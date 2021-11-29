#ifndef Ped_h
#define Ped_h
#include <set>
#include <sstream>
#include <vector>
#include <map>
#include "date.h"



using namespace std;


class ped{
public:
  string indnumStr, sirenumStr, damnumStr, indITB18Str, indTVDstr, indRaceStr, indITBRaceStr, sireRaceStr, damRaceStr;
  date indBirthdate;
  ped(string indnumstr, string sirenumstr, string damnumstr, string itbidstr, string indstr, date indbirthdatestr, string indbreedstr, string inditbbreedstr, string sirebreedstr, string dambreedstr);

};


#endif
