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

FQueue DBParser::funcList_;

DBParser::DBParser(const char *filename): file_(filename)  //same as file_ = filename
{
}

const char * DBParser::get_file()
{
    return file_;
}

void DBParser::addCallback(string name, funcV funcCall)
{
    funcList_.insert(std::pair<string, funcV>(name, funcCall));
}

void DBParser::callFunctions()
{
    for (auto const& x : funcList_)
    {
        std::cout << x.first << ':';
        (* x.second)();
        std::cout << std::endl ;
    }
}