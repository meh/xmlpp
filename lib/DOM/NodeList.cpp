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

void
Node::NodeList::insert (Node* node)
{
    _nodes.push_back(node);
}

void
Node::NodeList::insert (Node* node, unsigned long index)
{
    _nodes.insert(_nodes.begin()+index, node);
}

Node*
Node::NodeList::replace (Node* node, unsigned long index)
{
    Node* replaced = _nodes.at(index);
    _nodes[index]  = node;

    return replaced;
}

Node*
Node::NodeList::remove (unsigned long index)
{
    Node* node = _nodes.at(index);
    _nodes.erase(_nodes.begin()+index);
    
    return node;
}

Node*
Node::NodeList::item (unsigned long index)
{
    if (index >= this->length()) {
        return NULL;
    }
    
    return _nodes[index];
}

unsigned long
Node::NodeList::length (void)
{
    return _nodes.size();
}

bool
Node::NodeList::empty (void)
{
    return _nodes.empty();
}

};

};
