/// @file common.h
/// @brief This file includes the common constants and includes.

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


#if !defined(XMLPP_COMMON)
#define XMLPP_COMMON TRUE

#include <string.h>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstdio>

#include "DOM/DOMException.h"
#include "Utils.h"

namespace xmlpp {

namespace DOM {

typedef  std::string         DOMString;
typedef  unsigned long long  DOMTimeStamp;
typedef  unsigned short      DOMNodeType;
typedef  unsigned short      DOMDocumentPosition;
typedef  void*               DOMUserData;

};

};

#endif

