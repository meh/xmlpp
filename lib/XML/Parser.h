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

#include "../Parser.h"
#include "XMLException.h"

namespace xmlpp {

namespace XML {

class Parser : public xmlpp::Parser
{
  public:
    Parser (void);

    DOM::Document* Load (const std::string& text);

    std::string Save (DOM::Document* document);

  private:
    typedef struct {
        DOM::NodeType type;
        size_t offset;
        std::string text;
    } Node;

  private:
    DOM::Document* _parseDocument (const std::string& text);

    DOM::Element* _parseRoot (const std::string& text);

    Parser::Node* _fetchNode (const std::string& text);
    DOM::Node* _parseNode (const std::string& text);

    Parser::Node* _fetchElement (const std::string& text);
    std::string _closingTag (const std::string& text);

    DOM::Element* _parseElementTag (const std::string& text);
    DOM::Element* _parseElement (const std::string& text);

    Parser::Node* _recognizeNode (const std::string& text);
};

};

};
