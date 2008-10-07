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

#if !defined(XMLPP_DOM_NODE_H)
#define XMLPP_DOM_NODE_H

#include "../common.h"

namespace xmlpp {

namespace DOM {

class Node 
{
  public:
    #include "NodeList.h"
    #include "NamedNodeMap.h"

  public:
    static const NodeType  ELEMENT_NODE                 = 1;
    static const NodeType  ATTRIBUTE_NODE               = 2;
    static const NodeType  TEXT_NODE                    = 3;
    static const NodeType  CDATA_SECTION_NODE           = 4;
    static const NodeType  ENTITY_REFERENCE_NODE        = 5;
    static const NodeType  ENTITY_NODE                  = 6;
    static const NodeType  PROCESSING_INSTRUCTION_NODE  = 7;
    static const NodeType  COMMENT_NODE                 = 8;
    static const NodeType  DOCUMENT_NODE                = 9;
    static const NodeType  DOCUMENT_TYPE_NODE           = 10;
    static const NodeType  DOCUMENT_FRAGMENT_NODE       = 11;
    static const NodeType  NOTATION_NODE                = 12;

    static const DocumentPosition  DOCUMENT_POSITION_DISCONNECTED             = 0x01;
    static const DocumentPosition  DOCUMENT_POSITION_PRECEDING                = 0x02;
    static const DocumentPosition  DOCUMENT_POSITION_FOLLOWING                = 0x04;
    static const DocumentPosition  DOCUMENT_POSITION_CONTAINS                 = 0x08;
    static const DocumentPosition  DOCUMENT_POSITION_IS_CONTAINED             = 0x10;
    static const DocumentPosition  DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC  = 0x20;

  public:
    friend class Document;
    friend class Element;

  protected:
    Node (Node* ownerDocument, NodeType type);

  public:
    virtual ~Node (void);

    virtual DOMString nodeName (void) = 0;

    virtual DOMString nodeValue (void) throw() = 0;
    virtual void nodeValue (const DOMString& value) throw() = 0;

    NodeType nodeType (void);

    Node* parentNode (void);

    virtual NodeList childNodes (void) = 0;

    virtual Node* firstChild (void) = 0;

    virtual Node* lastChild (void) = 0;

    Node* nextSibling (void);

    Node* previousSibling (void);

    virtual NamedNodeMap attributes (void) = 0;

    Node* ownerDocument (void);

    virtual Node* insertBefore (Node* newChild, Node* refChild) throw() = 0;

    virtual Node* replaceChild (Node* newChild, Node* oldChild) throw() = 0;

    virtual Node* removeChild (Node* oldChild) throw() = 0;
    
    virtual Node* appendChild (Node* newChild) throw() = 0;

    virtual bool hasChildNodes (void) = 0;

    virtual Node* cloneNode (bool deep = true) = 0;

    bool isSameNode (Node* another);

    bool isEqualNode (Node* another);

    bool operator == (Node* another);
    bool operator != (Node* another);
    
  protected:
    DOMString _unescapeString (const DOMString& text);
    DOMString _unescapeChar (const DOMString& text);
    
    std::map<DOMString, DOMString> _specialChars (void);

  protected:
    NodeType _type;

    Node* _pSibling;

    Node* _nSibling;

    Node* _parent;

    NodeList _children;

    NamedNodeMap _attributes;

    Node* _ownerDocument;
};

typedef Node::NodeList     NodeList;
typedef Node::NamedNodeMap NamedNodeMap;

};

};

#endif

