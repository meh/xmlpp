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
#if !defined(XMLPP_DOM_NODELIST_H)
#define XMLPP_DOM_NODELIST_H

class NodeList
{
  public:
    void insert (Node* node);
    void insert (Node* node, unsigned long index);

    Node* replace (Node* node, unsigned long index);

    Node* remove (unsigned long index);

    Node* item (unsigned long index);

    unsigned long length (void);

    bool empty (void);

  private:
    std::vector<Node*> _nodes;
};

#endif
#endif

