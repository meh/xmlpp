#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;
using namespace xmlpp::DOM;

int main(int argc, char *argv[]) {
    Parser parser(new XML::Parser);

    Document* doc = parser.load("lol.xml");
    doc->normalizeDocument();

    cout << doc->getElementsByTagName("omg").item(0)->firstChild()->nodeValue() << std::endl;

    return 0;
}

