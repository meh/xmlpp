/// @file dom/dom.h
/// @brief This file includes the DOM.

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

#if !defined(XMLPP_DOM)
#define XMLPP_DOM TRUE

#include "../common.h"

namespace xmlpp {

#define DOM_DOCUMENT  1
#define DOM_CHILD     2

class DOM
{
  private:
    /// @brief  The unique id of the node.
    double uniqueID;

    int type;

  public:
    DOM (int);

    int getType (void);

    // Don't use these methods.
    #ifndef DOXYGEN_SHOULD_SKIP_THIS
    double __getID (void);
    #endif

    /// @brief  Get if a node is exactly the same as another (checks the unique id of the node).
    ///
    /// @return  True if it's the same.
    bool operator == (DOM* element);
    bool operator != (DOM* element);
};

};

#endif
