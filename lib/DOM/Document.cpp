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

#include "Document.h"

namespace xmlpp {

namespace DOM {

Document::Document (void) : Node(this, Node::DOCUMENT_NODE)
{
    _documentElement = NULL;
}

Document::~Document (void)
{
    if (_documentElement != NULL) {
        delete _documentElement;
    }
}

Element*
Document::documentElement (void)
{
    return _documentElement;
}

Element*
Document::createElement (const DOMString& tagName)
{
    return new Element(this, tagName);
}

Text*
Document::createTextNode (const DOMString& data)
{
    return new Text(this, data);
}

Comment*
Document::createComment (const DOMString& data)
{
    return new Comment(this, data);
}

CDATASection*
Document::createCDATASection (const DOMString& data) throw()
{
    return new CDATASection(this, data);
}

Attr*
Document::createAttribute (const DOMString& name) throw()
{
    return new Attr(this, name);
}

void
Document::normalizeDocument (void)
{
    _documentElement->_normalize();
}

// Parent realization
DOMString
Document::nodeName (void)
{
    return (DOMString) "#document";
}

DOMString
Document::nodeValue (void) throw()
{
    return DOMString();
}

void
Document::nodeValue (const DOMString& value) throw()
{
}

NodeList
Document::childNodes (void)
{
    NodeList list;
    list.insert(_documentElement);

    return list;
}

Node*
Document::firstChild (void)
{
    return _documentElement;
}

Node*
Document::lastChild (void)
{
    return _documentElement;
}

NamedNodeMap
Document::attributes (void)
{
    return NamedNodeMap(this);
}

Node*
Document::insertBefore (Node* newChild, Node* refChild) throw()
{
    throw DOMException(DOMException::HIERARCHY_REQUEST_ERR);
}

Node*
Document::replaceChild (Node* newChild, Node* oldChild) throw()
{
    if (newChild->nodeType() == Node::DOCUMENT_NODE) {
        throw DOMException(DOMException::HIERARCHY_REQUEST_ERR);
    }

    if (oldChild != _documentElement) {
        throw DOMException(DOMException::NOT_FOUND_ERR);
    }

    _documentElement = (Element*) newChild;

    return oldChild;
}

Node*
Document::removeChild (Node* oldChild) throw()
{
    if (oldChild != _documentElement) {
        throw DOMException(DOMException::NOT_FOUND_ERR);
    }

    _documentElement = NULL;

    return oldChild;
}

Node*
Document::appendChild (Node* newChild) throw()
{
    if (_documentElement == NULL) {
        return (_documentElement = (Element*) newChild);
    }

    throw DOMException(DOMException::HIERARCHY_REQUEST_ERR);
}

bool
Document::hasChildNodes (void)
{
    return (_documentElement != NULL);
}

Node*
Document::cloneNode (bool deep)
{
    Document *document = new Document;

    if (deep) {
        document->appendChild(this->documentElement()->cloneNode());
    }

    return document;
}

};

};

