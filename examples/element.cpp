#include <iostream>
#include "../lib/xml/element.h"

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    XMLElement *element = new XMLElement("pokemon");
    element->setAttribute("gay", "\"i'm gay\"");

    cout << "Name:  " << element->getAttribute("gay")["name"]  << endl;
    cout << "Value: " << element->getAttribute("gay")["value"] << endl;
    cout << "Plain: " << element->getAttribute("gay")["plain"] << endl;

    return 0;
}

