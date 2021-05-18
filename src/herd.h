#ifndef herd_h
#define herd_h
#include <set>
#include <sstream>
#include <vector>
#include <map>
#include "statistic.h"


using namespace std;

class herd{
public:

  string herdIdStr;
  herd();
  void increment(double birthWeightDbl);

  map<string,int> HerdYearStatistic;
  map<string,statistic*> HerdStatistic;


};



#endif
