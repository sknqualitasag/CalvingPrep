#ifndef CalvingDataMap_h
#define CalvingDataMap_h
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include "calvingData.h"
#include "animalMap.h"
#include "util.h"
#include "date.h"




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


  // functions for reading calving-data-file
  string getFileName(unsigned i, string name);
  void inputCalvingData(string fname, animalMap  &AMap, int lastYearToConsiderData);
  // functions to verify, transform, set, calculate before put in constructor
  string getVerifiedTvdNr(string id);
  string verifyBreed(string breedstr, string indstr);
  string verifySexBirth(string sexstr, string indstr);
  double verifyBirthWeight(string birthweightstr, string indstr);
  string verifyMultiple(string multiplesstr, string indstr);
  int verifyAbort(string abortstr, string indstr);
  int verifyCalvingscore(string calvingscorestr, string indstr);
  int verifyStillbirth(string stillbirthstr, date calvingdate, string idstr);
  int verifyPrematurity(string prematuritystr, string indstr);
  string verifySireBreed(string fbreedstr, string fstr);
  string verifyHerd(string herdstr, string indstr);
  string verifyMandate(string mandatestr, string idstr);
  int verifyLactationNumber(string lactnumberstr, string indstr);
  int verifyET(string ETstr, string idstr);
  int verifyRecordTypIns(string recordtypinsemstr, string idstr);
  int verifySpermaTraitment(string spermatraitmentstr, string idstr);
  string verifyAnimNr(string animIDstr, string idstr);
  string getVerifiedITBNr(string itb, string indstr);



};


#endif
