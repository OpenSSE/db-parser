/***
 * Abstract class to operate with different kind of providers.
 ***/

#ifndef DBParser_h
#define DBParser_h

#include <string>
#include <map>
#include <utility>
#include <list>

using namespace std;

typedef void(*func)(void*, void*);

typedef std::pair<func, void*> funcParam;
typedef std::map<string, std::pair<func, void*>> FQueue;



typedef void(*funcList)(const string& keyword, const list<unsigned> &documents);
typedef void(*funcPair)(const string& keyword, const unsigned &doc);
typedef std::list<funcPair> FPairQueue;
typedef std::list<funcList> FListQueue;

class DBParser
{
public:
    DBParser(const char *filename);
//    virtual ~DBParser();
    virtual void parse() = 0;
    
    const char *get_file();
    void addCallback(string name, func funcCall, void* param);

    void addCallbackPair(funcPair);
    void addCallbackList(funcList);

    static void callFunctions(void *param_input);
    static void callFunctions(string context, void *param_input);
    
    static void callFunctionsPair(const string& keyword, const unsigned &doc);
    static void callFunctionsList(const string& keyword, const list<unsigned> &documents);
    
    static FQueue funcList_;
    
    static FPairQueue pairqueue_;
    static FListQueue listqueue_;
private:
    const char *file_;
};


#endif /* DBParser_h */
