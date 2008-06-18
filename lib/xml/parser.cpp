/// @file   xml/parser.cpp
/// @brief  This file includes the DOM parser implementations.

/****************************************************************************
* XML++ is a library to work with XML files.                                *
* Copyright (C) 2008  Paolo D. Galli                                        *
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

#include "parser.h"

namespace xmlpp {

XMLParser::XMLParser()
{
}

XMLParser::XMLParser (std::string xmlFile)
{
    this->domObject = this->parseFromFile(xmlFile);
}

XMLParser::XMLParser (const char* xmlFile)
{
    this->domObject = this->parseFromFile(xmlFile);
}

std::string XMLParser::fetch (std::string xmlString)
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
        throw XMLException(EX_PARSER_FILE_READ_ERROR);
    }

    return plainText;
}

DOM* XMLParser::parseFromFile (std::string xmlFile)
{
    this->plainText = this->fetch(xmlFile);
    this->domObject = this->parseFromString(this->plain());

    return this->domObject;
}

DOM* XMLParser::parseFromFile (const char* xmlFile)
{
    this->plainText = this->fetch((std::string) xmlFile);
    this->domObject = this->parseFromString(this->plain());

    return this->domObject;
}

DOM* XMLParser::parseFromString (std::string xmlText)
{
    return this->parse(xmlText);
}

DOM* XMLParser::parseFromString (const char* xmlText)
{
    return this->parse((std::string) xmlText);
}

DOM* XMLParser::parse (std::string xmlText)
{
    DOM *domObject = new DOM();

    return domObject;
}

DOM* XMLParser::document (void)
{
    return this->domObject;
}

std::string XMLParser::plain (void)
{
    return this->plainText;
}

};

