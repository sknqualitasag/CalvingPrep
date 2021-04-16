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
