#ifndef CalvingData_h
#define CalvingData_h
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include "date.h"


using namespace std;


class calvingData {
public:
  // running mode indicating whether debug information should be printed or not
  string runningMode, psRunningModeStr;
  void constructorDebug(string message, string tvdid, string psRunningMode);

  int sexCode, yearMonthCode, breedcombCode;
  int calvingScoreInt, transformedCalvingScoreInt, stillbirthInt, transformedStillbirthInt, prematurityInt;
  int lnInt, spermaTraitmentInt, recordTypInsemInt;
  long int gestationLengthInDays, calvingAgeInDays, calvingIntervalInDays, firstCalvingAgeInDays;
  string idStr, idBreedStr, damStr, damBreedStr, mgsBreedStr, idSexStr, multipleStr;
  string geneticDamStr, sireStr, sireBreedStr, herdStr, mandateStr, breedCombStr;
  string sourceBeefOrDairyStr, animIDStr, itbIDStr, damIDStr, sireIDStr;
  date mbirthdate, calvingdate, insemmotherstartdate, insemmotherenddate;
  double birthWeightDbl;
  bool sourceMKS;



  calvingData(string idstr, string idbreedstr, string mstr, string mbreedstr, string mvbreedstr, string idsexstr,\
              date pmbirthdate, date pcalvingdate, double idbirthweightdbl, string multiplestr,\
              int calvingscoreint, int transformedcalvingscoreint, int stillbirthint, int transformedstillbirthint,\
              int prematurebirthint, string geneticmotherstr, string fstr, string fbreedstr, string herdstr,\
              string mandatestr, int lnint, date pinsemmotherstartdate, date pinsemmotherenddate,\
              string psRunningMode, string breedCombstr, bool psourceMKS, long int pgestationLengthInDays,\
              long int pcalvingAgeInDays, long int pcalvingIntervalInDays, long int pfirstCalvingAgeInDays,\
              string sourceBeefOrDairystr, int spermatraitmentint,int recordtypinsemint,\
              string animIDstr, string itbIDstr, string damIDstr, string sireIDstr);

};


#endif
