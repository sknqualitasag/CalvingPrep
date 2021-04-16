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




}


// simple debug File
void calvingData::constructorDebug(string message, string tvdid, string psRunningMode){
  string localRunningMode = psRunningMode;
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}
