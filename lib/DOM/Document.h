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

#if !defined(XMLPP_DOM_DOCUMENT_H)
#define XMLPP_DOM_DOCUMENT_H

#include "../common.h"

#include "Node.h"
#include "Element.h"
#include "Text.h"
//#include "DocumentFragment.h"
#include "Comment.h"
#include "CDATASection.h"
#include "Attr.h"

namespace xmlpp {

namespace DOM {

class Document : public Node
{
  public:
    Document (void);

    virtual ~Document (void);

    Element* documentElement (void);

    Element* createElement (const DOMString& tagName);

//    DocumentFragment* createDocumentFragment (void);

    Text* createTextNode (const DOMString& data);

    Comment* createComment (const DOMString& data);

    CDATASection* createCDATASection (const DOMString& data) throw();

    Attr* createAttribute (const DOMString& name) throw();

  private:
    Element* _documentElement;

  // Parent realization
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
};

};

};

#endif
