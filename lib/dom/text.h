/// @file   dom/text.h
/// @brief  This file includes the DOM text definitions.

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

#if !defined(XMLPP_XML_TEXT)
#define XMLPP_XML_TEXT TRUE

#include "../common.h"
#include "child.h"

namespace xmlpp {

class DOMText : public DOMChildNode
{
  private:

  public:
    DOMText (std::string text);
    DOMText (const char* text);

    /// @brief  Get the node's name.
    ///
    /// @return  The node's name
    std::string nodeName (void);

    /// @brief  Get the node's value.
    ///
    /// @return  The node's value.
    std::string nodeValue (void);

    /// @brief  Get the text from the node.
    ///
    /// @return  The text from the node.
    std::string text (void);

    void appendChild (DOMChildNode* childNode);
    DOMChildNodes childNodes (void);
    DOMChildNode* childNode (int childNode);
    DOMChildNode* cloneNode (void);

    DOMChildNode* firstChild (void);
    DOMChildNode* lastChild (void);

    bool hasChildNodes (void);

//    DOMText* cloneNode (void);
};

};

#endif
