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

Attr::Attr (Node* ownerDocument, const DOMString& name) : Node(ownerDocument, Node::ATTRIBUTE_NODE)
{
    _name = name;
}

Attr::~Attr (void)
{
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

Node*
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

DOMString
Attr::nodeValue (void) throw()
{
    this->value();
}

void
Attr::nodeValue (const DOMString& value) throw()
{
    this->value(value);
}

NodeList
Attr::childNodes (void)
{
    return NodeList();
}

Node*
Attr::firstChild (void)
{
    return NULL;
}

Node*
Attr::lastChild (void)
{
    return NULL;
}

NamedNodeMap
Attr::attributes (void)
{
    return NamedNodeMap(this);
}

Node*
Attr::insertBefore (Node* newChild, Node* refChild) throw()
{
    throw DOMException(DOMException::HIERARCHY_REQUEST_ERR);
}

Node*
Attr::replaceChild (Node* newChild, Node* oldChild) throw()
{
    throw DOMException(DOMException::HIERARCHY_REQUEST_ERR);
}

Node*
Attr::removeChild (Node* oldChild) throw()
{
    throw DOMException(DOMException::NOT_SUPPORTED_ERR);
}

Node*
Attr::appendChild (Node* newChild) throw()
{
    throw DOMException(DOMException::NOT_SUPPORTED_ERR);
}

bool
Attr::hasChildNodes (void)
{
    return false;
}

Node*
Attr::cloneNode (bool deep)
{
    Attr* attr = new Attr (this->ownerDocument(), this->name());
    attr->value(this->value());
    attr->_isId = _isId;

    return attr;
}

};

};

