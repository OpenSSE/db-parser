
#include <iostream>
#include "json/DBParserJSON.h"


/*
 * This function takes two parameters, one to store the result 
 * of the function, and the second to transform the input of the 
 * callback.
 * 
 *
 * In this example:
 *
 * The first parameter is a pointer to a list of records that it is defined
 * for the callback creator to maintain the result of the function. Here,
 * we insert into this list all the values that the callback indicates.
 *
 * The second parameter is a record struct (or whatever struct) that the 
 * caller of the callback knows, here, it is a [string, list<unsigned>]
 * which is called after the array is parsed.
 *
 * The body of the function is just to append the input of the caller 
 * to the list where are stored. 
 *
 * param_input.append(input_callback)
 *
 */
void func1(const string& keyword, const list<unsigned> &documents)
{
    std::cout << keyword << ':';
    for (auto const& x: documents){
        std::cout << x << " ";
    }
    std::cout << std::endl;
}



int main(int argc, const char * argv[]) {
   
    if(argc != 2) {
        std::cout << "usage: " << argv[0] << " <filename> \n";
    } else {
        
        /* We prepare the functions to added into the scheduler */
        
        void (*f1)(const string& keyword, const list<unsigned> &documents);
        f1 = &func1;
        
        
        DBParserJSON parser(argv[1]);
        /* 
         * We add the functions into the scheduler
         * The first parameter is an identifier (name) for the scheduler executor, 
         * in case that if we need to execute some functions.
         *
         */

        parser.addCallbackList(f1);

        std::cout << "starting the parse \n";
        parser.parse();
        std::cout << "parse finished \n";
        
    }
    return 0;
}
