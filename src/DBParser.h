#ifndef DBParser_h
#define DBParser_h


/***
 * Abstract class to operate with different kind of providers.
 ***/

class DBParser
{
public:
    virtual ~DBParser();
    virtual void parse() = 0;
    
    void setFile(char* input)
    {
        file = input;
    }
    
    char *getFile(){
        return file;
    }
private:
    char *file;
    
    
};


#endif /* DBParser_h */
