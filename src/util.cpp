#include <time.h>
#include <cmath>
#include <string>
#include <iostream>
#include "util.h"
#define IGREG (15 + 31L * (10 + 12L * 1582))
#include <algorithm>

using namespace std;


void Tokenizer::getTokens(const string &str, const string &sep){
  clear();
  string::size_type begidx,endidx;
  begidx = str.find_first_not_of(sep);
  while (begidx != string::npos) {
    endidx = str.find_first_of(sep,begidx);
    if (endidx == string::npos) endidx = str.length();
    push_back(str.substr(begidx,endidx - begidx));
    begidx = str.find_first_not_of(sep,endidx);
  }
}

string Tokenizer::processSemikolon(string &str){
  string newStr;
  for(unsigned l=1; l<str.size()-1; l++) {
    if(l==1) newStr = str[0];
    if(str[l] == ';'){
      if(str[l-1] ==';'){
        newStr+="-9999;";
      }
      else {
        newStr+=";";
      }
    }
    else {
      newStr+=str[l];
    }
  }
  if(newStr[newStr.size()-1] == ';'){
    newStr+="-9999";
  }

  return newStr;
}
