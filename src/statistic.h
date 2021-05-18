#ifndef Statistic_h
#define Statistic_h
#include <set>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class statistic{
public:
  string trait;
  unsigned ObsPerHerd;
  double Sum;
  double Std;
  double Quadriert;
  statistic();
};

#endif

