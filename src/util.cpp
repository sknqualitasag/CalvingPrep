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

long julDate(string yyyy, string mm, string dd){

  int year, month, day;

  //     cout<<yyyymmdd<<endl;

  if(yyyy != "-9999" && mm != "-9999" && dd != "-9999" ){
    if(yyyy.size() != 4) return -9999;

    year = atoi(yyyy.c_str());                //Converting to integer


    month = atoi(mm.c_str());               //Converting to integer
    if(month>12 || month<1) return -9999;

    day = atoi(dd.c_str());                  //Converting to integer
    if(day>31 || day<1) return -9999;

    long int jul;
    int ja, jy=year,jm;
    if(jy == 0) {
      cout<<"ERROR in jul_date: There is no year 0, setting date to missing \n";
      return(-9999);
    }
    if(jy < 0) ++jy;
    if(month > 2) {
      jm = month+1;
    }
    else{
      --jy;
      jm = month + 13;
    }

    jul = (long) (floor(365.25*jy) + floor(30.6001*jm) + day + 1720995);
    if(day + 31L * (month + 12L * year) >= IGREG) {
      ja = (int)(0.01*jy);
      jul += 2 - ja + (int) (0.25*ja);
    }
    //       cout<<jul<<endl;
    return(jul);

  }
  else return(-9999);
};
