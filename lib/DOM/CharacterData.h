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

#if !defined(XMLPP_DOM_CHARACTERDATA_H)
#define XMLPP_DOM_CHARACTERDATA_H

#include "../common.h"
#include "Node.h"

namespace xmlpp {

namespace DOM {

class CharacterData : public Node
{
  protected:
    CharacterData (Node* ownerDocument, NodeType type);

  public:
    virtual ~CharacterData (void);

    DOMString data (void);
    void data (const DOMString& string);

    void appendData (const DOMString& arg) throw();

    void insertData (unsigned long offset, const DOMString& arg) throw();

    void replaceData (unsigned long offset, unsigned long count, const DOMString& arg) throw();

    DOMString substringData (unsigned long offset, unsigned long count = -1) throw();

  protected:
    DOMString _data;

  // Parent realization.
  public:
    virtual DOMString nodeName (void) = 0;

    virtual DOMString nodeValue (void) throw() = 0;
    virtual void nodeValue (const DOMString& value) throw() = 0;

    NodeList childNodes (void);
    Node* firstChild (void);
    Node* lastChild (void);

    NamedNodeMap attributes (void);

    Node* insertBefore (Node* newChild, Node* refChild) throw();

    Node* replaceChild (Node* newChild, Node* oldChild) throw();

    Node* removeChild (Node* oldChild) throw();

    Node* appendChild (Node* newChild) throw();

    bool hasChildNodes (void);

    virtual Node* cloneNode (bool deep = true) = 0;

  protected:
    virtual void _normalize (void);
};

};

};

#endif

