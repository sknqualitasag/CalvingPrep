#ifndef AnimalMap_h
#define AnimalMap_h
#include <string>
#include "animal.h"
#include "calvingData.h"


using namespace std;


class animalMap : public map<string, animal*>{

public:

  animalMap();

};


#endif
