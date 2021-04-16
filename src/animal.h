#ifndef Animal_h
#define Animal_h
#include <string>
#include "calvingData.h"
#include "date.h"



using namespace std;

class animal {
public:

  string psRunningModeStr;
  int idCode, sireCode, damCode;

  animal(calvingData *ptr);

};



#endif
