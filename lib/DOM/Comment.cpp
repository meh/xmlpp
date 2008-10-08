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

#include "Comment.h"

namespace xmlpp {

namespace DOM {

Comment::Comment (Node* ownerDocument, const DOMString& data) : CharacterData (ownerDocument, Node::COMMENT_NODE)
{
    _data = data;
}

Comment::~Comment (void)
{
}

// Parent realization.
DOMString
Comment::nodeName (void)
{
    return (DOMString) "#comment";
}

DOMString
Comment::nodeValue (void) throw()
{
    return this->data();
}

void
Comment::nodeValue (const DOMString& value) throw()
{
    this->data(value);
}

Node*
Comment::cloneNode (bool deep)
{
    return new Comment(this->ownerDocument(), this->data());
}

};

};

