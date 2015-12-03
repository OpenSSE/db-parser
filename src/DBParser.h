/***
 * Abstract class to operate with different kind of providers.
 ***/

#ifndef DBParser_h
#define DBParser_h

#include <string>
#include <map>

using namespace std;

typedef void(*func)(void*);
typedef void(*funcV)();

typedef std::map<string, funcV> FQueue;

class DBParser
{
public:
    DBParser(const char *filename);
//    virtual ~DBParser();
    virtual void parse() = 0;
    
    const char *get_file();
    void addCallback(string name, funcV funcCall);
    static void callFunctions();
    static FQueue funcList_;
private:
    const char *file_;
};


#endif /* DBParser_h */
