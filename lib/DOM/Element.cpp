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

#include "Element.h"

namespace xmlpp {

namespace DOM {

Element::Element (Document* ownerDocument, const DOMString& tagName) : Node (ownerDocument, Node::ELEMENT_NODE)
{
    _tagName = tagName;
}

DOMString
Element::tagName (void)
{
    return Utils::toUpper(_tagName);
}

DOMString
Element::getAttribute (const DOMString& name)
{
    Node* attr = _attributes.getNamedItem(name);

    if (attr == NULL) {
        return "";
    }
    else {
        return attr->nodeValue();
    }
}

void
Element::setAttribute (const DOMString& name, const DOMString& value) throw()
{
    Node* attr = _attributes.getNamedItem(name);

    if (attr == NULL) {
        attr = new Attribute(this->ownerDocument(), name);
    }

    attr->value(value);
    attr->_ownerElement = this;
}

void
Element::removeAttribute (const DOMString& name) throw()
{
    Node* attr = _attributes.getNamedItem (name);

    if (attr != NULL) {
        delete _attributes.removeNamedItem(name);
    }
}

Attr*
Element::getAttributeNode (const DOMString& name)
{
    return _attributes.getNamedItem (name);
}

Attr*
Element::setAttributeNode (Attr* newAttr) throw()
{
    if (newAttr->ownerDocument() != this->ownerDocument()) {
        throw DOMException(DOMException::WRONG_DOCUMENT_ERR);
    }

    return _attributes.setNamedItem(newAttr);
}

NodeList
Element::getElementsByTagName (const DOMString& name)
{
    NodeList elements;
    
    for (size_t i = 0; i < _children.length(); i++) {
        Node* node = _children.item(i)->tagName();

        if (node->nodeType() == Node::ELEMENT_NODE) {
            if (node->tagName() == Utils::toUpper(name)) {
                elements.insert(node);
            }
        }
    }

    for (size_t i = 0; i < _children.length(); i++) {
        NodeList subElements = _children.item(i)->getElementsByTagName(name);

        for (size_t h = 0; h < subElements.length(); h++) {
            elements.insert(subElements.item(h));
        }
    }

    return elements;
}

bool
Element::hasAttribute (const DOMString& name)
{
    if (_attributes.getNamedItem(name) == NULL) {
        return false;
    }

    return true;
}

void
Element::setIdAttribute (const DOMString& name, bool isId) throw()
{
    Attr* attr = _attributes.getNamedItem(name);

    if (attr == NULL) {
        throw DOMException(DOMException::NOT_FOUND_ERR);
    }

    attr->_isId = isId;
}

void
Element::setIdAttributeNode (Attr* idAttr, bool isId) throw()
{
    Attr* attr = _attributes.getNamedItem(idAttr->nodeName());

    if (attr == NULL) {
        throw DOMException(DOMException::NOT_FOUND_ERR);
    }

    attr->_isId = isId;
}

};

};

