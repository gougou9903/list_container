#include <sstream>
#include <string>
#include "exception.h"

Exception::Exception(std::string _description,
                     std::string _fileName, int _line) : description(_description),
                                                         fileName(_fileName),
                                                         line(_line) {}

const std::string Exception::getDescription() const {
    std::stringstream errorDesc;
    errorDesc << description << " at line " << line << " of the file " << fileName;
    return errorDesc.str();
}
