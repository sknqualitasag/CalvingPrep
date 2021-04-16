#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <sstream>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <cstring>
#include "calvingData.h"
#include "date.h"
#include "constants.h"
#include <plog/Log.h>
#include <plog/Formatters/MessageOnlyFormatter.h>



using namespace std;


calvingData::calvingData(string idstr, string idbreedstr, string mstr, string mbreedstr, string mvbreedstr, string idsexstr,\
                         date pmbirthdate, date pcalvingdate, double idbirthweightdbl, string multiplestr, \
                         int calvingscoreint, int transformedcalvingscoreint, int stillbirthint, \
                         int prematurebirthint, string geneticmotherstr, string fstr, string fbreedstr, string herdstr, \
                         string mandatestr, int lnint, date pinsemmotherstartdate, date pinsemmotherenddate, \
                         string psRunningMode, string breedCombstr, bool psourceMKS, long int pgestationLengthInDays,\
                         long int pcalvingAgeInDays, long int pcalvingIntervalInDays, long int pfirstCalvingAgeInDays, \
                         string sourceBeefOrDairystr, int spermatraitmentint, int recordtypinsemint, \
                         string animIDstr, string itbIDstr, string damIDstr, string sireIDstr){

  psRunningModeStr = psRunningMode;

  // Initializing Code for fixed effect
  sexCode = -1;
  herdYearCode = -1;
  yearCode = -1;
  yearMonthCode = -1;
  breedLNCode = -1;
  LNAgeCode = -1;

  idStr = idstr;
  constructorDebug("constructor calvingData()_Constructor called with idStr", idStr, psRunningMode);

  idBreedStr = idbreedstr;
  constructorDebug("constructor calvingData()_idBreedStr " + idBreedStr, idStr, psRunningMode);

  damStr = mstr;
  constructorDebug("constructor calvingData()_damStr " + damStr, idStr, psRunningMode);

  damBreedStr = mbreedstr;
  constructorDebug("constructor calvingData()_damBreedStr " + damBreedStr, idStr, psRunningMode);

  mgsBreedStr = mvbreedstr;
  constructorDebug("constructor calvingData()_mgsBreedStr " + mgsBreedStr, idStr, psRunningMode);

  idSexStr = idsexstr;
  constructorDebug("constructor calvingData()_idSexStr " + idSexStr, idStr, psRunningMode);

  mbirthdate = pmbirthdate;
  constructorDebug("constructor calvingData()_mbirthdate.YearInt " + to_string(mbirthdate.YearInt), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_mbirthdate.YearStr " + mbirthdate.YearStr, idStr, psRunningMode);
  constructorDebug("constructor calvingData()_mbirthdate.MonthInt " + to_string(mbirthdate.MonthInt), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_mbirthdate.MonthStr " + mbirthdate.MonthStr, idStr, psRunningMode);
  constructorDebug("constructor calvingData()_mbirthdate.DayInt " + to_string(mbirthdate.DayInt), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_mbirthdate.DayStr " + mbirthdate.DayStr, idStr, psRunningMode);
  constructorDebug("constructor calvingData()_mbirthdate.DateInDays " + to_string(mbirthdate.DateInDays), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_mbirthdate.isValid " + to_string(mbirthdate.isValid), idStr, psRunningMode);

  calvingdate = pcalvingdate;
  constructorDebug("constructor calvingData()_calvingdate.YearInt " + to_string(calvingdate.YearInt), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_calvingdate.YearStr " + calvingdate.YearStr, idStr, psRunningMode);
  constructorDebug("constructor calvingData()_calvingdate.MonthInt " + to_string(calvingdate.MonthInt), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_calvingdate.MonthStr " + calvingdate.MonthStr, idStr, psRunningMode);
  constructorDebug("constructor calvingData()_calvingdate.DayInt " + to_string(calvingdate.DayInt), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_calvingdate.DayStr " + calvingdate.DayStr, idStr, psRunningMode);
  constructorDebug("constructor calvingData()_calvingdate.DateInDays " + to_string(calvingdate.DateInDays), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_calvingdate.isValid " + to_string(calvingdate.isValid), idStr, psRunningMode);

  birthWeightDbl=idbirthweightdbl;
  constructorDebug("constructor calvingData()_birthWeightDbl " + to_string(birthWeightDbl), idStr, psRunningMode);

  multipleStr = multiplestr;
  constructorDebug("constructor calvingData()_multipleStr " + multipleStr, idStr, psRunningMode);



}


// simple debug File
void calvingData::constructorDebug(string message, string tvdid, string psRunningMode){
  string localRunningMode = psRunningMode;
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}
