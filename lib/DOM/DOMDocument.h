/// @file   dom/document.h
/// @brief  This file includes the XML object definitions.

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

#if !defined(XMLPP_DOM_DOCUMENT)
#define XMLPP_DOM_DOCUMENT TRUE

#include "../common.h"
#include "node.h"
#include "element.h"
#include "text.h"

namespace xmlpp {

/// @brief DOM document class.
class DOMDocument
{
  public:
    /// @brief  Initiate the DOM document.
    DOMDocument (void);

    /// @brief  Destroy the DOM document.
    ~DOMDocument (void);

    /// @brief  Get the plain text version of the document.
    /// 
    /// @return  The plain text document.
    std::string documentElement (void);

    /// @brief  Get the node's type.
    ///
    /// @return  The type. document | element | text
    DOMNodeType nodeType (void);

    /// @brief  Append a child to a DOMElement.
    ///
    /// @param  childNode  The pointer to the child to append.
    void appendChild (DOMNode* childNode);

    /// @brief  Insert a child before another child.
    ///
    /// @param  childNode  The pointer to the child to insert.
    /// @param  nodeAfter  The pointer to the child that you want to insert the child before.
    void insertBefore (DOMNode* childNode, DOMNode* nodeAfter);

    /// @brief  Replace a child with another.
    ///
    /// @param  newChild  The pointer to the child to put in the node.
    /// @param  oldChild  The pointer to the child to replace.
    void replaceChild (DOMNode* newChild, DOMNode* oldChild);

    /// @brief  Remove a child from the node.
    ///
    /// @param  childNode  The node number.
    void removeChild (int childNode);

    /// @brief  Remove a child from the node.
    ///
    /// @param  childNode  The pointer to the node that you want to delete.
    void removeChild (DOMNode* childNode);

    /// @brief  Get a child node.
    ///
    /// @param  childNode  The child number in the vector.
    /// 
    /// @return  The pointer to the child.
    DOMNode* childNodes (int childNode);

    /// @brief  Get the first child of the node.
    ///
    /// @return  The pointer to the first child.
    DOMNode* firstChild (void);

    /// @brief  Get the last child of the node.
    ///
    /// @return  The pointer to the last child.
    DOMNode* lastChild (void);

    /// @brief  Get the element with that id.
    ///
    /// @param  id  The id to look for.
    ///
    /// @return  The DOMElement object with that id.
    DOMNode* getElementById (std::string id);

    /// @brief  Get the element with that id.
    ///
    /// @param  id  The id to look for.
    ///
    /// @return  The DOMElement object with that id.
    DOMNode* getElementById (const char* id);

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    DOMNodes getElementsByTagName (std::string tagName);

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    DOMNodes getElementsByTagName (const char* tagName);

    /// @brief  Get the XML version of the document.
    ///
    /// @return  The XML version.
    std::string version (void);

    /// @brief  Set the XML version of the document.
    ///
    /// @param  version  The XML version to set.
    void setVersion (std::string version);

    /// @brief  Set the XML version of the document.
    ///
    /// @param  version  The XML version to set.
    void setVersion (const char* version);

  private:
    /// @brief  The XML version.
    std::string _xmlVersion;

    /// @brief  The document element.
    DOMElement* _element;
};

};

#endif
