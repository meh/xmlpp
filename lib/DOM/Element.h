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
* WITHOUT ANY WARRANTY; without even the implied warranty of                *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU Affero General Public License for more details.                       *
*                                                                           *
* You should have received a copy of the GNU Affero General Public License  *
* along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
****************************************************************************/

#if !defined(XMLPP_DOM_ELEMENT_H)
#define XMLPP_DOM_ELEMENT_H

#include "../common.h"
#include "Node.h"
#include "Text.h"
#include "Attr.h"

namespace xmlpp {

namespace DOM {

class Element : public Node
{
  public:
    friend class Document;

  protected:
    Element (Node* ownerDocument, const DOMString& tagName);

  public:
    virtual ~Element (void);

    DOMString tagName (void);

    DOMString getAttribute (const DOMString& name);
    void setAttribute (const DOMString& name, const DOMString& value) throw();
    void removeAttribute (const DOMString& name) throw();

    Attr* getAttributeNode (const DOMString& name);
    Attr* setAttributeNode (Attr* newAttr) throw();

    NodeList getElementsByTagName (const DOMString& name);

    bool hasAttribute (const DOMString& name);

    void setIdAttribute (const DOMString& name, bool isId) throw();
    void setIdAttributeNode (Attr* idAttr, bool isId) throw();

  private:
    DOMString _tagName;

  // Parent realization.
  public:
    DOMString nodeName (void);

    DOMString nodeValue (void) throw();
    void nodeValue (const DOMString& value) throw();

    NodeList childNodes (void);
    Node* firstChild (void);
    Node* lastChild (void);

    NamedNodeMap attributes (void);

    Node* insertBefore (Node* newChild, Node* refChild) throw();

    Node* replaceChild (Node* newChild, Node* oldChild) throw();

    Node* removeChild (Node* oldChild) throw();

    Node* appendChild (Node* newChild) throw();

    bool hasChildNodes (void);

    Node* cloneNode (bool deep = true);

  protected:
    void _normalize (void);
};

};

};

#endif
