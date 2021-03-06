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

#include "DOM.h"
#include "Utils.h"

#include <string>
#include <fstream>
#include <stack>

namespace xmlpp {

class Parser
{
  public:
    Parser (void);

  public:
    DOM::Document* load (const std::string& fileName);
    void save (DOM::Document* document, const std::string& fileName);

    virtual DOM::Document* Load (const std::string& text) = 0;
    virtual std::string Save (DOM::Document* document) = 0;

  protected:
    DOM::Document* _document;
};

};

