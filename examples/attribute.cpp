#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    DOMElement *element = new DOMElement("div");
    element->setAttribute("name", "gianni");

    cout << element->getAttribute("name") << endl;

    return 0;
}

