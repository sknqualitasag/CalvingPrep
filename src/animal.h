#ifndef Animal_h
#define Animal_h
#include <string>
#include "calvingData.h"
#include "date.h"



using namespace std;

class animal {
public:

  string psRunningModeStr, idStr, idBreedStr, damStr, damBreedStr, sireStr, sireBreedStr, sexStr;
  int idCode, sireCode, damCode;
  date birthdate;

  animal(calvingData *ptr);

  void constructorDebug(string message, string tvdid, string psRunningMode);

};



#endif
