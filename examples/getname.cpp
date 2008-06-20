#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    DOMElement *element = new DOMElement("div");
    
    DOMElement *element2 = new DOMElement("div");
    element2->setAttribute("id", "header");

    DOMElement *element3 = new DOMElement("div");
    element3->setAttribute("id", "top");

    element2->appendChild(element3);
    element->appendChild(element2);

    DOMChildNodes elements = element->getElementsByTagName("div");
    for (size_t i = 0; i < elements.size(); i++) {
        cout << i << ": " << elements[i]->getAttribute("id") << endl;
    }

    return 0;
}
