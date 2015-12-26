#ifndef DBParserJSON_h
#define DBParserJSON_h

#include <stdio.h>
#include "../DBParser.h"
#include "rapidjson102/filereadstream.h"
#include "rapidjson102/document.h"
#include <list>
#include <iostream>
#include <cstdio>


using namespace rapidjson;

class DBParserJSON: public DBParser {
    using DBParser::DBParser;
public:
    void parse();
    bool parsed();
    
private:
    bool parsed_ = false;

    struct MessageHandler;
};



#endif
