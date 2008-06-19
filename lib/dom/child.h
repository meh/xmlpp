/// @file dom/child.h
/// @brief This file includes the DOM child definitions.

/****************************************************************************
* XML++ is a library to work with XML files.                                *
* Copyright (C) 2008  Paolo D. Galli                                        *
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

#if !defined(XMLPP_DOM_CHILD)
#define XMLPP_DOM_CHILD TRUE

#include "../common.h"

#define DOM_ELEMENT_NODE  1
#define DOM_TEXT_NODE     2

namespace xmlpp {

class DOMChildNode
{
  protected:
    typedef std::vector<DOMChildNode*>::iterator DOMSibling;

    /// @brief The node's type: DOM_ELEMENT_NODE or DOM_TEXT_NODE
    DOMNodeType type;

    /// @brief  Node's name.
    std::string name;

    /// @brief  Node's value.
    std::string value;

    /// @brief  Plain text view of the node.
    std::string plainText;

    DOMChildNode* pSibling;
    DOMChildNode* nSibling;
    DOMChildNode* parent;

  public:
    /// @brief  Create the node.
    ///
    /// @param  type  The node's type.
    DOMChildNode (DOMNodeType type);

    // Getters.

    /// @brief  Get the node's type.
    ///
    /// @return  The type. DOM_ELEMENT_NODE or DOM_TEXT_NODE
    DOMNodeType nodeType (void);

    virtual std::string nodeName (void) = 0;
    virtual std::string nodeValue (void) = 0;
    virtual std::string text (void) = 0;

    virtual void appendChild (DOMChildNode* childNode) = 0;
    virtual DOMChildNode* childNodes (int childNode) = 0;

    virtual DOMChildNode* firstChild (void) = 0;
    virtual DOMChildNode* lastChild (void) = 0;

    virtual bool hasChildNodes (void) = 0;

    DOMChildNode* nodeParent (void);
    DOMChildNode* nextSibling (void);
    DOMChildNode* previousSibling (void);

    /// @ignore
    void __setParent (DOMChildNode* parent);
    /// @ignore
    void __setNextSibling (DOMChildNode* sibling);
    /// @ignore
    void __setPreviousSibling (DOMChildNode* sibling);
};

typedef std::vector<DOMChildNode*> DOMChildNodes;
typedef std::vector<DOMChildNode*>::iterator DOMSibling;

};

#endif

