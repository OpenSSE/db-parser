#include "DBParserJSON.h"

#include "rapidjson102/filereadstream.h"
#include "rapidjson102/document.h"
#include "../DBParser.h"
#include <iostream>
#include <cstdio>

using namespace rapidjson;
using namespace std;

void DBParserJSON::parse(){
    if(!parsed_) {
        FILE* fp = fopen(get_file(), "r");
        char readBuffer[65536];
        FileReadStream is(fp, readBuffer, sizeof(readBuffer));
            
        MessageHandler handler;
        Reader reader;

        reader.Parse(is, handler);
            
        fclose(fp);
        parsed_ = true;
    }
};





