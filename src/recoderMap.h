#ifndef Recoder_H
#define Recoder_H
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
#include "effectclass.h"


using namespace std;

class recoderMap : public map<string, effectclass*> {

public:
  unsigned Count;
  unsigned missing;

  recoderMap();
  int code(string s, string missing_value_code);
  void displayCodes(void);
  void toCSV(string csvfilename);

};

#endif
