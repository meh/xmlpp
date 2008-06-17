// Exception codes
#define PARSER_FILE_READ_ERROR       1
#define ATTRIBUTE_MODE_NOT_EXISTENT  10

namespace xmlpp {

class XMLException {
  private:
    std::string description;

  public:
    XMLException(int code) {
        switch (code) {
            case PARSER_FILE_READ_ERROR:
            this->description = "Error while reading the text file, maybe it doesn't exist.";
            break;

            case ATTRIBUTE_MODE_NOT_EXISTENT:
            this->description = "The modes are only 'name' or 'value'.";
            break;
        }
    }

    XMLException(const char* description) {
        this->description = description;
    }

    XMLException(std::string description) {
        this->description = description;
    }

    std::string getMessage() const throw() {
        return this->description + "\n";
    }
};

};

