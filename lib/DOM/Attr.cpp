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

Attr::Attr (const char* name) : Node(Node::ATTRIBUTE_NODE)
{
    _init(owner, (DOMString) name, (DOMString) "", false);
}

Attr::Attr (const char* name, const char* value) : Node(Node::ATTRIBUTE_NODE)
{
    _init(owner, (DOMString) name, (DOMString) value, true);
}

Attr::Attr (const DOMString& name) : Node(Node::ATTRIBUTE_NODE)
{
    _init(owner, name, (DOMString) "", false);
}

Attr::Attr (const DOMString& name, const DOMString& value) : Node(Node::ATTRIBUTE_NODE)
{
    _init(owner, name, value, true);
}

void
Attr::_init (const DOMString& name, const DOMString& value, bool specified)
{
    _ownerElement = NULL;

    _name  = name;
    _value = value;

    _isId      = (name == "id");
    _specified = specified;
}   

DOMString
Attr::name (void)
{
    return _name;
}

DOMString
Attr::value (void)
{
    return Utils::unescapeString(_value);
}

void
Attr::value (const char* value)
{
    _value = value;
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
Attr::nodeValue (const char* value) throw()
{
    this->value(value);
}

void
Attr::nodeValue (const DOMString& value) throw()
{
    this->value(value);
}

};

};

