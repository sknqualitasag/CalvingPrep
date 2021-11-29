#ifndef PedMap_h
#define PedMap_h
#include <set>
#include <sstream>
#include <vector>
#include <map>
#include "ped.h"

using namespace std;

class pedMap : public map<string,ped*>{

private:

  string runningMode;

public:

  pedMap(void);
  void makeReadableRRTDMPedigree(string ipedfile, string opedfile);

};

#endif
