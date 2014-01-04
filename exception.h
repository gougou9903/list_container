#include <string>

/**
 * Common exception class
 */
class Exception {
public:
    /**
    * Constructs an exception object
    * @param _description General info about error
    * @param _filename Name of the file that generated error
    * @param _line Number of the line that generated error
    */
    Exception(std::string _description, std::string _fileName, unsigned int _line);

    /**
    * @return String with error info, including line number and filename
    */
    std::string getDescription() const;

private:
    std::string description;
    std::string fileName;
    unsigned int line;
};
