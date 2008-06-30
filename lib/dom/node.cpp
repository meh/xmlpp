/// @file dom/node.cpp
/// @brief This file includes the DOM child definitions.

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

#include "child.h"

namespace xmlpp {

DOMNode::DOMNode (DOMNodeType type)
{
    this->type = type;

    // Create a random id.
    this->uniqueID = (rand() / (rand() * 0.23)) * (clock() / 10000);
}

DOMNodeType DOMNode::nodeType (void)
{
    return this->type;
}

DOMNode* DOMNode::parentNode (void)
{
    return this->parent;
}

DOMNode* DOMNode::previousSibling (void)
{
    return this->pSibling;
}

DOMNode* DOMNode::nextSibling (void)
{
    return this->nSibling;
}

void DOMNode::__setParent (DOMNode* parent)
{
    this->parent = parent;
}

void DOMNode::__setPreviousSibling (DOMNode* sibling)
{
    this->pSibling = sibling;
}

void DOMNode::__setNextSibling (DOMNode* sibling)
{
    this->nSibling = sibling;
}

double DOMNode::__getID (void)
{
    return this->uniqueID;
}

bool DOMNode::operator == (DOMNode* element)
{
    if (this->uniqueID == element->__getID()) {
        return true;
    }
    else {
        return false;
    }
}

bool DOMNode::operator != (DOMNode* element)
{
    if (this->uniqueID != element->__getID()) {
        return true;
    }
    else {
        return false;
    }
}

};

