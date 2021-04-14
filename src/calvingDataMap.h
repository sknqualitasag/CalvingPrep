#ifndef CalvingDataMap_h
#define CalvingDataMap_h
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>



using namespace std;


class calvingDataMap : public map<string, calvingData*> {

public:
  calvingDataMap(void);

};


#endif
