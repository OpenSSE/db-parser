
#include <iostream>
#include "json/DBParserJSON.h"

void func1()
{
    printf( "func1\n" );
}

void func2()
{
    printf( "func2\n" );
}


int main(int argc, const char * argv[]) {
   
    if(argc != 2) {
        std::cout << "usage: " << argv[0] << " <filename> \n";
    } else {
        DBParserJSON parser(argv[1]);
        std::cout << "starting the parse \n";
        
        void (*f1)();
        void (*f2)();
        f1 = &func1;
        f2 = &func2;

        
        parser.addCallback("f1", f1);
        parser.addCallback("f2", f2);
        
        parser.parse();
        std::cout << "parse finished \n";
    }
    
    return 0;
}
