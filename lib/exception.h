// Exception codes
#define XML_FILE_READ_ERROR   1
#define XML_PARSE_MODE_ERROR  2

class xmlException {
  private:
    string description;

  public:
    xmlException(int code) {
        switch (code) {
            case XML_FILE_READ_ERROR:
            this->description = "Error while reading the text file, maybe it doesn't exist.";
            break;

            case XML_PARSE_MODE_ERROR:
            this->description = "The parse mode doesn't exist.";
            break;
        }
    }

    xmlException(const char* description) {
        this->description = description;
    }

    xmlException(string description) {
        this->description = description;
    }

    string getMessage() const throw() {
        return this->description + "\n";
    }
};

