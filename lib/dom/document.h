/// @file   dom/document.h
/// @brief  This file includes the XML object definitions.

/****************************************************************************
* XML++ is a library to work with XML files.                                *
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
#include "child.h"
#include "element.h"
#include "text.h"

namespace xmlpp {

/// @brief DOM document class.
class DOM
{
  private:
    /// @brief  The plain text version of the document.
    std::string document;

    /// @brief Vector with the child nodes.
    DOMChildNodes children;

  public:
    /// @brief  Says if the document is empty or not.
    ///
    /// @return  True if it's empty.
    ///          False if it isn't.
    bool empty (void);

    /// @brief  Get the plain text version of the document.
    /// 
    /// @return  The plain text document.
    std::string documentElement (void);

    /// @brief  Get a child node.
    ///
    /// @param  childNode  The child number in the vector.
    /// 
    /// @return  The pointer to the child.
    DOMChildNode* childNodes (int childNode);

    /// @brief  Get the element with that id.
    ///
    /// @param  id  The id to look for.
    ///
    /// @return  The DOMElement object with that nick.
    DOMChildNode* getElementById (std::string id);

    /// @brief  Get the element with that id.
    ///
    /// @param  id  The id to look for.
    ///
    /// @return  The DOMElement object with that nick.
    DOMChildNode* getElementById (const char* id);

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    DOMChildNodes getElementsByTagName (std::string tagName);

    /// @brief Get every element with the tag name passed starting from the node.
    ///
    /// @param  tagName  The tag name to use for searching.
    ///
    /// @return  A vector with the pointers to the matched nodes.
    DOMChildNodes getElementsByTagName (const char* tagName);
};

};

#endif
