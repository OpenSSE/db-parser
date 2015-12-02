
#include <iostream>
#include "json/DBParserJSON.h"

int main(int argc, const char * argv[]) {
   
    if(argc != 2) {
        std::cout << "usage: " << argv[0] << " <filename> \n";
    } else {
        DBParserJSON parser(argv[1]);
        std::cout << "starting the parse \n";
        parser.parse();
        std::cout << "parse finished \n";
    }
    
    return 0;
}
