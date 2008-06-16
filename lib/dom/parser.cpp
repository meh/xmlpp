/// @file   dom/parser.cpp
/// @brief  This file includes the DOM parser implementations.

/****************************************************************************
 * XML++ is a library to work with XML files.
 * Copyright (C) 2008  Paolo D. Galli
 *
 * This file is part of XML++
 *
 * XML++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include "parser.h"

namespace xmlpp {

DOMParser::DOMParser (const char* xmlFile)
{
    this->plain = this->getPlain((std::string) xmlFile);
    this->xml   = new XML();
}

DOMParser::DOMParser (std::string xmlFile)
{
    this->plain = this->getPlain(xmlFile);
    this->xml   = new XML();
}

std::string DOMParser::getPlain (std::string xmlString)
{
    std::string plain;
    std::string line;

    std::ifstream xmlFile(xmlString.c_str());

    if (xmlFile.is_open()) {
        while (!xmlFile.eof()) {
            getline(xmlFile, line);
            plain += line + "\n";
        }
        plain.resize(plain.length()-2);
    }
    else {
        throw XMLException(PARSER_FILE_READ_ERROR);
    }

    return plain;
}

std::string DOMParser::document()
{
    return this->plain;
}

};

