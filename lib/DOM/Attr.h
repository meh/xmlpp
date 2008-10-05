/// @file dom/attribute.h
/// @brief This file includes the XML attribute definitions.

/****************************************************************************
* XML++ is a library for working with XML files.                                *
* Copyright (C) 2008  cHoBi                                                 *
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

namespace xmlpp {

namespace DOM {

class DOMAttr : public Node
{
  public:
    Attr (Element* owner, const char* name);
    Attr (Element* owner, const char* name, const char* value);
    Attr (Element* owner, const DOMString& name);
    Attr (Element* owner, const DOMString& name, const DOMString& value);

    DOMString name (void);

    DOMString value (void);

    void value (const char* value);
    void value (DOMString value);

  private:
    void _init (Element* owner, const DOMString& name, const DOMString& value, bool specified);

  private:
    Element _ownerElement;

    DOMString _name;

    DOMString _value;

    bool _isId;

    bool _specified;
};

};

};

#endif
