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
#include "herd.h"
#include "sire.h"




using namespace std;


class calvingDataMap : public map<string, calvingData*> {

public:
  calvingDataMap(void);
  set<string> dummySires, offspringIds, offspringIdsToDelete;

  // functions for debugging
  void setRunningMode(string psRunningMode);
  string getRunningMode();
  void simpleDebug(string message, string tvdid);
  void outputDebug(string message, string tvdid);
  // running mode indicating whether debug information should be printed or not
  string runningMode;


  // functions for reading calving-data-file
  string getFileName(unsigned i, string name);
  void inputCalvingData(string fname, animalMap  &AMap, int lastYearToConsiderData);
  // Verification function of the reading fields
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
  // Second verification functions
  date verifyCalvingDate(date calvingdate, string idstr);
  date verifyInsemStart(date insemmotherstartdate, string idstr);
  date verifyInsemEnd(date insemmotherenddate, string idstr);
  int verifyInteractStillbirthDeathcalfdate(int stillbirthint, date deathcalfdate, date calvingdate, string idstr);
  // function for setting a new field in dependency to other already declared fields
  bool setSourceVMS(string mandatestr, string idstr);
  string setBreedComb(string mbreedstr, string fbreedstr, string idstr);
  string setSourceBeefOrDairy(string mbreedstr, string idstr);
  // Calculate a new field in dependency with other already declared fields
  long int calculateGL(date insemmotherstartdate, date insemmotherenddate, date calvingdate, string idstr);
  long int calculateCalvingAge(date calvingdate, date mbirthdate, int lnint, string idstr);
  long int calculateCalvingInterval(date calvingdate, date calfbefore_calvingdate, string idstr);
  long int calculateFirstCalvingAge(date mbirthdate, date firstcalvingdate, string idstr);
  // Verification of calculate fields
  long int verifyGL(long int gestationLength, string idstr);
  long int verifyCalvingAge(long int calvingAgeInDays, int laktNrDamInt, string idstr);
  long int verifyIV(long int calvingIntervalInDays, string idstr);
  long int verifyFirstAge(long int firstCalvingAgeInDays, string idstr);
  int verifyInteractLnIV(int lnint, long int calvingIntervalInDays, string idstr);

  // Transform field by creating a new field
  int transformCalvingScore(int calvingscoreint, string idstr);
  int transformStillbirth(int stillbirthint, string idstr);


  // Check number observation in herd.year
  void countHerdYear();
  herd herdYearID;
  void purgeHerdYear();
  // Calculate variance in herd
  void countHerd();
  map<string, herd*> HerdStatisticMap;
  void stdHerd();
  void purgeHerd();


  // Check number observation per sire
  void countSire();
  sire sireID;
  void purgeSire();


  // Draw a sample of data based on herds
  void drawHerd(unsigned proportion, unsigned seed);


  //Coding the effects
  unsigned numSexes, numYearMonth, numBreedCombination;
  void codeEffects();
  void codeSex(void);
  void codeYearMonth(void);
  void codeBreedCombination(void);



  //output function
  void pheno_out();





};


#endif
