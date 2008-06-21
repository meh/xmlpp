#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    DOMElement *element = new DOMElement("body");

    DOMElement *element2 = new DOMElement("div");
    element2->setAttribute("id", "lol");

    DOMElement *element3 = new DOMElement("div");
    element3->setAttribute("id", "omg");

    element->appendChild(element2);

    cout << element->firstChild()->getAttribute("id") << endl;

    element->replaceChild(element3, element2);

    cout << element->firstChild()->getAttribute("id") << endl;

    // Output:
    // lol
    // omg
    
    return 0;
}

