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

#if !defined(XMLPP_DOM_ATTRIBUTE)
#define XMLPP_DOM_ATTRIBUTE TRUE

#include "../common.h"

#include "Node.h"

namespace xmlpp {

namespace DOM {

class Attr : public Node
{
  protected:
    Attr (Document* ownerDocument, const DOMString& name);

  public:
    friend class Document;
    friend class Element;

    DOMString name (void);

    DOMString value (void);

    void value (const char* value);
    void value (DOMString value);

  private:
    void _init (Element* owner, const DOMString& name, const DOMString& value, bool specified);

  private:
    Element* _ownerElement;

    DOMString _name;

    DOMString _value;

    bool _isId;

    bool _specified;

  // Parent realization.
  public:
    DOMString nodeName (void);

    DOMString nodeValue (void) throw();
    void nodeValue (const char* value) throw();
    void nodeValue (const DOMString& value) throw(); 
};

};

};

#endif
