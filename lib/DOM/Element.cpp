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

Element::Element (Node* ownerDocument, const DOMString& tagName) : Node (ownerDocument, Node::ELEMENT_NODE)
{
    _tagName = tagName;
    _attributes._ownerNode = this;
}

Element::~Element (void)
{
    for (unsigned long i = 0; i < _attributes.length(); i++) {
        delete _attributes.remove(i);
    }

    for (unsigned long i = 0; i < _children.length(); i++) {
        delete _children.remove(i);
    }
}

DOMString
Element::tagName (void)
{
    return Utils::toUpper(_tagName);
}

DOMString
Element::getAttribute (const DOMString& name)
{
    Attr* attr = (Attr*) _attributes.getNamedItem(name);

    if (attr == NULL) {
        return "";
    }
    else {
        return attr->value();
    }
}

void
Element::setAttribute (const DOMString& name, const DOMString& value) throw()
{
    Attr* attr = (Attr*) _attributes.getNamedItem(name);

    if (attr == NULL) {
        attr = new Attr(this->ownerDocument(), name);
        this->setAttributeNode(attr);
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
    return (Attr*) _attributes.getNamedItem (name);
}

Attr*
Element::setAttributeNode (Attr* newAttr) throw()
{
    if (newAttr->ownerDocument() != this->ownerDocument()) {
        throw DOMException(DOMException::WRONG_DOCUMENT_ERR);
    }

    return (Attr*) _attributes.setNamedItem(newAttr);
}

NodeList
Element::getElementsByTagName (const DOMString& name)
{
    NodeList elements;
    
    for (size_t i = 0; i < _children.length(); i++) {
        Node* node = _children.item(i);

        if (node->nodeType() == Node::ELEMENT_NODE) {
            if (((Element*)node)->tagName() == Utils::toUpper(name)) {
                elements.insert(node);
            }
        }
    }

    for (size_t i = 0; i < _children.length(); i++) {
        Node* node = _children.item(i);

        if (node->nodeType() == Node::ELEMENT_NODE) {
            NodeList subElements = ((Element*)node)->getElementsByTagName(name);

            for (size_t h = 0; h < subElements.length(); h++) {
                elements.insert(subElements.item(h));
            }
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
    Attr* attr = (Attr*) _attributes.getNamedItem(name);

    if (attr == NULL) {
        throw DOMException(DOMException::NOT_FOUND_ERR);
    }

    attr->_isId = isId;
}

void
Element::setIdAttributeNode (Attr* idAttr, bool isId) throw()
{
    Attr* attr = (Attr*) _attributes.getNamedItem(idAttr->nodeName());

    if (attr == NULL) {
        throw DOMException(DOMException::NOT_FOUND_ERR);
    }

    attr->_isId = isId;
}

// Parent realization.
DOMString
Element::nodeName (void)
{
    return _tagName;
}

DOMString
Element::nodeValue (void) throw()
{
    return "";
}

void
Element::nodeValue (const DOMString& value) throw()
{
}

NodeList
Element::childNodes (void)
{
    return _children;
}

Node*
Element::firstChild (void)
{
    if (_children.length() == 0) {
        return NULL;
    }

    return _children.item(0);
}

Node*
Element::lastChild (void)
{
    if (_children.length() == 0) {
        return NULL;
    }

    return _children.item(_children.length()-1);
}

NamedNodeMap
Element::attributes (void)
{
    return _attributes;
}

Node*
Element::insertBefore (Node* newChild, Node* refChild) throw()
{
    NodeType type = newChild->nodeType();
    if (       type == Node::DOCUMENT_NODE
            || type == Node::ATTRIBUTE_NODE
            || type == Node::DOCUMENT_TYPE_NODE
            || type == Node::NOTATION_NODE
            || type == Node::ENTITY_REFERENCE_NODE) {
        throw DOMException(DOMException::NOT_SUPPORTED_ERR);
    }

    if (newChild->ownerDocument() != this->ownerDocument()) {
        throw DOMException(DOMException::WRONG_DOCUMENT_ERR);
    }

    for (unsigned long i = 0; i < _children.length(); i++) {
        if (_children.item(i) == refChild) {
            Node* pSibling = (i > 0) ? _children.item(i-1) : NULL;
            Node* nSibling = refChild;

            if (pSibling == NULL) {
                nSibling->_pSibling = newChild;
                newChild->_nSibling = nSibling;
            }
            else {
                pSibling->_nSibling = newChild;
                newChild->_pSibling = pSibling;
                newChild->_nSibling = nSibling;
                nSibling->_pSibling = newChild;
            }
       
            newChild->_parent = this;
            _children.insert(newChild, i);
            return newChild;
        }
    }

    throw DOMException(DOMException::NOT_FOUND_ERR);
}

Node*
Element::replaceChild (Node* newChild, Node* oldChild) throw()
{
    NodeType type = newChild->nodeType();
    if (       type == Node::DOCUMENT_NODE
            || type == Node::ATTRIBUTE_NODE
            || type == Node::DOCUMENT_TYPE_NODE
            || type == Node::NOTATION_NODE
            || type == Node::ENTITY_REFERENCE_NODE) {
        throw DOMException(DOMException::NOT_SUPPORTED_ERR);
    }

    if (newChild->ownerDocument() != this->ownerDocument()) {
        throw DOMException(DOMException::WRONG_DOCUMENT_ERR);
    }

    for (unsigned long i = 0; i < _children.length(); i++) {
        if (_children.item(i) == oldChild) {
            newChild->_pSibling = oldChild->_pSibling;
            newChild->_nSibling = oldChild->_nSibling;
            newChild->_parent   = this;

            return _children.replace(newChild, i);
        }
    }

    throw DOMException(DOMException::NOT_FOUND_ERR);
   
}

Node*
Element::removeChild (Node* oldChild) throw()
{
     for (unsigned long i = 0; i < _children.length(); i++) {
        if (_children.item(i) == oldChild) {
            Node* pSibling = (i > 0) ? _children.item(i-1) : NULL;
            Node* nSibling = _children.item(i+1);

            if (pSibling == NULL && nSibling == NULL) {
                23; // This will kill you in 23 days after you read it.
            }
            else if (pSibling == NULL) {
                nSibling->_pSibling = NULL;
            }
            else if (nSibling == NULL) {
                pSibling->_nSibling = NULL;
            }
            else {
                pSibling->_nSibling = nSibling;
                nSibling->_pSibling = pSibling;
            }
            
            oldChild->_parent = NULL;
            return _children.remove(i);
        }
    }

    throw DOMException(DOMException::NOT_FOUND_ERR);   
}

Node*
Element::appendChild (Node* newChild) throw()
{
    NodeType type = newChild->nodeType();
    if (       type == Node::DOCUMENT_NODE
            || type == Node::ATTRIBUTE_NODE
            || type == Node::DOCUMENT_TYPE_NODE
            || type == Node::NOTATION_NODE
            || type == Node::ENTITY_REFERENCE_NODE) {
        throw DOMException(DOMException::NOT_SUPPORTED_ERR);
    }

    if (newChild->ownerDocument() != this->ownerDocument()) {
        throw DOMException(DOMException::WRONG_DOCUMENT_ERR);
    }

    if (_children.length() > 0) {
        Node* pSibling      = _children.item(_children.length()-1);
        pSibling->_nSibling = newChild;

        newChild->_pSibling = pSibling;
    }
    newChild->_parent = this;

    _children.insert(newChild);
}

bool
Element::hasChildNodes (void)
{
    if (_children.empty()) {
        return false;
    }

    return true;
}

Node*
Element::cloneNode (bool deep)
{
    Element* element     = new Element(this->ownerDocument(), this->nodeName());
    element->_attributes = _attributes;

    if (deep) {
        for (unsigned long i = 0; i < _children.length(); i++) {
            element->appendChild(_children.item(i)->cloneNode(true));
        }
    }

    return element;
}

Node*
Element::_getElementById (const DOMString& id)
{
    for (size_t i = 0; i < _children.length(); i++) {
        NamedNodeMap attrs = _children.item(i)->attributes();

        for (size_t h = 0; h < attrs.length(); h++) {
            Attr* attr = (Attr*) attrs.item(h);

            if (attr->_isId) {
                if (attr->value() == id) {
                    return _children.item(i);
                }
            }
        }
    }

    for (size_t i = 0; i < _children.length(); i++) {
        Node* element = _children.item(i)->_getElementById(id);

        if (element) {
            return element;
        }
    }

    return NULL;
}

void
Element::_normalize (void)
{
    for (size_t i = 0; i < _attributes.length(); i++) {
        _attributes.item(i)->_normalize();
    }

    for (size_t i = 0; i < _children.length(); i++) {
        _children.item(i)->_normalize();
    }
}

};

};

