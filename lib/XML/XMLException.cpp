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

#include "XMLException.h"

namespace xmlpp {

namespace XML {

XMLException::XMLException (int code) : std::exception ()
{
    switch (code) {
        case PARSER_FILE_READ_ERROR:
        _description = "Error while reading the text file, maybe it doesn't exist.";
        break;

        case NOT_STANDARD:
        _description = "There are some errors in the XML file.";
        break;

        case BAD_NODE:
        _description = "A node is bad written.";
        break;

        case TAG_NOT_CLOSED:
        _description = "A tag is not closed.";
        break;
    }
}

const char*
XMLException::what (void) const throw()
{
    return _description.c_str();
}

};

};

