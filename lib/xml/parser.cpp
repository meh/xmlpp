/// @file   xml/parser.cpp
/// @brief  This file includes the XML parser implementations.

/****************************************************************************
* XML++ is a library to work with XML files.                                *
* Copyright (C) 2008  cHoBi                                                 *
*                                                                           *
* This file is part of XML++                                                *
*                                                                           *
* XML++ is free software: you can redistribute it and/or modify             *
* it under the terms of the GNU Affero General Public License as            *
* published by the Free Software Foundation, either version 3 of the        *
* License, or (at your option) any later version.                           *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU Affero General Public License for more details.                       *
*                                                                           *
* You should have received a copy of the GNU Affero General Public License  *
* along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
****************************************************************************/

#include "parser.h"

namespace xmlpp {

XMLParser::XMLParser (std::string xmlFile)
{
    this->documentObj = this->parseFromFile(xmlFile);
}

XMLParser::XMLParser (const char* xmlFile)
{
    this->documentObj = this->parseFromFile(xmlFile);
}

std::string XMLParser::fetch (std::string xmlString)
{
    std::string plainText;
    std::string line;

    std::ifstream xmlFile(xmlString.c_str());

    if (xmlFile.is_open()) {
        while (!xmlFile.eof()) {
            getline(xmlFile, line);
            plainText += line + "\n";
        }
        // Remove the last \n
        plainText.resize(plainText.length()-2);
    }
    else {
        throw XMLException(EX_PARSER_FILE_READ_ERROR);
    }

    return plainText;
}

DOMDocument* XMLParser::parseFromFile (std::string xmlFile)
{
    this->plainText   = this->fetch(xmlFile);
    this->documentObj = this->parseFromString(this->plain());

    return this->documentObj;
}

DOMDocument* XMLParser::parseFromFile (const char* xmlFile)
{
    this->plainText   = this->fetch((std::string) xmlFile);
    this->documentObj = this->parseFromString(this->plain());

    return this->documentObj;
}

DOMDocument* XMLParser::parseFromString (std::string xmlText)
{
    return this->parseDocument(xmlText);
}

DOMDocument* XMLParser::parseFromString (const char* xmlText)
{
    return this->parseDocument((std::string) xmlText);
}

DOMDocument* XMLParser::document (void)
{
    return this->documentObj;
}

std::string XMLParser::plain (void)
{
    return this->plainText;
}

DOMDocument* XMLParser::parseDocument (std::string xml)
{
    DOMDocument *document = new DOMDocument();

    for (size_t i = 0; i < xml.length(); i++) {
        // It has only to get elements because the document can't have
        // text child nodes.
        if (xml.at(i) == '<') {
            std::string nodeText;
            while (i < xml.length() && xml.at(i) != '>') {
                nodeText += xml.at(i);
                i++;
            }
            nodeText += ">";
            i++;

            nodeText = this->cleanElement(nodeText);

            if (nodeText.length() > 4 && nodeText.at(1) == '?' && nodeText.at(nodeText.length()-2) == '?') {
                document->setVersion(this->getVersion(nodeText));
            }
            else if (nodeText.length() > 3 && nodeText[nodeText.length()-2] == '/') {
                document->appendChild(this->parseElement(nodeText));
            }
            else {
                FetchedNode *fNode = this->fetchNode((i-nodeText.length()), nodeText+xml.substr(i));
                i = fNode->point-1;
                document->appendChild(this->parseNode((*fNode).text));

                delete fNode;
            }
        }
    }

    return document;
}

DOMNode* XMLParser::parseNode (std::string xml)
{
    size_t i = 0;
    std::string nodeText;
    while (i < xml.length() && xml.at(i) != '>') {
        nodeText += xml.at(i);
        i++;
    }
    nodeText += ">";
    DOMElement *mainNode = this->parseElement(nodeText);

    // Removing the closing tag of the main node.
    xml = xml.substr(i+1);
    xml.resize(xml.find_last_of('<'));

    size_t h;
    for (h = 0; h < xml.length(); h++) {
        // If it's an element node
        if (xml.at(h) == '<') {
            std::string nodeText;
            while (h < xml.length() && xml.at(h) != '>') {
                nodeText += xml.at(h);
                h++;
            }
            nodeText += ">";
            h++;

            nodeText = this->cleanElement(nodeText);

            if (nodeText.length() > 3 && nodeText.at(nodeText.length()-2) == '/') {
                mainNode->appendChild(this->parseElement(nodeText));
            }
            else {
                FetchedNode *fNode = this->fetchNode((h-nodeText.length()), nodeText+xml.substr(h));
                h = fNode->point-1;
                mainNode->appendChild(this->parseNode(fNode->text));

                delete fNode;
            }
        }
        // If it's a text node
        else {
            std::string text;
            
            while (h < xml.length() && xml.at(h) != '<') {
                text += xml.at(h);
                h++;
            }
            h--;

            DOMNode *textNode = this->parseText(text);
            if (!textNode->nodeValue().empty()) {
                mainNode->appendChild(textNode);
            }
        }
    }

    return mainNode;
}

FetchedNode* XMLParser::fetchNode (size_t start, std::string xml)
{
    FetchedNode *fNode = new FetchedNode;

    size_t i = 0;
    std::string nodeText;
    while (i < xml.length() && xml.at(i) != '>') {
        nodeText += xml.at(i);
        i++;
    }
    nodeText += ">";

    DOMElement *node = this->parseElement(nodeText);

    if (node == NULL) {
        throw XMLException(EX_XML_BAD_NODE);
    }

    std::string nodeName = node->nodeName();
    free(node);
    
    std::stack<int> tags;
    tags.push(1);

    while (i < xml.length() && !tags.empty()) {
        if (xml.at(i) == '<') {
            std::string nodeText;
            while (i < xml.length() && xml.at(i) != '>') {
                nodeText += xml.at(i);
                i++;
            }
            nodeText += ">";
            i++;

            std::string closed = this->closingTag(nodeText);

            if (!closed.empty()) {
                if (closed == nodeName) {
                    tags.pop();
                }
            }
            else {
                DOMElement *node = this->parseElement(nodeText);
                if (node->nodeName() == nodeName) {
                    tags.push(1);
                }
                free(node);
            }
        }

        i++;
    }

    if (!tags.empty()) {
        throw XMLException(EX_XML_TAG_NOT_CLOSED);
    }

    fNode->point = i + start;
    fNode->text  = xml.substr(0, i-1);

    return fNode;
}

DOMElement* XMLParser::parseElement (std::string xml)
{
    DOMElement *element;

    xml = this->cleanElement(xml);

    // Get the element name
    std::string name;
    size_t i = 1;
    while (i < xml.length() && xml.at(i) != ' ' && xml.at(i) != '>') {
        name += xml.at(i);
        i++;
    }
    element = new DOMElement(name);

    // Get the attributes
    size_t h;
    for (h = i; h < xml.length(); h++) {
        if (xml.at(h) != ' ' && xml.at(h) != '/' && xml.at(h) != '>') {
            // Get attribute's name
            std::string attributeName;
            while (xml.at(h) != '=') {
                attributeName += xml.at(h);
                h++;
            }
            h += 2;

            // Get attribute's value.
            std::string attributeValue;
            char stringType = xml[h-1];
            while (xml.at(h) != stringType && xml.at(h-1) != '\\') {
                attributeValue += xml.at(h);
                h++;
            }

            element->setAttribute(attributeName, attributeValue);
        }
    }

    return element;
}

std::string XMLParser::cleanElement (std::string element)
{
    std::string clean;

    bool inString   = false;
    char stringType = 'x';

    bool firstSpace = true;
    for (size_t i = 0; i < element.length(); i++) {
        if (element.at(i) == '"' && element.at(i-1) != '\\') {
            if (inString && stringType == '"') {
                inString   = false;
                stringType = 'x';
                firstSpace = true;
            }
            else if (!inString){
                inString   = true;
                stringType = '"';
            }

            clean += element[i];
        }
        else if (element.at(i) == '\'' && element.at(i-1) != '\\') {
            if (inString && stringType == '\'') {
                inString   = false;
                stringType = 'x';
                firstSpace = true;
            }
            else if (!inString) {
                inString   = true;
                stringType = '\'';
            }

            clean += element.at(i);
        }
        else if (inString) {
            clean += element.at(i);
        }
        else if (utils::isSpace(element.at(i))) {
            if (firstSpace) {
                clean += ' ';
                firstSpace = false;
            }
        }
        else if (element.at(i) == '/') {
            clean += "/>";
            break;
        }
        else {
            clean += element[i];
        }
    }
    
    return clean;
}

DOMText* XMLParser::parseText (std::string text)
{
    std::string filteredText;
    bool        firstSpace = true;

    size_t i;
    for (i = 0; i < text.length(); i++) {
        if (utils::isSpace(text.at(i))) {
            if (firstSpace) {
                filteredText += " ";
                firstSpace    = false;
            }
        }
        else if (text.at(i) == '&') {
            std::string unescaped = utils::unescapeChar(text.substr(i));

            if (!unescaped.empty()) {
                filteredText += unescaped;

                while (i < text.length() && text.at(i) != ';') {
                    i++;
                }
            }

            firstSpace = true;
        }
        else {
            filteredText += text.at(i);
            
            if (!firstSpace) {
                firstSpace = true;
            }
        }
    }

    if (filteredText.length() == 1 && filteredText.at(0) == ' ') {
        filteredText = "";
    }

    return new DOMText(filteredText);
}

std::string XMLParser::closingTag (std::string tag)
{
    std::string element;
    std::string tagName;

    size_t  word  = 0;
    size_t  i     = 0;
    bool    space = false;
    while (i < tag.length() && word < 2) {
        if (!utils::isSpace((const char) tag[i])) {
            element += tag.at(i);

            if (i > 1 && tag.at(i) != '>') {
                tagName += tag.at(i);
            }

            if (space) {
                space = false;
                word++;
            }
        }
        else {
            word++;
            space = true;
        }

        i++;
    }

    if (element.at(1) == '/' && word < 2 && !tagName.empty()) {
        return tagName;
    }
    else {
        return (std::string) "";
    }
}

std::string XMLParser::getVersion (std::string xml)
{
/*    DOMElement *element = this->parseElement(xml);
    std::string version = element->getAttribute("version");
    delete element;*/

    std::string version = "";

    return version;
}

};

