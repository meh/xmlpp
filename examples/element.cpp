#include <iostream>
#include "../lib/xml/element.h"

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    XMLElement *element = new XMLElement("pokemon");
    element->setAttribute("style", "width: 234px; height: 23px;");

    cout << "Name:  " << element->getAttribute("style")["name"]  << endl;
    cout << "Value: " << element->getAttribute("style")["value"] << endl;
    cout << "Plain: " << element->getAttribute("style")["plain"] << endl;

    return 0;
}

