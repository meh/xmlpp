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

DOM::Document*
Parser::_parseDocument (const std::string& text)
{
    _document = new DOM::Document;

    if (text.substr(0, 2) == "<?") {
        std::string verNode;
        size_t i = 0;
        while (i < text.length() && text.at(i) != '>') {
            verNode += text.at(i);
            i++;
        }
        verNode += ">";
        i++;

        // Well, i forgot the things for the XML version >_>
        // @todo Add them.
    }

    _document.appendChild(_parseRoot(text.substr(i)));

    return _document;
}

DOM::Element*
Parser::_parseRoot (const std::string& text)
{
    if (text.substr(0, 4) == "<!--" || text.substr(0, 9) == "<![CDATA[") {
        throw XMLException(XMLException::WRONG_ROOT_NODE);
    }

    DOM::Element* root;

    for (size_t i = 0; i < text.length(); i++) {
        Node node = _fetchNode(text, 0);
    }

    return root;
}

DOM::Element*
Parser::_parseElement (const std::string& text)
{
    for (size_t i = 0; i < text.length(); i++) {

    }
}

Node*
Parser::_fetchNode (const std::string& text, size_t start)
{
    Node* fNode;
    
    Node* recon = _recognizeNode(text);
    switch (recon.type) {
        case DOM::Node::ELEMENT_NODE:
        fNode = _fetchElement(text, start);
        break;

        case DOM::Node::CDATA_SECTION_NODE:
        fNode = _fetchCDATASection(text, start);
        break;

        case DOM::Node::COMMENT_NODE:
        fNode = _fetchComment(text, start);
        break;
    }
    delete recon;

    return fNode;
}

Node*
Parser::_fetchElement (const std::string& text, size_t start)
{
    Node* fNode = new Node;

    Node* element = _fetchElementTag(text, 0);
    DOMElement* node = _parseElement(element.text);
    if (node == NULL) {
        throw XMLException(XMLException::BAD_NODE);
    }
    std::string nodeName = node->nodeName();
    delete node;
    
    std::stack<char> tags;
    tags.push(0);

    size_t i = element.offset;
    while (i < text.length() && !tags.empty()) {
        if (text.at(i) == '<') {
            Node* recon = _recognizeNode(text.substr(i), 0);
            if (recon.type == DOM::Node::ELEMENT_NODE) {
                std::string closed = this->_closingTag(recon.text);

                if (!closed.empty()) {
                    if (closed == nodeName) {
                        tags.pop();
                    }
                }
                else {
                    DOM::Element* node = _parseElement(recon.text);
                    if (node->nodeName() == nodeName) {
                        tags.push(0);
                    }
                    delete node;
                }
            }
            i += recon.offset;
            delete recon;
        }

        i++;
    }
    delete element;

    if (!tags.empty()) {
        throw XMLException(XMLException::TAG_NOT_CLOSED);
    }

    fNode.type   = DOM::Node::ELEMENT_NODE;
    fNode.offset = i + start;
    fNode.text   = text.substr(0, i-1);

    return fNode;
}


};

