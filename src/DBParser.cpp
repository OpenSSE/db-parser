//
//  DBParser.cpp
//  db-parser
//
//  Created by Mario Cornejo on 26/11/15.
//  Copyright © 2015 ENS. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "DBParser.h"

using namespace std;

/* The list of the functions to be called*/
FQueue DBParser::funcList_;


DBParser::DBParser(const char *filename): file_(filename)  //same as file_ = filename
{
}

const char * DBParser::get_file()
{
    return file_;
}


/* TODO 
 * change the name for registerCallback 
 */

void DBParser::addCallback(string name, func funcCall, void* param)
{
    funcList_.insert(std::pair<string, funcParam>(name, std::pair<func, void*>(funcCall, param)));
}


/* Execute functions */

/* Execute all functions in the list of task */
void DBParser::callFunctions(void *input_callback)
{
    for (auto const& x : funcList_)
    {
        std::cout << x.first << ':';
        funcParam funp = x.second;
        (* funp.first)(funp.second, input_callback);
        std::cout << std::endl ;
    }
}

/* Execute functions that the name matches with the context */
void DBParser::callFunctions(string context,void *input_callback)
{
    for (auto const& x : funcList_)
    {
        if(context == x.first){
            std::cout << x.first << ':';
            funcParam funp = x.second;
            (* funp.first)(funp.second, input_callback);
            std::cout << std::endl ;
        }
    }
}