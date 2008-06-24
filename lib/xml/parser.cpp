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
#include <iostream>
using namespace std;

namespace xmlpp {

XMLParser::XMLParser()
{
}

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
        plainText.resize(plainText.length()-2);
    }
    else {
        throw XMLException(EX_PARSER_FILE_READ_ERROR);
    }

    return plainText;
}

DOM* XMLParser::parseFromFile (std::string xmlFile)
{
    this->plainText   = this->fetch(xmlFile);
    this->documentObj = this->parseFromString(this->plain());

    return this->documentObj;
}

DOM* XMLParser::parseFromFile (const char* xmlFile)
{
    this->plainText   = this->fetch((std::string) xmlFile);
    this->documentObj = this->parseFromString(this->plain());

    return this->documentObj;
}

DOM* XMLParser::parseFromString (std::string xmlText)
{
    return this->parseDocument(xmlText);
}

DOM* XMLParser::parseFromString (const char* xmlText)
{
    return this->parseDocument((std::string) xmlText);
}

DOM* XMLParser::document (void)
{
    return this->documentObj;
}

std::string XMLParser::plain (void)
{
    return this->plainText;
}

DOM* XMLParser::parseDocument (std::string xml)
{
    DOM *document = new DOM();

    for (size_t i = 0; i < xml.length(); i++) {
        if (xml[i] == '<') {
            std::string node = "<";
            
            while (xml[i] != '>') {
                i++;
                node += xml[i];
            }
            i++;

            node = this->cleanElement(node);

            if (node[node.length()-2] == '/') {
                document->appendChild(this->parseElement(node));
            }
            else {
                FetchedNode *fNode = this->fetchNode((i-node.length()), node+xml.substr(i));;
                i = (*fNode).point-1;
                document->appendChild(this->parseNode((*fNode).text));

                delete fNode;
            }
        }
    }

    return document;
}

DOMChildNode* XMLParser::parseNode (std::string xml)
{
    
}

FetchedNode* XMLParser::fetchNode (size_t start, std::string xml)
{
    FetchedNode *fNode = new FetchedNode;

    size_t i = 0;
    std::string nodeText = "<";
    while (xml[i] != '>') {
        i++;
        nodeText += xml[i];
    }
    DOMElement *node = this->cleanElement(nodeText);

    std::string nodeName = node->nodeName();
    
    std::stack<int> tags;

    size_t h  = 0;
    while (true) {
        if (xml[i] == '<') {
            std::string nodeText = "<";
            while (xml[i] != '>') {
                i++;
                nodeText += xml[i];
            }
            i++;

            if (this->closingTag(node)) {
                if ()
            }
            else {
                DOMElement *node = this->cleanElement(nodeText);
            }
        }

        i++;
    }

    (*fNode).point = xml.length() + start;
    (*fNode).text  = xml;

    return fNode;
}

DOMElement* XMLParser::parseElement (std::string xml)
{
    DOMElement *element;

    // Get the element name
    std::string name;
    size_t i = 1;
    while (xml[i] != ' ') {
        name += xml[i];
        i++;
    }
    element = new DOMElement(name);

    // Get the attributes
    size_t h;
    for (h = i; h < xml.length(); h++) {
        if (xml[h] != ' ' && xml[h] != '/' && xml[h] != '>') {
            // Get attribute's name
            std::string attributeName;
            while (xml[h] != '=') {
                attributeName += xml[h];
                h++;
            }
            h += 2;

            // Get attribute's value.
            std::string attributeValue;
            char stringType = xml[h-1];
            while (xml[h] != stringType && xml[h-1] != '\\') {
                attributeValue += xml[h];
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
        if (element[i] == '"' && element[i-1] != '\\') {
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
        else if (element[i] == '\'' && element[i-1] != '\\') {
            if (inString && stringType == '\'') {
                inString   = false;
                stringType = 'x';
                firstSpace = true;
            }
            else if (!inString) {
                inString   = true;
                stringType = '\'';
            }

            clean += element[i];
        }
        else if (inString) {
            clean += element[i];
        }
        else if (   element[i] == ' '
                 || element[i] == '\t'
                 || element[i] == '\r'
                 || element[i] == '\n') {
            if (firstSpace) {
                clean += ' ';
                firstSpace = false;
            }
        }
        else if (element[i] == '/') {
            clean += "/>";
            break;
        }
        else {
            clean += element[i];
        }
    }
    
    return clean;
}

std::string closingTag (std::string tag)
{
    std::string element;
    std::string tagName;

    size_t word = 0;
    size_t i = 0;
    while (i < tag.length() && word < 2) {
        if (tag[i] != ' ' && tag[i] != '\t' && tag[i] != '\r' && tag[i] != '\n') {
            element += tag[i];

            if (i > 1) {
                tagName += tag[i]
            }
        }
        else {
            word++;
        }

        i++;
    }

    if (element[1] == '/') {
        
    }
    else {
        return false;
    }
}

};

