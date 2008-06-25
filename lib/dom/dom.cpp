/// @file dom/dom.cpp
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

#include "dom.h"

namespace xmlpp {

DOM::DOM (int type)
{
    this->type = type;

    // Create a random id.
    this->uniqueID = (rand() / (rand() * 0.23)) * (clock() / 10000);
}

int DOM::getType (void)
{
    return this->type;
}

double DOM::__getID (void)
{
    return this->uniqueID;
}

bool DOM::operator == (DOM* element)
{
    if (this->uniqueID == element->__getID()) {
        return true;
    }
    else {
        return false;
    }
}

bool DOM::operator != (DOM* element)
{
    if (this->uniqueID != element->__getID()) {
        return true;
    }
    else {
        return false;
    }
}

};

