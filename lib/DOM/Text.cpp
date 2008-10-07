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

#include "Text.h"

namespace xmlpp {

namespace DOM {

Text::Text (Node* ownerDocument, const DOMString& data) : CharacterData (ownerDocument, Node::TEXT_NODE)
{
    _data = data;
}

Text*
Text::splitText (unsigned long offset)
{
    if (this->parentNode() == NULL) {
        throw DOMException(DOMException::NO_MODIFICATION_ALLOWED_ERR);
    }

    Text* split = new Text(this->ownerDocument(), this->substringData(offset));
    this->data(this->substringData(0, offset));

    return (Text*) this->parentNode()->insertBefore(split, this->nextSibling());
}

// Parent realization.
DOMString
Text::nodeName (void)
{
    return (DOMString) "#text";
}

DOMString
Text::nodeValue (void) throw()
{
    return _unescapeString(this->data());
}

void
Text::nodeValue (const DOMString& value) throw()
{
    this->data(value);
}

Node*
Text::cloneNode (bool deep)
{
    Text* text = new Text(this->ownerDocument(), this->data());

    return text;
}

};

};

