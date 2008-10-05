/// @file dom/NamedNodeMap.h

/****************************************************************************
* XML++ is a library for working with XML files.                            *
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

#if !defined(XMLPP_DOM_NAMED_NODE_MAP)
#define XMLPP_DOM_NAMED_NODE_MAP TRUE

#include "../common.h"

namespace xmlpp {

namespace dom {

class NamedNodeMap
{
  public:
    NamedNodeMap (NodeType type);

    Node* getNamedItem (DOMString name);

    Node* setNamedItem (Node* node) throw (DOMException);
    
    Node* removeNamedItem (DOMString name) throw (DOMException);

    Node* item (unsigned long index);

    unsigned long length (void);

    Node* getNamedItemNS (DOMString namespaceURI, DOMString localName) throw (DOMException);

    Node* setNamedItemNS (Node* node) throw (DOMException);

    Node* removeNamedItemNS (DOMString namespaceURI, DOMString localName) throw (DOMException);

  private:
    std::map<DOMString, Node*> _items;

    NodeType _ownerType;
};

};

};

#endif

