#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;
using namespace xmlpp::DOM;

int main(int argc, char *argv[]) {
    Parser parser(new XML::Parser);

    Document* doc = parser.load("easy.xml");
    doc->normalizeDocument();

    std::cout << doc->firstChild()->firstChild()->nodeValue() << std::endl;

    doc = parser.load("hard.xml");
    std::cout << ((Element*)doc->getElementsByTagName("directories").item(0))->getElementsByTagName("document").item(0)->firstChild()->nodeValue() << std::endl;

    return 0;
}

