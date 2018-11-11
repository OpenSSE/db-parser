#ifndef DBParserJSON_h
#define DBParserJSON_h

#include <cstdio>
#include <iostream>
#include <list>
#include <sse/dbparser/DBParser.h>
#include <stdio.h>

namespace sse {
namespace dbparser {

class DBParserJSON : public DBParser {
public:
  DBParserJSON(const char *filename);
  DBParserJSON(const std::string &filename);
  void parse();
  bool parsed();

private:
  bool parsed_ = false;

  struct MessageHandler;
};

} // namespace dbparser
} // namespace sse

#endif
