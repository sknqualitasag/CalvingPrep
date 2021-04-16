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

  int sexCode, herdYearCode, yearCode, yearMonthCode, breedLNCode, LNAgeCode;
  int calvingScoreInt, transformedCalvingScoreInt, stillbirthInt, prematurityInt;
  int lnInt;
  long int gestationLengthInDays;
  string idStr, idBreedStr, damStr, damBreedStr, mgsBreedStr, idSexStr, multipleStr;
  string geneticDamStr, sireStr, sireBreedStr, herdStr, mandateStr, breedCombStr;
  date mbirthdate, calvingdate, insemmotherstartdate, insemmotherenddate;
  double birthWeightDbl;
  bool sourceMKS;



  calvingData(string idstr, string idbreedstr, string mstr, string mbreedstr, string mvbreedstr, string idsexstr,\
              date pmbirthdate, date pcalvingdate, double idbirthweightdbl, string multiplestr,\
              int calvingscoreint, int transformedcalvingscoreint, int stillbirthint,\
              int prematurebirthint, string geneticmotherstr, string fstr, string fbreedstr, string herdstr,\
              string mandatestr, int lnint, date pinsemmotherstartdate, date pinsemmotherenddate,\
              string psRunningMode, string breedCombstr, bool psourceMKS, long int pgestationLengthInDays,\
              long int pcalvingAgeInDays, long int pcalvingIntervalInDays, long int pfirstCalvingAgeInDays,\
              string sourceBeefOrDairystr, int spermatraitmentint,int recordtypinsemint,\
              string animIDstr, string itbIDstr, string damIDstr, string sireIDstr);

};


#endif
