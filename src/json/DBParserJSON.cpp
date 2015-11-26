#include "DBParserJSON.h"

#include "rapidjson102/filereadstream.h"
#include "rapidjson102/document.h"
#include "../DBParser.h"
#include <cstdio>

using namespace rapidjson;


class DBParserJSON: public DBParser {
public:
    Document d;
    
    void parse(){
        if(!parsed) {
            FILE* fp = fopen(get_file(), "r");
            char readBuffer[65536];
            FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    
            d.ParseStream(is);
            fclose(fp);
            parsed = true;
        }
    }
private:
    bool parsed = false;
};
