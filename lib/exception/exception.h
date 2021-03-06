/// @file exception.h
/// @brief This file includes the base exception definitions.

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

#if !defined(XMLPP_EXCEPTION)
#define XMLPP_EXCEPTION TRUE

#include <string>

namespace xmlpp {

class Exception {
  protected:
    std::string description;

  public:
    Exception (void);
    Exception (std::string description);
    Exception (const char* description);
    
    std::string getMessage (void);
};

};

#include "xml_exception.h"
#include "dom_exception.h"

#endif


