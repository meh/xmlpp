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

#include "DOMException.h"

namespace xmlpp {

namespace DOM {

DOMException::DOMException (int code) : std::exception ()
{
    switch (code) {
        case INDEX_SIZE_ERR:
        _description = "Index or size is negative, or greater than the allowed value.";
        break;

        case DOMSTRING_SIZE_ERR:
        _description = "The range does not fit into a DOMString.";
        break;

        case HIERARCHY_REQUEST_ERR:
        _description = "You're trying to insert a node in a wrong place.";
        break;

        case WRONG_DOCUMENT_ERR:
        _description = "The document is different from the creator.";
        break;
    }
}

const char*
DOMException::what (void) const throw()
{
    return _description.c_str();
}

};

};

