#include "DBParserJSON.h"

#include "rapidjson102/filereadstream.h"
#include "rapidjson102/document.h"
#include "../DBParser.h"
#include <cstdio>

using namespace rapidjson;

class DBParserJSON: public DBParser {
public:
    void parse(){

        FILE* fp = fopen(getFile(), "r");
        char readBuffer[65536];
        FileReadStream is(fp, readBuffer, sizeof(readBuffer));
        Document d;
        d.ParseStream(is);
        fclose(fp);
    }

};
