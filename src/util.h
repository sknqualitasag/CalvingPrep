#ifndef Util_h
#define Util_h
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

long julDate(string yyyy, string mm, string dd);

class Tokenizer:public vector<string> {
public:
  void getTokens(const string &str, const string &sep);
  string processSemikolon(string &str);
};


#endif
