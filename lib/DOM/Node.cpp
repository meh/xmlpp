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

Node::Node (Document* ownerDocument, NodeType type)
{
    _type = type;

    _parent   = NULL;
    _pSibling = NULL;
    _nSibling = NULL;

    _ownerDocument = ownerDocument;
}

NodeType
Node::nodeType (void)
{
    return _type;
}

Node*
Node::parentNode (void)
{
    return _parent;
}

Node*
Node::previousSibling (void)
{
    return _pSibling;
}

Node*
Node::nextSibling (void)
{
    return _nSibling;
}

NamedNodeMap
Node::attributes (void)
{
    return _attributes;
}

bool
Node::isSameNode (Node* another)
{
    if (this == another) {
        return true;
    }
    else {
        return false;
    }
}

bool
Node::isEqualNode (Node* another)
{
    return false;
}

bool
Node::operator == (Node* another)
{
    return this->isSameNode(another);
}

bool
Node::operator != (Node* another)
{
    return !this->isSameNode(another);
}

};

};

