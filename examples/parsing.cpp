#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    XMLParser *parser = new XMLParser();
    DOM *document     = parser->parseFromFile("lol.xml");

    return 0;
}

