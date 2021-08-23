#ifndef herd_h
#define herd_h
#include <set>
#include <sstream>
#include <vector>
#include <map>
#include "statistic.h"
#include "statisticHYS.h"


using namespace std;

class herd{
public:

  string herdIdStr, herdyearIdStr;
  herd();
  void increment(int transformedCalvingScoreInt, int birthWeightInt);
  void incrementHYS(string herdStr, string YearStr, string sireStr);

  map<string,statisticHYS*> HerdYearStatistic;
//  map<string,int> HerdYearStatistic;
  map<string,statistic*> HerdStatistic;


};



#endif
