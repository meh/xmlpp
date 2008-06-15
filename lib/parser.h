#include "common.h"

class Parser {
  private:
    string xmlDoc;

    string getXmlDoc(string, int);

  public:
    Parser(const char*, int);
    Parser(string, int);
    Parser(ifstream);
};

