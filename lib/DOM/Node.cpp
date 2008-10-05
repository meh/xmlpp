/// @file dom/node.cpp
/// @brief This file includes the DOM child definitions.

/****************************************************************************
* XML++ is a library for working with XML files.                                *
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

#include "DOMNode.h"

namespace xmlpp {

DOMString DOMNode::nodeName (void)
{
    return this->_name;
}

DOMString DOMNode::nodeValue (void) throw()
{
    return this->_value;
}

DOMNodeType DOMNode::nodeType (void)
{
    return this->_type;
}

DOMNamedNodeMap DOMNode::attributes (void)
{
    return this->_attributes;
}

DOMNode* DOMNode::parentNode (void)
{
    return this->_parent;
}

DOMNode* DOMNode::previousSibling (void)
{
    return this->_pSibling;
}

DOMNode* DOMNode::nextSibling (void)
{
    return this->_nSibling;
}

void DOMNode::__setParent (DOMNode* parent)
{
    this->_parent = parent;
}

void DOMNode::__setPreviousSibling (DOMNode* sibling)
{
    this->_pSibling = sibling;
}

void DOMNode::__setNextSibling (DOMNode* sibling)
{
    this->_nSibling = sibling;
}

double DOMNode::__getID (void)
{
    return this->_uniqueID;
}

bool DOMNode::operator == (DOMNode* element)
{
    if (this->_uniqueID == element->__getID()) {
        return true;
    }
    else {
        return false;
    }
}

bool DOMNode::operator != (DOMNode* element)
{
    if (this->_uniqueID != element->__getID()) {
        return true;
    }
    else {
        return false;
    }
}

bool DOMNode::operator == (DOMNodeType type)
{
    if (this->nodeType() == type) {
        return true;
    }
    else {
        return false;
    }
}

bool DOMNode::operator != (DOMNodeType type)
{
    if (this->nodeType() != type) {
        return true;
    }
    else {
        return false;
    }
}

};

