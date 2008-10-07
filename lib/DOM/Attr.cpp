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

#include "Attr.h"

namespace xmlpp {

namespace DOM {

Attr::Attr (Document* ownerDocument, const DOMString& name) : Node(ownerDocument, Node::ATTRIBUTE_NODE)
{
    _name = name;
}

DOMString
Attr::name (void)
{
    return _name;
}

DOMString
Attr::value (void)
{
    return _unescapeString(_value);
}

void
Attr::value (const DOMString& value)
{
    _value = value;
}

Element*
Attr::ownerElement (void)
{
    return _ownerElement;
}

// Parent realization.
DOMString
Attr::nodeName (void)
{
    return this->name();
}

void
Attr::nodeValue (void) throw()
{
    this->value();
}

void
Attr::nodeValue (const DOMString& value) throw()
{
    this->value(value);
}

};

};

