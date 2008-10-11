/****************************************************************************
* XML++ is a library for working with XML files.                            *
* Copyleft meh.                                                             *
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

#include "Parser.h"

namespace xmlpp {

namespace XML {

Parser::Parser (void) : xmlpp::Parser()
{
}

DOM::Document*
Parser::Load (const std::string& text)
{
    return _parseDocument(text);
};

std::string
Parser::Save (DOM::Document* document)
{
    return "";
}

DOM::Document*
Parser::_parseDocument (const std::string& text)
{
    _document = new DOM::Document;

    size_t i = 0;
    if (text.substr(0, 2) == "<?") {
        std::string verNode;
        while (i < text.length() && text.at(i) != '>') {
            verNode += text.at(i);
            i++;
        }
        verNode += ">";
        i++;

        // Well, i forgot the things for the XML version >_>
        // @todo Add them.
    }

    _document->appendChild(_parseRoot(text.substr(i)));

    return _document;
}

DOM::Element*
Parser::_parseRoot (const std::string& text)
{
    if (text.substr(0, 4) == "<!--" || text.substr(0, 9) == "<![CDATA[") {
        throw XMLException(XMLException::WRONG_ROOT_NODE);
    }

    return (DOM::Element*) _parseNode(_fetchNode(text)->text);
}

Parser::Node*
Parser::_fetchNode (const std::string& text)
{
    Parser::Node* fNode;
    
    Parser::Node* recon = _recognizeNode(text);
    switch (recon->type) {
        case DOM::Node::ELEMENT_NODE:
        fNode = _fetchElement(text);
        delete recon;
        break;

        case DOM::Node::CDATA_SECTION_NODE:
        fNode = recon;
        break;

        case DOM::Node::COMMENT_NODE:
        fNode = recon;
        break;
    }

    return fNode;
}

DOM::Node*
Parser::_parseNode (const std::string& text)
{
    DOM::Node* node;

    Parser::Node* recon = _recognizeNode(text);
    switch (recon->type) {
        case DOM::Node::ELEMENT_NODE:
        node = _parseElement(text);
        break;

        case DOM::Node::CDATA_SECTION_NODE:
        node = _document->createCDATASection(recon->text);
        break;

        case DOM::Node::COMMENT_NODE:
        node = _document->createComment(recon->text);
        break;
    }
    delete recon;

    return node;
}

Parser::Node*
Parser::_fetchElement (const std::string& text)
{
    Parser::Node* fNode = new Node;

    Parser::Node* element = _recognizeNode(text);
    DOM::Element* node = _parseElement(element->text);
    if (node == NULL) {
        throw XMLException(XMLException::BAD_NODE);
    }
    std::string nodeName = node->nodeName();
    delete node;
    
    std::stack<char> tags;
    tags.push(0);

    size_t i = element->offset;
    while (i < text.length() && !tags.empty()) {
        if (text.at(i) == '<') {
            Parser::Node* recon = _recognizeNode(text.substr(i));
            if (recon->type == DOM::Node::ELEMENT_NODE) {
                std::string closed = this->_closingTag(recon->text);

                if (!closed.empty()) {
                    if (closed == nodeName) {
                        tags.pop();
                    }
                }
                else {
                    DOM::Element* node = _parseElement(recon->text);
                    if (node->nodeName() == nodeName) {
                        tags.push(0);
                    }
                    delete node;
                }
            }
            i += recon->offset;
            delete recon;
        }

        i++;
    }
    delete element;

    if (!tags.empty()) {
        throw XMLException(XMLException::TAG_NOT_CLOSED);
    }

    fNode->type   = DOM::Node::ELEMENT_NODE;
    fNode->offset = i;
    fNode->text   = text.substr(0, i-1);

    return fNode;
}

std::string
Parser::_closingTag (const std::string& text)
{
    std::string element;
    std::string tagName;

    size_t word  = 0;
    size_t i     = 0;
    bool   space = false;
    while (i < text.length() && word < 2) {
        if (!Utils::isSpace(text.at(i))) {
            element += text.at(i);

            if (i > 1 && text.at(i) != '>') {
                tagName += text.at(i);
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
        return "";
    }
}

DOM::Element*
Parser::_parseElementTag (const std::string& text)
{
    DOM::Element* element;

    bool inString   = false;
    char stringType = '\0';
    bool firstSpace = true;

    std::string attrName;
    std::string attrValue;

    size_t i = 0;
    while (i < text.length() && text.at(i) != '<') {
        i++;
    }
    i++;

    while (i < text.length()) {
        if (Utils::isSpace(text.at(i)) && firstSpace) {
            while (Utils::isSpace(text.at(i))) {
                i++;
            }
        }
        else {
            std::string elementName;
            while (!Utils::isSpace(text.at(i))) {
                elementName += text.at(i);
                i++;
            }
            i++;
            element = _document->createElement(elementName);
            break;
        }
        i++;
    }

    while (i < text.length() && text.at(i) != '>') {
        if (!inString) {
            if (Utils::isSpace(text.at(i))) {
                if (firstSpace) {
                    firstSpace = false;
                }
            }
            else if (text.at(i) == '\'' || text.at(i) == '"') {
                firstSpace = true;
                inString   = true;
                stringType = text.at(i);
            }
            else {
                firstSpace = true;

                if (text.at(i) != '=') {
                    attrName += text.at(i);
                }
            }
        }
        else {
            if (text.substr(i, 2) == std::string("\\" + stringType)) {
                i++;
            }
            else if (text.at(i) == stringType) {
                inString = false;
                stringType = '\0';

                element->setAttribute(attrName, attrValue);
                attrName  = "";
                attrValue = "";
            }
            else {
                attrValue += text.at(i);
            }
        }
        i++;
    }

    return element;
}

DOM::Element*
Parser::_parseElement (const std::string& text)
{
    DOM::Element* mainNode = _parseElementTag(text);

    // Removing the closing tag of the main node.
    std::string innerNode = text.substr(_recognizeNode(text)->offset);
    innerNode.resize(innerNode.find_last_of('<'));

    for (size_t i = 0; i < innerNode.length(); i++) {
        if (innerNode.at(i) == '<') {
            Parser::Node* node = _fetchNode(innerNode.substr(i));
            mainNode->appendChild(_parseNode(node->text));

            i += node->offset;
        }
        else {
            std::string text;

            while (i < innerNode.length() && innerNode.at(i) != '<') {
                text += innerNode.at(i);
                i++;
            }
            i--;

            mainNode->appendChild(_document->createTextNode(text));
    }
}

    return mainNode;
}

Parser::Node*
Parser::_recognizeNode (const std::string& text)
{
    Parser::Node* recon = new Node;
    std::string nText;
    size_t i;

    if (text.substr(0, 4) == "<!--") {
        recon->type = DOM::Node::COMMENT_NODE;

        i = 4;
        while (i < text.length() && text.substr(i, 3) != "-->") {
            nText += text.at(i);
            i++;
        }
        i += 3;
    }
    else if (text.substr(0, 9) == "<![CDATA[") {
        recon->type = DOM::Node::CDATA_SECTION_NODE;

        i = 9;
        while (i < text.length() && text.substr(i, 3) != "]]>") {
            nText += text.at(i);
            i++;
        }
        i += 3;
    }
    else {
        recon->type = DOM::Node::ELEMENT_NODE;

        i = 0;
        while (i < text.length() && text.at(i) != '>') {
            nText += text.at(i);
            i++;
        }
        nText += ">";
        i++;
    }

    recon->offset = i;
    recon->text   = nText;

    return recon;
}

};

};

