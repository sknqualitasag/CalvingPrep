#ifndef CalvingDataMap_h
#define CalvingDataMap_h
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include "calvingData.h"




using namespace std;


class calvingDataMap : public map<string, calvingData*> {

public:
  calvingDataMap(void);

  // functions for debugging
  void setRunningMode(string psRunningMode);
  string getRunningMode();
  void simpleDebug(string message, string tvdid);
  // running mode indicating whether debug information should be printed or not
  string runningMode;

};


#endif
