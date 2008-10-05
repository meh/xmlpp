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
#define XMLPP_DOM_DOCUMENT

#include "../common.h"

#include "Node.h"
#include "Element.h"
#include "Text.h"

namespace xmlpp {

namespace DOM {

/// @brief DOM document class.
class Document : public Node
{
  public:
    Document (void);

    ~Document (void);

  private:
};

};

};

#endif
