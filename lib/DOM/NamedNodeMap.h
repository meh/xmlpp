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

#if defined(XMLPP_DOM_NODE_H)
#if !defined(XMLPP_NAMEDNODEMAP_H)
#define XMLPP_NAMEDNODEMAP_H

class NamedNodeMap
{
  public:
    friend class Element;

  public:
    NamedNodeMap (void);
    NamedNodeMap (Node* ownerNode);

    Node* getNamedItem (const DOMString& name);

    Node* setNamedItem (Node* arg) throw ();
    
    Node* removeNamedItem (const DOMString& name) throw ();

    Node* item (unsigned long index);

    unsigned long length (void);

    Node* getNamedItemNS (const DOMString& namespaceURI, const DOMString& localName) throw ();

    Node* setNamedItemNS (Node* arg) throw ();

    Node* removeNamedItemNS (const DOMString& namespaceURI, const DOMString& localName) throw ();

  private:
    Node* _ownerNode;

    std::map<DOMString, Node*> _items;
};

#endif
#endif

