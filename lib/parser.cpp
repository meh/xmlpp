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

DOMParser::DOMParser()
{
}

DOMParser::DOMParser (std::string xmlFile)
{
    this->xmlDocument = this->parseFromFile(xmlFile);
}

DOMParser::DOMParser (const char* xmlFile)
{
    this->xmlDocument = this->parseFromFile(xmlFile);
}

std::string DOMParser::fetch (std::string xmlString)
{
    std::string plainText;
    std::string line;

    std::ifstream xmlFile(xmlString.c_str());

    if (xmlFile.is_open()) {
        while (!xmlFile.eof()) {
            getline(xmlFile, line);
            plainText += line + "\n";
        }
        plainText.resize(plainText.length()-2);
    }
    else {
        throw XMLException(PARSER_FILE_READ_ERROR);
    }

    return plainText;
}

XML* DOMParser::parseFromFile (std::string xmlFile)
{
    this->plainText = this->fetch(xmlFile);
    this->xmlDocument   = this->parseFromString(this->plain());

    return this->xmlDocument;
}

XML* DOMParser::parseFromFile (const char* xmlFile)
{
    this->plainText   = this->fetch((std::string) xmlFile);
    this->xmlDocument = this->parseFromString(this->plain());

    return this->xmlDocument;
}

XML* DOMParser::parseFromString (std::string xmlText)
{
    return this->parse(xmlText);
}

XML* DOMParser::parseFromString (const char* xmlText)
{
    return this->parse((std::string) xmlText);
}

XML* DOMParser::parse (std::string xmlText)
{
    XML *xmlDocument = new XML();

    return xmlDocument;
}

XML* DOMParser::document (void)
{
    return this->xmlDocument;
}

std::string DOMParser::plain (void)
{
    return this->plainText;
}

};

