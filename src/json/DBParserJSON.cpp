#include "DBParserJSON.h"

#include "rapidjson102/filereadstream.h"
#include "rapidjson102/document.h"
#include "../DBParser.h"
#include <iostream>
#include <cstdio>


using namespace rapidjson;
using namespace std;






/*Test CALLBACK*/
void callback_test(Record rec) {
    std::cout << "keyword: " << rec.keyword << "\n";
    std::cout << "identifiers: ";
    std::list<unsigned>::iterator it;
    for(it = rec.identifiers.begin(); it != rec.identifiers.end(); ++it){
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
};






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





