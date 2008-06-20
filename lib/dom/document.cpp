/// @file   dom/document.cpp
/// @brief  This file includes the XML object implementation.

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

#include "document.h"

namespace xmlpp {

DOM::DOM (void)
{
}

DOMChildNode* DOM::childNode (int childNode)
{
    if (this->children.size() <= childNode) {
        throw DOMException (EX_OUT_OF_RANGE);
    }
    else {
        return this->children.at(childNode);
    }
}

DOMChildNode* DOM::getElementById (std::string id)
{
    DOMChildNode *found = NULL;

    for (size_t i = 0; i < this->children.size(); i++) {
        if (this->childNode(i)->getAttribute("id") == id) {
            found = this->childNode(i);
            break;
        }
        else {
            found = this->childNode(i)->__getElementById(id);

            if (found != NULL) {
                break;
            }
        }
    }

    return found;
}

DOMChildNode* DOM::getElementById (const char* id)
{
    return this->getElementById((std::string) id);
}

};

