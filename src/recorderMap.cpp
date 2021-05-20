#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include "recoderMap.h"
#include "constants.h"


using namespace std;


recoderMap::recoderMap(){}


int recoderMap::code(string s, string missing_value_code){
  if(s != missing_value_code){
    typename map<string,effectclass*>::iterator mapit = this->find(s);
    if(mapit == this->end()){
      effectclass *ptr;
      ptr = new effectclass(++Count);
      (*this)[s] = ptr;
      return Count;
    }
    else {
      effectclass *ptr = (*mapit).second;
      ptr->number++;
      return ((*mapit).second)->name;
    }
  }
  else{
    missing++;
    return -9999;
  }
}


void recoderMap::displayCodes(void){
  typename recoderMap::iterator it;
  unsigned rec = 0, num =0;
  for (it=this->begin(); it!=this->end();it++){
    rec++;
    std::cout << "\nEffect Key = "<<(*it).first << " Effect Code = " << ((*it).second)->name <<" Number of obs for Effect = "<<((*it).second)->number<< std::endl;
    num+=((*it).second)->number;
  }
  std::cout << "\nMissing Values (not coded) = "<<missing<< std::endl;
  std::cout << "Number of different effect classes = "<<rec<< std::endl;
  std::cout << "Total number of obs in all effect classes = "<<num<< std::endl;
}


void recoderMap::toCSV(string csvfilename){

  ofstream csvfile(csvfilename.c_str());

  if(!csvfile){
    cout<< "output(): Cannot open file "<<csvfilename<<std::endl;
  }

  typename recoderMap::iterator it;
  unsigned rec = 0, num =0;

  csvfile<<"EffectKey;EffectCode;NObs"<<std::endl;

  for (it=this->begin(); it!=this->end();it++){
    rec++;
    csvfile <<(*it).first << ";" << ((*it).second)->name <<";"<<((*it).second)->number<< std::endl;
    num+=((*it).second)->number;
  }

}
