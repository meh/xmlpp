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

#include "Parser.h"

namespace xmlpp {

Parser::Parser (void)
{
    _document = NULL;
}

Parser::Parser (Parser* specializedParser)
{
    _document = NULL;
    _parser   = specializedParser;
}

Parser::~Parser (void)
{
    if (_parser) {
        delete _parser;
    }
}

DOM::Document*
Parser::load (const std::string& fileName)
{
    std::ifstream file(fileName.c_str());

    if (file.is_open()) {
        std::string text;
        while (!file.eof()) {
            std::string line;

            getline(file, line);
            text += line + "\n";
        }
        file.close();
        text.resize(text.length()-2);

        return _parser->Load(text);
    }
    else {
        throw std::exception();
    }
}

void
Parser::save (DOM::Document* document, const std::string& fileName)
{
    std::ofstream file(fileName.c_str());
    file << _parser->Save(document);
}

};

