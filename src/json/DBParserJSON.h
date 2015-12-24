#ifndef DBParserJSON_h
#define DBParserJSON_h

#include <stdio.h>
#include "DBParser.h"
#include <list>
#include <iostream>
#include <cstdio>


class DBParserJSON: public DBParser {
    using DBParser::DBParser;
public:
    void parse();
    
private:
    bool parsed_ = false;

    struct MessageHandler;
};



#endif
