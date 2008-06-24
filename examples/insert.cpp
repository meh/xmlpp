#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    DOMElement *element  = new DOMElement("div");
    element->appendChild(new DOMElement("lol"));
    element->insertBefore(new DOMElement("omg"), element->firstChild());

    cout << element->firstChild()->nodeName() << endl;

    return 0;
}

