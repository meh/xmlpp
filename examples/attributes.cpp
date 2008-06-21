#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    DOMElement *element = new DOMElement("div");
    element->setAttribute("id", "omg");

    cout << element->getAttribute("id") << endl;

    element->setAttribute("id", "win");

    cout << element->getAttribute("id") << endl;

    return 0;
}

