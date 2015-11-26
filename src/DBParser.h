/***
 * Abstract class to operate with different kind of providers.
 ***/

#ifndef DBParser_h
#define DBParser_h

#include <string>

using namespace std;

class DBParser
{
public:
    DBParser(const char *filename);
    virtual ~DBParser();
    virtual void parse() = 0;
    
    const char *get_file();
    
private:
    const char *file_;
};


#endif /* DBParser_h */
