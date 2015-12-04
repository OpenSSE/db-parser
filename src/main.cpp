
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
void func1(void* param_input, void* input_callback)
{
    list<Record> *listOfRecords = (list<Record> *)param_input;
    Record *mrecord = (Record *)input_callback;
    
    (* listOfRecords).push_back(*mrecord);
}


/* This function does nothing, it is just to have two functions
 * in the scheduler. 
 * 
 * The scheduler first call func1(_) and then it calls func2(_)
 *
 */
void func2(void* param_input, void* input_callback)
{
    printf( "func2 was called. \n" );
}



int main(int argc, const char * argv[]) {
   
    if(argc != 2) {
        std::cout << "usage: " << argv[0] << " <filename> \n";
    } else {
        
        /* We prepare the functions to added into the scheduler */
        
        void (*f1)(void *, void *);
        void (*f2)(void *, void *);
        f1 = &func1;
        f2 = &func2;
        
        /* This is a local pointer to store the values of the callback */
        list<Record> *listOfRecords = new list<Record>;

        
        DBParserJSON parser(argv[1]);

        
        /* 
         * We add the functions into the scheduler
         * The first parameter is an identifier (name) for the scheduler executor, 
         * in case that if we need to execute some functions.
         *
         */

        parser.addCallback("f1", f1, (void*) listOfRecords); 
        parser.addCallback("f2", f2, (void*) listOfRecords);

        std::cout << "starting the parse \n";
        parser.parse();
        std::cout << "parse finished \n";
        
        
        /* Now it is possible to iterate over listOfRecords */
        std::cout << "printing the list \n";
        for (auto const& x : *listOfRecords)
        {
            std::cout << x.keyword << ':';
            for(auto const& y : x.identifiers)
            {
                std::cout << y << " ";
            }
            std::cout << std::endl ;
        }
    }
    return 0;
}
