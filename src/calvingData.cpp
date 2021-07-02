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
                         int calvingscoreint, int transformedcalvingscoreint, int stillbirthint, int transformedstillbirthint, \
                         int prematurebirthint, string geneticmotherstr, string fstr, string fbreedstr, string herdstr, \
                         string mandatestr, int lnint, date pinsemmotherstartdate, date pinsemmotherenddate, \
                         string psRunningMode, string breedCombstr, bool psourceMKS, long int pgestationLengthInDays,\
                         long int pcalvingAgeInDays, long int pcalvingIntervalInDays, long int pfirstCalvingAgeInDays, \
                         string sourceBeefOrDairystr, int spermatraitmentint, int recordtypinsemint, \
                         string animIDstr, string itbIDstr, string damIDstr, string sireIDstr){

  psRunningModeStr = psRunningMode;

  // Initializing Code for fixed effect
  sexCode = -1;
  yearMonthCode = -1;
  breedcombCode = -1;
  nestedDamBreedLNCode = -1;
  LNAgeCode = -1;
  herdYearCode = -1;
  herdCode = -1;
  PECode = -1;
  sireCode = -1;
  mandantCode = -1;

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

  calvingScoreInt = calvingscoreint;
  constructorDebug("constructor calvingData()_calvingScoreInt " + to_string(calvingScoreInt), idStr, psRunningMode);

  transformedCalvingScoreInt = transformedcalvingscoreint;
  constructorDebug("constructor calvingData()_transformedCalvingScoreInt " + to_string(transformedCalvingScoreInt), idStr, psRunningMode);

  stillbirthInt = stillbirthint;
  constructorDebug("constructor calvingData()_stillbirthInt " + to_string(stillbirthInt), idStr, psRunningMode);

  transformedStillbirthInt = transformedstillbirthint;
  constructorDebug("constructor calvingData()_transformedStillbirthInt " + to_string(transformedStillbirthInt), idStr, psRunningMode);

  prematurityInt = prematurebirthint;
  constructorDebug("constructor calvingData()_prematurityInt " + to_string(prematurityInt), idStr, psRunningMode);

  geneticDamStr = geneticmotherstr;
  constructorDebug("constructor calvingData()_geneticDamStr " + geneticDamStr, idStr, psRunningMode);

  sireStr = fstr;
  constructorDebug("constructor calvingData()_sireStr " + sireStr, idStr, psRunningMode);

  sireBreedStr = fbreedstr;
  constructorDebug("constructor calvingData()_sireBreedStr " + sireBreedStr, idStr, psRunningMode);

  herdStr = herdstr;
  constructorDebug("constructor calvingData()_herdStr " + herdStr, idStr, psRunningMode);

  mandateStr = mandatestr;
  constructorDebug("constructor calvingData()_mandateStr " + mandateStr, idStr, psRunningMode);

  lnInt = lnint;
  constructorDebug("constructor calvingData()_lnInt " + to_string(lnInt), idStr, psRunningMode);

  insemmotherstartdate = pinsemmotherstartdate;
  constructorDebug("constructor calvingData()_insemmotherstartdate.YearInt " + to_string(insemmotherstartdate.YearInt), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherstartdate.YearStr " + insemmotherstartdate.YearStr, idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherstartdate.MonthInt " + to_string(insemmotherstartdate.MonthInt), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherstartdate.MonthStr " + insemmotherstartdate.MonthStr, idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherstartdate.DayInt " + to_string(insemmotherstartdate.DayInt), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherstartdate.DayStr " + insemmotherstartdate.DayStr, idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherstartdate.DateInDays " + to_string(insemmotherstartdate.DateInDays), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherstartdate.isValid " + to_string(insemmotherstartdate.isValid), idStr, psRunningMode);

  insemmotherenddate = pinsemmotherenddate;
  constructorDebug("constructor calvingData()_insemmotherenddate.YearInt " + to_string(insemmotherenddate.YearInt), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherenddate.YearStr " + insemmotherenddate.YearStr, idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherenddate.MonthInt " + to_string(insemmotherenddate.MonthInt), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherenddate.MonthStr " + insemmotherenddate.MonthStr, idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherenddate.DayInt " + to_string(insemmotherenddate.DayInt), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherenddate.DayStr " + insemmotherenddate.DayStr, idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherenddate.DateInDays " + to_string(insemmotherenddate.DateInDays), idStr, psRunningMode);
  constructorDebug("constructor calvingData()_insemmotherenddate.isValid " + to_string(insemmotherenddate.isValid), idStr, psRunningMode);

  breedCombStr = breedCombstr;
  constructorDebug("constructor calvingData()_breedCombStr " + breedCombStr, idStr, psRunningMode);

  sourceMKS = psourceMKS;
  constructorDebug("constructor calvingData()_sourceMKS " + to_string(sourceMKS), idStr, psRunningMode);

  gestationLengthInDays = pgestationLengthInDays;
  constructorDebug("constructor calvingData()_gestationLengthInDays " + to_string(gestationLengthInDays), idStr, psRunningMode);

  calvingAgeInDays = pcalvingAgeInDays;
  constructorDebug("constructor calvingData()_calvingAgeInDays " + to_string(calvingAgeInDays), idStr, psRunningMode);

  calvingIntervalInDays = pcalvingIntervalInDays;
  constructorDebug("constructor calvingData()_calvingIntervalInDays " + to_string(calvingIntervalInDays), idStr, psRunningMode);

  firstCalvingAgeInDays = pfirstCalvingAgeInDays;
  constructorDebug("constructor calvingData()_firstCalvingAgeInDays " + to_string(firstCalvingAgeInDays), idStr, psRunningMode);

  sourceBeefOrDairyStr = sourceBeefOrDairystr;
  constructorDebug("constructor calvingData()_sourceBeefOrDairyStr " + sourceBeefOrDairyStr, idStr, psRunningMode);

  spermaTraitmentInt = spermatraitmentint;
  constructorDebug("constructor calvingData()_spermatraitmentInt " + to_string(spermaTraitmentInt), idStr, psRunningMode);

  recordTypInsemInt = recordtypinsemint;
  constructorDebug("constructor calvingData()_recordTypInsemInt " + to_string(recordTypInsemInt), idStr, psRunningMode);

  animIDStr = animIDstr;
  constructorDebug("constructor calvingData()_animIDStr " + animIDStr, idStr, psRunningMode);

  itbIDStr = itbIDstr;
  constructorDebug("constructor calvingData()_itbIDStr " + itbIDStr, idStr, psRunningMode);

  damIDStr = damIDstr;
  constructorDebug("constructor calvingData()_damIDStr " + damIDStr, idStr, psRunningMode);

  sireIDStr = sireIDstr;
  constructorDebug("constructor calvingData()_sireIDStr " + sireIDStr, idStr, psRunningMode);

}


// simple debug File
void calvingData::constructorDebug(string message, string tvdid, string psRunningMode){
  string localRunningMode = psRunningMode;
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}
