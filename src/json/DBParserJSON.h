#ifndef DBParserJSON_h
#define DBParserJSON_h

#include <stdio.h>
#include "../DBParser.h"
#include "rapidjson102/filereadstream.h"
#include "rapidjson102/document.h"
#include <list>
#include <iostream>
#include <cstdio>


using namespace rapidjson;

typedef struct {
    string keyword;
    list<unsigned> identifiers;
} Record;


class DBParserJSON: public DBParser {
    using DBParser::DBParser;
public:
    void parse();
    
private:
    bool parsed_ = false;

    struct MessageHandler: public BaseReaderHandler<UTF8<>, MessageHandler>{
        MessageHandler(): state_(kExpectObjectStart) {
        }
        
        bool StartObject() {
            switch (state_) {
                case kExpectObjectStart:
                    state_ = kExpectKeyOrObjectEnd;
                    return true;
                default:
                    return false;
            }
        }
        
        bool Key(const char* str, SizeType length, bool) {
            switch (state_) {
                case kExpectKeyOrObjectEnd:
                    keyword_ = string(str, length);
                    state_ = kExpectStartList;
                    return true;
                default:
                    return false;
            }
        }
        
        bool StartArray() {
            switch(state_) {
                case kExpectStartList:
                    state_ = kExpectFirstValue;
                    return true;
                default:
                    return false;
                    
            }
        }
        
        bool Uint(unsigned i) {
            switch (state_) {
                case kExpectFirstValue:
                    ids_.push_back(i);
                    state_ = kExpectValueOrEndArray;
                    return true;
                case kExpectValueOrEndArray:
                    ids_.push_back(i);
                    return true;
                default:
                    return false;
            }
        }
        
        bool EndArray(SizeType elementCount) {
            switch(state_){
                case kExpectValueOrEndArray:
                    record_.keyword = keyword_;
                    record_.identifiers = ids_;
                    state_ = kExpectKeyOrObjectEnd;

                    callFunctionsList(keyword_, ids_);
                    
                    keyword_.clear();
                    ids_.clear();
                    return true;
                default:
                    return false;
            }
        }
        
        bool EndObject(SizeType) {
            return state_ == kExpectKeyOrObjectEnd;
        }
        
        bool Default() {
            return false;
        } // All other events are invalid.
        
        enum State {
            kExpectObjectStart,
            kExpectKeyOrObjectEnd,
            kExpectStartList,
            kExpectFirstValue,
            kExpectValueOrEndArray,
        } state_;
        
        Record record_;
        string keyword_;
        list<unsigned> ids_;
    };
};



#endif
