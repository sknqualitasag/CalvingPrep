#ifndef AnimalMap_h
#define AnimalMap_h
#include <string>
#include "animal.h"
#include "calvingData.h"


using namespace std;


class animalMap : public map<string, animal*>{

public:

  animalMap();
  void addAnimal(calvingData *ptr);

  // Debugging function
  void constructorDebug(string message, string tvdid, string psRunningMode);

};


#endif
