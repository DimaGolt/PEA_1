#ifndef PEA_1_PARSER_H
#define PEA_1_PARSER_H


#include <string>
#include "Matrix.h"

using namespace std;

class Parser {

public:
    Matrix * LoadFile(string &filename);
};


#endif //PEA_1_PARSER_H
