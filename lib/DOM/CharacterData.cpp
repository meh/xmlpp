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

#include "CharacterData.h"

namespace xmlpp {

namespace DOM {

CharacterData::CharacterData (Document* ownerDocument, NodeType type) : Node (ownerDocument, type)
{
}

DOMString
CharacterData::data (void)
{
    return _data;
}

void
CharacterData::data (const DOMString& string)
{
    _data = string;
}

void
CharacterData::appendData (const DOMString& arg) throw()
{
    _data.append(arg);
}

void
CharacterData::insertData (unsigned long offset, const DOMString& arg) throw()
{
    _data.insert(offset, arg);
}

void
CharachterData::replaceData (unsigned long offset, unsigned long count, const DOMString& arg) throw()
{
    _data.replace(offset, count, arg);
}

DOMString
CharacterData::substringData (unsigned long offset, unsigned long count) throw()
{
    return _data.substr(offset, count);
}

// Parent realization.
NodeList
CharacterData::childNodes (void)
{
    return NodeList();
}

Node*
CharacterData::firstChild (void)
{
    return NULL;
}

Node*
CharacterData::lastChild (void)
{
    return NULL;
}

Node*
CharacterData::attributes (void)
{
    return NamedNodeMap(this);
}

Node*
CharacterData::insertBefore (Node* newChild, Node* refChild) throw()
{
    throw DOMException(DOMException::HIERARCHY_REQUEST_ERR);
}

Node*
CharacterData::replaceChild (Node* newChild, Node* oldChild) throw()
{
    throw DOMException(DOMException::HIERARCHY_REQUEST_ERR);
}

Node*
CharacterData::removeChild (Node* oldChild) throw()
{
    throw DOMException(DOMException::NOT_SUPPORTED_ERR);
}

Node*
CharacterData::appendChild (Node* newChild) throw()
{
    throw DOMException(DOMException::NOT_SUPPORTED_ERR);
}

};

};

