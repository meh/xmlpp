/// @file dom/DOMNamedNodeMap.cpp

/****************************************************************************
* XML++ is a library for working with XML files.                            *
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

#include "DOMNamedNodeMap.h"

DOMNamedNodeMap::DOMNamedNodeMap (DOMNodeType type)
{
    _ownerType = type;
}

DOMNode*
DOMNamedNodeMap::getNamedItem (DOMString name)
{
    return _items[name];
}

/// @todo  Add the INUSE_ATTRIBUTE_ERR exception.
DOMNode*
DOMNamedNodeMap::setNamedItem (DOMNode* node) throw (DOMException)
{
    if (this->ownerDocument() != node->ownerDocument()) {
        throw DOMException (WRONG_DOCUMENT_ERR);
    }

    // Check if the node passed can be added to the actual map.
    switch (_ownerType) {
        case DOMNode::ELEMENT_NODE:
        if (node->nodeType() != DOMNode::ATTRIBUTE_NODE) {
            throw DOMException(HIERARCHY_REQUEST_ERR);
        }
        break;

        case DOMNode::DOCUMENT_TYPE_NODE:
        if (node->nodeType() != DOMNode::ENTITY_NODE) {
            throw DOMException(HIERARCHY_REQUEST_ERR);
        }
        break;
    }

    DOMNode* replaced = NULL;
    if (_items.find(node->nodeName()) != _items.end()) {
        replaced = _items[node->nodeName()];
    }

    _items[node->nodeName()] = node;

    return replaced;
}


DOMNode*
DOMNamedNodeMap::removeNamedItem (DOMString name)
{
    if (_items.find(name) != _items.end()) {
        DOMNode *removed = _items[name];
        _items.erase(name);
        return removed;
    }
    else {
        throw DOMException(NOT_FOUND_ERR);
    }
}

DOMNode*
DOMNamedNodeMap::item (unsigned long index)
{
    if (index > this->length()) {
        return NULL;
    }

    std::map<DOMString, DOMNode*>::iterator item;
    size_t i;
    for (item = _items.begin(), i = 0; item != _items.end(); item++, i++) {
        if (index == i) {
            return *item;
        }
    }
}

unsigned long
DOMNamedNodeMap::length (void)
{
    return (unsigned long) _items.size();
}

/// @todo  Not implemented yet.
DOMNode*
DOMNamedNodeMap::getNamedItemNS (DOMString namespaceURI, DOMString localName) throw (DOMException)
{
    return NULL;
}

/// @todo  Not implemented yet.
DOMNode*
DOMNamedNodeMap::setNamedItemNS (DOMString namespaceURI, DOMString localName) throw (DOMException)
{
    return NULL;
}

/// @todo  Not implemented yet.
DOMNode*
DOMNamedNodeMap::removeNamedItemNS (DOMString namespaceURI, DOMString localName) throw (DOMException)
{
    return NULL;
}

