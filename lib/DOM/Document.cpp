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

Document::Document (void) : Node(Node::DOCUMENT_NODE)
{
    _documentElement = NULL;
}

Element*
Document::documentElement (void)
{
    return _documentElement;
}

Element*
Document::createElement (DOMString tagName)
{
    return new Element(this, tagName);
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
Document::nodeValue (const char* value) throw() 
{
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
    NamedNodeMap attrs(this);

    return attrs;
}

Node*
Document::insertBefore (Node* childNode, Node* nodeAfter) throw()
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

    _documentElement = newChild;

    return oldChild;
}

Node*
Document::removeChild (Node* childNode) throw()
{
    if (childNode != _documentElement) {
        throw DOMException(DOMException::NOT_FOUND_ERR);
    }

    _documentElement = NULL;

    return childNode;
}

Node*
Document::appendChild (Node* childNode)
{
    if (_documentElement == NULL) {
        _documentElement = childNode;
    }
    else {
        throw DOMException(DOMException::HIERARCHY_REQUEST_ERR);
    }
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

