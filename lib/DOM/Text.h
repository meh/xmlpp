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

#if !defined(XMLPP_DOM_TEXT_h)
#define XMLPP_DOM_TEXT_h

#include "../common.h"
#include "CharacterData.h"

namespace xmlpp {

namespace DOM {

class Text : public CharacterData
{
  public:
    friend class Document;

  protected:
    Text (Node* ownerDocument, const DOMString& data);

  public:
    virtual ~Text (void);

    Text* splitText (unsigned long offset);

  // Parent realization.
  public:
    DOMString nodeName (void);

    DOMString nodeValue (void) throw();
    void nodeValue (const DOMString& value) throw();

    Node* cloneNode (bool deep = true);
};

};

};

#endif
