/// @file dom/child.h
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

DOMChildNode::DOMChildNode (DOMNodeType type) : DOM (DOM_CHILD)
{
    this->type = type;
}

DOMNodeType DOMChildNode::nodeType (void)
{
    return this->type;
}

DOM* DOMChildNode::parentNode (void)
{
    return this->parent;
}

DOMChildNode* DOMChildNode::previousSibling (void)
{
    return this->pSibling;
}

DOMChildNode* DOMChildNode::nextSibling (void)
{
    return this->nSibling;
}

void DOMChildNode::__setParent (DOM* parent)
{
    this->parent = parent;
}

void DOMChildNode::__setPreviousSibling (DOMChildNode* sibling)
{
    this->pSibling = sibling;
}

void DOMChildNode::__setNextSibling (DOMChildNode* sibling)
{
    this->nSibling = sibling;
}

};

