#include <iostream>
#include <xml++/xml++.h>

using namespace std;
using namespace xmlpp;

int main (int argc, char *argv[])
{
    DOMText *text = new DOMText("lol");
    cout << text->nodeValue() << endl;

    text->nodeValue("omg");
    cout << text->nodeValue() << endl;

    return 0;
}

