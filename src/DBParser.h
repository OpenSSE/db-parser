/***
 * Abstract class to operate with different kind of providers.
 ***/

#ifndef DBParser_h
#define DBParser_h

#include <string>
#include <map>
#include <utility>

using namespace std;

typedef void(*func)(void*, void*);
typedef std::pair<func, void*> funcParam;
typedef std::map<string, std::pair<func, void*>> FQueue;

class DBParser
{
public:
    DBParser(const char *filename);
//    virtual ~DBParser();
    virtual void parse() = 0;
    
    const char *get_file();
    void addCallback(string name, func funcCall, void* param);

    static void callFunctions(void *param_input);
    static void callFunctions(string context, void *param_input);
    
    static FQueue funcList_;
private:
    const char *file_;
};


#endif /* DBParser_h */
