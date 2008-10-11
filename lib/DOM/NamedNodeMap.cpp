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

#include "Node.h"

namespace xmlpp {

namespace DOM {

Node::NamedNodeMap::NamedNodeMap (void)
{
    _ownerNode = NULL;
}

Node::NamedNodeMap::NamedNodeMap (Node* ownerNode)
{
    _ownerNode = ownerNode;
}

Node*
Node::NamedNodeMap::getNamedItem (const DOMString& name)
{
    if (_items.find(name) != _items.end()) {
        return _items[name];
    }
    else {
        return NULL;
    }
}

Node*
Node::NamedNodeMap::setNamedItem (Node* node) throw ()
{
    if (_ownerNode->ownerDocument() != node->ownerDocument()) {
        throw DOMException(DOMException::WRONG_DOCUMENT_ERR);
    }

    // Check if the node passed can be added to the actual map.
    switch (_ownerNode->nodeType()) {
        case Node::ELEMENT_NODE:
        if (node->nodeType() != Node::ATTRIBUTE_NODE) {
            throw DOMException(DOMException::HIERARCHY_REQUEST_ERR);
        }
        break;

        case Node::DOCUMENT_TYPE_NODE:
        if (node->nodeType() != Node::ENTITY_NODE) {
            throw DOMException(DOMException::HIERARCHY_REQUEST_ERR);
        }
        break;
    }

    Node* replaced = NULL;
    if (_items.find(node->nodeName()) != _items.end()) {
        replaced = _items[node->nodeName()];
    }

    _items[node->nodeName()] = node;

    return replaced;
}


Node*
Node::NamedNodeMap::removeNamedItem (const DOMString& name) throw()
{
    if (_items.find(name) != _items.end()) {
        Node *removed = _items[name];
        _items.erase(name);
        return removed;
    }
        
    throw DOMException(DOMException::NOT_FOUND_ERR);
}

Node*
Node::NamedNodeMap::item (unsigned long index)
{
    if (index > this->length()) {
        return NULL;
    }

    std::map<DOMString, Node*>::iterator item;
    size_t i;
    for (item = _items.begin(), i = 0; item != _items.end(); item++, i++) {
        if (index == i) {
            return item->second;
        }
    }
}

Node*
Node::NamedNodeMap::remove (unsigned long index)
{
    if (index > this->length()) {
        return NULL;
    }

    return this->removeNamedItem(this->item(index)->nodeName());
}

unsigned long
Node::NamedNodeMap::length (void)
{
    return (unsigned long) _items.size();
}

/// @todo  Not implemented yet.
Node*
Node::NamedNodeMap::getNamedItemNS (const DOMString& namespaceURI, const DOMString& localName) throw ()
{
    return NULL;
}

/// @todo  Not implemented yet.
Node*
Node::NamedNodeMap::setNamedItemNS (Node* arg) throw ()
{
    return NULL;
}

/// @todo  Not implemented yet.
Node*
Node::NamedNodeMap::removeNamedItemNS (const DOMString& namespaceURI, const DOMString& localName) throw ()
{
    return NULL;
}

};

};

