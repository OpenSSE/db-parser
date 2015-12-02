//
//  DBParser.cpp
//  db-parser
//
//  Created by Mario Cornejo on 26/11/15.
//  Copyright © 2015 ENS. All rights reserved.
//

#include <stdio.h>
#include "DBParser.h"


DBParser::DBParser(const char *filename): file_(filename)  //same as file_ = filename
{
}

const char * DBParser::get_file()
{
    return file_;
}