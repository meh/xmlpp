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

#include "Element.h"

namespace xmlpp {

namespace DOM {

Element::Element (Document* ownerDocument, const DOMString& tagName) : Node (ownerDocument, Node::ELEMENT_NODE)
{
    _tagName = tagName;
}

DOMString
Element::tagName (void)
{
    return Utils::toUpper(_tagName);
}

DOMString
Element::getAttribute (const DOMString& name)
{
    Node* attr = _attributes.getNamedItem(name);

    if (attr == NULL) {
        return "";
    }
    else {
        return attr->nodeValue();
    }
}

void
Element::setAttribute (const DOMString& name, const DOMString& value) throw()
{
    Node* attr = _attributes.getNamedItem(name);

    if (attr == NULL) {
        attr = new Attribute(this->ownerDocument(), name);
    }

    attr->value(value);
    attr->_ownerElement = this;
}

void
Element::removeAttribute (const DOMString& name) throw()
{
    Node* attr = _attributes.getNamedItem (name);

    if (attr != NULL) {
        delete _attributes.removeNamedItem(name);
    }
}

};

};

