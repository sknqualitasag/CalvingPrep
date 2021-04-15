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
#include <set>
#include "util.h"
#include <cstring>
#include "calvingDataMap.h"
#include "calvingData.h"
#include <plog/Log.h>
#include "constants.h"
#include "date.h"



using namespace std;

calvingDataMap::calvingDataMap(){

  cout<<"\ncalvingDataMap(): calvingDataMap "<<endl;
  cout<<"*****************************************************************"<< endl;

  // dummySires content male and female to skip
  dummySires.insert("CH900080500000");//-
  dummySires.insert("CH900080700000");// FLHB/HBBV LM M
  dummySires.insert("CH900087000000");//-
  dummySires.insert("CH900900000000");//-
  dummySires.insert("CH900900600008");// FLHB/HBBV OB M
  dummySires.insert("CH900080400000");//-
  dummySires.insert("CH110804000013");// CHAROLAIS-NH M
  dummySires.insert("CH110804000020");// ** F
  dummySires.insert("CH110805000012");// ANGUS-NHB M
  dummySires.insert("CH110805000029");// ** F
  dummySires.insert("CH110807000010");// LIMOUSIN-NHB M
  dummySires.insert("CH110807000027");// LIMOUSIN-NHB F
  dummySires.insert("CH110808000019");// BLONDE-D-NHB M
  dummySires.insert("CH110808000026");// ** F
  dummySires.insert("CH110809000018");// BLEU BEL-NHB M
  dummySires.insert("CH110809000025");// ** F
  dummySires.insert("CH110810000014");// ERINGER-NHB M
  dummySires.insert("CH110810000021");// ERINGER F
  dummySires.insert("CH110811000013");// ROTFLECK-NHB M
  dummySires.insert("CH110811000020");// ROTFLECK F
  dummySires.insert("CH110811000037");// SIMMENTA-NHB M
  dummySires.insert("CH110811000044");// SIMMENTALER F
  dummySires.insert("CH110811000068");// -
  dummySires.insert("CH110811000082");// -
  dummySires.insert("CH110820000011");// FLEISCH M
  dummySires.insert("CH110820000028");// FLEISCH F
  dummySires.insert("CH110825000016");// GRAUVIEH M
  dummySires.insert("CH110825000023");// GRAUVIEH F
  dummySires.insert("CH110827000014");// EVOLENER M
  dummySires.insert("CH110827000021");// EVOLENER F
  dummySires.insert("CH111910000010");// BV-STIER M
  dummySires.insert("CH111910000027");// BV-KUH F
  dummySires.insert("CH111910000034");// OB-STIER M
  dummySires.insert("CH111910000041");// OB-KUH F
  dummySires.insert("CH111910000058");// BS-STIER M
  dummySires.insert("CH111910000065");// BS-KUH F
  dummySires.insert("CH111960000015");// ET-TRAEG. M
  dummySires.insert("CH111960000022");// Scoglio Top TI Schwarzfleck ET-TRAEG. M
  dummySires.insert("CH111995000011");// *UFO* M
  dummySires.insert("CH119005000013");// JERSEY M
  dummySires.insert("CH119005000020");// JERSEYKUH F

  // FIKTIVE FLHB-STIERE (Liste 26.02.2019)
  dummySires.insert("CH900900000006");
  dummySires.insert("CH900900600015");
  dummySires.insert("CH900091900000");
  dummySires.insert("CH900080500006");
  dummySires.insert("CH900900800002");
  dummySires.insert("CH900080800007");
  dummySires.insert("CH900901500000");
  dummySires.insert("CH900080400009");
  dummySires.insert("CH900901900008");
  dummySires.insert("CH900901000005");
  dummySires.insert("CH900900700005");
  dummySires.insert("CH900902400002");
  dummySires.insert("CH900080900004");
  dummySires.insert("CH900900100003");
  dummySires.insert("CH900900900009");
  dummySires.insert("CH900902300005");
  dummySires.insert("CH900902200008");
  dummySires.insert("CH900900200000");
  dummySires.insert("CH900901300006");
  dummySires.insert("CH900901400003");
  dummySires.insert("CH900099000009");
  dummySires.insert("CH900902000004");
  dummySires.insert("CH900901100002");
  dummySires.insert("CH900900400004");
  dummySires.insert("CH900900500001");
  dummySires.insert("CH900087000004");
  dummySires.insert("CH900087000011");
  dummySires.insert("CH900901800001");
  dummySires.insert("CH900901200009");
  dummySires.insert("CH900901700004");
  dummySires.insert("CH900901600007");
  dummySires.insert("CH900902100001");
  dummySires.insert("CH900900300007");

}


// setter for running mode
void calvingDataMap::setRunningMode(string psRunningMode){
  runningMode = psRunningMode;
}


// getter for running mode
string calvingDataMap::getRunningMode(){
  return runningMode;
}


// simple debug File
void calvingDataMap::simpleDebug(string message, string tvdid){
  string localRunningMode = getRunningMode();
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Debug-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}


string calvingDataMap::getFileName(unsigned i, string name){
  string fileName;
  if(i<10){
    fileName = name+"00"+std::to_string(i)+".csv";
  }
  else if(i<100){
    fileName = name+"0"+std::to_string(i)+".csv";
  }
  else if(i<1000){
    fileName = name+std::to_string(i)+".csv";
  }
  else fileName = "Junk";
  return fileName;
}


void calvingDataMap::inputCalvingData(string fname, animalMap  &AMap, int lastYearToConsiderData){

  ifstream datafile(fname.c_str());
  if(!datafile){
    cout<< "inputCalvingData(): Cannot open file "<<fname<<endl;
    exit(8);
  }

  cout<<"\ninputCalvingData(): Reading file "<<fname<<endl;
  cout<<"*****************************************************************"<< endl;


  unsigned sexBirthNotRead=0;
  unsigned calvingMonthNotRead=0;
  unsigned calvingYearNotRead=0;
  unsigned lacationNumberNotRead=0;
  unsigned calvingAgeInDaysNotRead=0;
  unsigned breedCombNotRead=0;
  unsigned herdNotRead=0;
  unsigned sireNotRead=0;
  unsigned mandantNotRead=0;
  unsigned calvingScoreNotRead=0;
  unsigned birthweightNotRead=0;
  unsigned stillbirthNotRead=0;
  unsigned gestationLenghtNotRead=0;



  string sep(";");
  string inputStr;
  unsigned lineNumber=0, numCols, rec=0;
  Tokenizer colData;
  while (getline(datafile,inputStr)){
    string newInputStr = colData.processSemikolon(inputStr);
    cout<<"newInputStr: "<<newInputStr<<endl;
    colData.getTokens(newInputStr,sep);


    for(int i=0; i<colData.size(); i++){
      cout<<"i: "<<i<<" colData : "<<colData[i]<<endl;
    }


    lineNumber++;
    if(lineNumber%200000==0){
      cout<<lineNumber<<" records processed \r";
      cout.flush();
    }
    if(lineNumber==1){
      numCols = colData.size();
      continue;
    }
    else if(colData.size() != numCols){
      cout<<"inputData(): Number of columns on line "<<lineNumber<<" in file "<<fname<<" is "<<colData.size()<<", but the header of the files has "<<numCols<<" labels."<<endl;
      exit(19);
    }


    simpleDebug("inputData()_Input Line inputStr " + inputStr, "");
    string psRunningMode = getRunningMode();


    // Verification for fields as colData
    simpleDebug("inputData()_getVerifiedTvdNr of dam",colData[0]);
    string mstr = getVerifiedTvdNr(colData[0]);
    string mbreedstr = verifyBreed(colData[1],mstr);
    string mvbreedstr = verifyBreed(colData[2],"");
    string idsexstr = verifySexBirth(colData[3],colData[6]);
    simpleDebug("inputData()_Call contructor date for mbirthdate " + colData[4], mstr);
    date mbirthdate = date(colData[4], lastYearToConsiderData, psRunningMode, mstr);
    simpleDebug("inputData()_Call contructor date for calvingdate " + colData[5], colData[6]);
    date calvingdate = date(colData[5], lastYearToConsiderData, psRunningMode, colData[6]);
    simpleDebug("inputData()_getVerifiedTvdNr of animal",colData[6]);
    string idstr = getVerifiedTvdNr(colData[6]);
    string idbreedstr = verifyBreed(colData[7],idstr);
    double idbirthweightdbl = verifyBirthWeight(colData[8],idstr);
    string multiplestr = verifyMultiple(colData[9],idstr);
    int abortint = verifyAbort(colData[10],idstr);
    int calvingscoreint = verifyCalvingscore(colData[11],idstr);
    int stillbirthint = verifyStillbirth(colData[12], calvingdate, idstr);
    int prematurebirthint = verifyPrematurity(colData[13],idstr);
    simpleDebug("inputData()_getVerifiedTvdNr of geneticmother",colData[14]);
    string geneticmotherstr = getVerifiedTvdNr(colData[14]);
    simpleDebug("inputData()_getVerifiedTvdNr of sire",colData[15]);
    string fstr = getVerifiedTvdNr(colData[15]);
    string fbreedstr = verifySireBreed(colData[16], fstr);
    string herdstr = verifyHerd(colData[17], idstr);
    string mandatestr = verifyMandate(colData[18], idstr);
    simpleDebug("inputData()_Call contructor date for insemmotherstartdate " + colData[19], idstr);
    date insemmotherstartdate = date(colData[19], lastYearToConsiderData, psRunningMode, idstr);
    simpleDebug("inputData()_Call contructor date for insemmotherenddate " + colData[20], idstr);
    date insemmotherenddate = date(colData[20], lastYearToConsiderData, psRunningMode, idstr);
    int lnint = verifyLactationNumber(colData[21],idstr);
    simpleDebug("inputData()_Call contructor date for deathmotherdate " + colData[22], idstr);
    date deathmotherdate = date(colData[22], lastYearToConsiderData, psRunningMode, idstr);
    simpleDebug("inputData()_Call contructor date for deathmothertvddate", idstr);
    date deathmothertvddate = date(colData[23], lastYearToConsiderData, psRunningMode, idstr);
    int ETint = verifyET(colData[24], idstr);
    simpleDebug("inputData()_Call contructor date for calfbefore_calvingdate", idstr);
    date calfbefore_calvingdate = date(colData[25], lastYearToConsiderData, psRunningMode, idstr);
    simpleDebug("inputData()_Call contructor date for firstcalvingdate", idstr);
    date firstcalvingdate = date(colData[26], lastYearToConsiderData, psRunningMode, idstr);
    string afterbirthsexstr = colData[27];
    int recordtypinsemint = verifyRecordTypIns(colData[28], idstr);
    string insemnumberstr = colData[29];
    int spermatraitmentint = verifySpermaTraitment(colData[30], idstr);
    string inseminatorstr = colData[31];
    string insemorganisation = colData[32];
    string animIDstr = verifyAnimNr(colData[33], idstr);
    string itbIDstr = getVerifiedITBNr(colData[34], idstr);
    simpleDebug("inputData()_verifyAnimNr of dam",mstr);
    string damIDstr = verifyAnimNr(colData[35], mstr);
    simpleDebug("inputData()_verifyAnimNr of sire",fstr);
    string sireIDstr = verifyAnimNr(colData[36], fstr);
    simpleDebug("inputData()_Call contructor date for deathcalfdate", idstr);
    date deathcalfdate = date(colData[37], lastYearToConsiderData, psRunningMode, idstr);

    // Second verification of declared fields
    calvingdate = verifyCalvingDate(calvingdate,idstr);
    insemmotherstartdate = verifyInsemStart(insemmotherstartdate, idstr);
    insemmotherenddate = verifyInsemEnd(insemmotherenddate, idstr);

    // Set a new field in dependency to other already declared fields
    bool sourceMKS = setSourceVMS(mandatestr, idstr);
    simpleDebug("inputData()_after setSourceVMS, new field sourceMKS is "+to_string(sourceMKS),idstr);
    string breedCombstr = setBreedComb(mbreedstr, fbreedstr, idstr);

    // Calculate a new field in dependency with other already declared fields
    long int gestationLengthInDays = calculateGL(insemmotherstartdate, insemmotherenddate, calvingdate, idstr);
    long int calvingAgeInDays =  calculateCalvingAge(calvingdate, mbirthdate, lnint, idstr);
    long int calvingIntervalInDays = calculateCalvingInterval(calvingdate, calfbefore_calvingdate, idstr);
    long int firstCalvingAgeInDays = calculateFirstCalvingAge(mbirthdate, firstcalvingdate, idstr);

    // Verification of calculate fields
    gestationLengthInDays = verifyGL(gestationLengthInDays, idstr);

    // Transform field by creating a new field
    int transformedcalvingscoreint = transformCalvingScore(calvingscoreint, idstr);


    rec++;
    if(rec%100000==0){
      cout<<rec<<" records processed \r";
      cout.flush();
    }

    set<string>::iterator dsit = dummySires.find(fstr);
    if(dsit!=dummySires.end()){
      fstr = CONSTANTS::STRING_NA;
      simpleDebug("inputData()_sire in dummySires so set sire to missing", idstr);
    }
    dsit = dummySires.find(mstr);
    if(dsit!=dummySires.end()){
      mstr = CONSTANTS::STRING_NA;
      simpleDebug("inputData()_dam in dummySires so set dam to missing", idstr);
    }
    dsit = dummySires.find(idstr);
    if(dsit!=dummySires.end()){
      simpleDebug("inputData()_animal in dummySires so continue", idstr);
      continue;
    }


    if(idsexstr == CONSTANTS::STRING_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because sexbirth is missing", idstr);
      sexBirthNotRead++;
      continue;
    }
    if(calvingdate.MonthStr == CONSTANTS::STRING_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because calvingdate.MonthStr is missing", idstr);
      calvingMonthNotRead++;
      continue;
    }
    if(calvingdate.YearStr == CONSTANTS::STRING_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because calvingdate.YearStr is missing", idstr);
      calvingYearNotRead++;
      continue;
    }
    if(lnint == CONSTANTS::INT_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because lnint is missing", idstr);
      lacationNumberNotRead++;
      continue;
    }
    if(calvingAgeInDays == CONSTANTS::INT_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because calvingAgeInDays is missing", idstr);
      calvingAgeInDaysNotRead++;
      continue;
    }
    if(breedCombstr == CONSTANTS::STRING_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because breedCombstr is missing", idstr);
      breedCombNotRead++;
      continue;
    }
    if(herdstr == CONSTANTS::STRING_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because herdstr is missing", idstr);
      herdNotRead++;
      continue;
    }
    if(fstr == CONSTANTS::STRING_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because fstr is missing", idstr);
      sireNotRead++;
      continue;
    }
    if(mandatestr == CONSTANTS::STRING_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because mandatestr is missing", idstr);
      mandantNotRead++;
      continue;
    }
    if(calvingscoreint == CONSTANTS::INT_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because calvingscoreint is missing", idstr);
      calvingScoreNotRead++;
      continue;
    }
    if(idbirthweightdbl == CONSTANTS::DOUBLE_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because idbirthweightdbl is missing", idstr);
      birthweightNotRead++;
      continue;
    }
    if(stillbirthint == CONSTANTS::INT_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because stillbirthint is missing", idstr);
      stillbirthNotRead++;
      continue;
    }
    if(gestationLengthInDays == CONSTANTS::INT_NA){
      simpleDebug("inputData()_Animal is not read in calvingDataMap, because gestationLengthInDays is missing", idstr);
      gestationLenghtNotRead++;
      continue;
    }







  }

}



string calvingDataMap::getVerifiedTvdNr(string id){

  // check for length of TVD-Nr
  if (id.size() != CONSTANTS::TVD_NR_LENGTH){
    simpleDebug("getVerifiedTvdNr()_Setting id to missing, because TVD_NR_LENGTH is not correct", id);
    return CONSTANTS::STRING_NA;
  }else{
    simpleDebug("getVerifiedTvdNr()_Plausible length of TVD-Nr ", id);
  }

  // check whether first two positions of id are letters
  string countryCode = id.substr(0,CONSTANTS::COUNTRY_CODE_LENGTH);
  // countryCode should not be numeric
  if (strspn(countryCode.c_str(), CONSTANTS::LETTERS) != CONSTANTS::COUNTRY_CODE_LENGTH){
    simpleDebug("getVerifiedTvdNr()_Setting id to missing, because country code are not letters", id);
    return CONSTANTS::STRING_NA;
  }else{
    simpleDebug("getVerifiedTvdNr()_Plausible first two positions of TVD-Nr ", id);
  }

  // check whether second parts is only numeric
  string aniMM = id.substr(CONSTANTS::COUNTRY_CODE_LENGTH);
  // aniMM must be all numbers
  if (strspn(aniMM.c_str(), CONSTANTS::NUMBERS) != (CONSTANTS::TVD_NR_LENGTH - CONSTANTS::COUNTRY_CODE_LENGTH)){
    simpleDebug("getVerifiedTvdNr()_Setting id to missing, because numeric part is not numeric", id);
    return CONSTANTS::STRING_NA;
  }else{
    simpleDebug("getVerifiedTvdNr()_Plausible second numeric part of TVD-Nr ", id);
  }

  return id;
}


string calvingDataMap::verifyBreed(string breedstr, string indstr){

  if(breedstr == "KR") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "KR";
  }
  else if(breedstr =="SI") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "SI";
  }
  else if(breedstr =="SF") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "SF";
  }
  else if(breedstr == "HO") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "HO";
  }
  else if(breedstr =="BV" || breedstr == "BS"){
    simpleDebug("verifyBreed()_Plausible breed (BS will be set to BV) "+breedstr, indstr);
    return "BV";
  }
  else if(breedstr =="OB" || breedstr =="ROB") {
    simpleDebug("verifyBreed()_Plausible breed (ROB will be set to OB) "+breedstr, indstr);
    return "OB";
  }
  else if(breedstr =="JE") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "JE";
  }
  else if(breedstr =="MO") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "MO";
  }
  else if(breedstr =="AN") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "AN";
  }
  else if(breedstr =="AU") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "AU";
  }
  else if(breedstr =="CH") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "CH";
  }
  else if(breedstr =="LM") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "LM";
  }
  else if(breedstr == "HH") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "HH";
  }
  else if(breedstr == "AL") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "AL";
  }
  else if(breedstr =="BD") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "BD";
  }
  else if(breedstr =="SL") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "SL";
  }
  else if(breedstr =="PI") {
    simpleDebug("verifyBreed()_Plausible breed "+breedstr, indstr);
    return "PI";
  }
  else if(breedstr =="HR") { //Eringer
    return "HR";
  }
  else{
    simpleDebug("verifyBreed()_Setting breed to missing, because breed "+breedstr +" is not in the breed list (KR,SI,SF,HO,BV,BS,OB,ROB,JE,MO,AN,AU,CH,LM,HH,AL,BD,SL,PI)", indstr);
    return CONSTANTS::STRING_NA;
  }

}


string calvingDataMap::verifySexBirth(string sexstr, string indstr){
  if(sexstr == "M") {
    simpleDebug("verifySexBirth()_Plausible sexstr "+sexstr, indstr);
    return "M";
  }
  else if(sexstr == "F") {
    simpleDebug("verifySexBirth()_Plausible sexstr "+sexstr, indstr);
    return "F";
  }
  simpleDebug("verifySexBirth()_Setting sexstr to missing, because sex at birth "+sexstr+" is not male/female", indstr);
  return CONSTANTS::STRING_NA;
}


double calvingDataMap::verifyBirthWeight(string birthweightstr, string indstr){
  double bw;
  bw = atoi(birthweightstr.c_str());
  if(bw <= 10. || bw >= 80.) {
    simpleDebug("verifyBirthWeight()_Setting birthweightstr to missing, because birthweightstr "+to_string(bw)+" is bellow 10 or higher 80", indstr);
    bw =  -9999.;
  }else{
    simpleDebug("verifyBirthWeight()_Plausible birthweightstr "+to_string(bw), indstr);
  }

  return bw;
}


string calvingDataMap::verifyMultiple(string multiplesstr, string indstr){

  int multiplesint = atoi(multiplesstr.c_str());
  if(multiplesint < 0 || multiplesint > 1){
    simpleDebug("verifyMultiple()_Setting multiplesstr to missing, because multiplesstr "+multiplesstr+" is bellow 0 or higher 1", indstr);
    return CONSTANTS::STRING_NA;
  }else{
    simpleDebug("verifyMultiple()_Plausible multiplesstr "+multiplesstr, indstr);
  }
  return multiplesstr;
}


int calvingDataMap::verifyAbort(string abortstr, string indstr){

  int abortint = atoi(abortstr.c_str());

  if(abortint < 0 || abortint > 1) {
    simpleDebug("verifyAbort()_Setting abortstr to missing, because abortstr "+abortstr+" is bellow 0 or higher 1", indstr);
    return CONSTANTS::INT_NA;
  }else{
    simpleDebug("verifyAbort()_Plausibel abortstr "+abortstr, indstr);
  }

  return abortint;

}


int calvingDataMap::verifyCalvingscore(string calvingscorestr, string indstr){

  int calvingscoreint = atoi(calvingscorestr.c_str());

  if(calvingscoreint < 1 || calvingscoreint > 4) {
    simpleDebug("verifyCalvingscore()_Setting calvingscorestr to missing, because calvingscorestr "+calvingscorestr+" is bellow 1 or higher 4", indstr);
    return CONSTANTS::INT_NA;
  }else{
    simpleDebug("verifyCalvingscore()_Plausible calvingscorestr "+calvingscorestr, indstr);
  }

  return calvingscoreint;

}


int calvingDataMap::verifyStillbirth(string stillbirthstr, date calvingdate, string idstr){

  int stillbirthint = atoi(stillbirthstr.c_str());

  // Transfer of calving date to TVD since autumn 2005
  if(calvingdate.YearInt>2005) {
    if(stillbirthint < 1 || stillbirthint > 4) {
      simpleDebug("verifyStillbirth()_Setting stillbirthint to missing, because stillbirthint "+to_string(stillbirthint)+" is bellow 1 or higher 4", idstr);
      stillbirthint = CONSTANTS::INT_NA;
    }else{
      simpleDebug("verifyStillbirth()_Plausible stillbirthint "+ to_string(stillbirthint), idstr);
    }
  }
  else {
    simpleDebug("verifyStillbirth()_Setting stillbirthint to missing, because calvingdate.YearInt is bellow 2005", idstr);
    stillbirthint = CONSTANTS::INT_NA;
  }

  return stillbirthint;

}


int calvingDataMap::verifyPrematurity(string prematuritystr, string indstr){

  int prematurityint = atoi(prematuritystr.c_str());
  if(prematurityint < 0 || prematurityint > 1){
    simpleDebug("verifyPrematurity()_Setting prematuritystr to missing, because prematuritystr "+prematuritystr+" is bellow 0 or higher 1", indstr);
    return CONSTANTS::INT_NA;
  }else{
    simpleDebug("verifyPrematurity()_Plausible prematuritystr "+prematuritystr, indstr);
  }
  return prematurityint;
}


string calvingDataMap::verifySireBreed(string fbreedstr, string fstr){

  if(fbreedstr =="SI") {
    simpleDebug("verifySireBreed()_Plausible sire breed "+fbreedstr, fstr);
    return "SI";
  }
  else if(fbreedstr =="OB" || fbreedstr =="ROB") {
    simpleDebug("verifySireBreed()_Plausible sire breed (set ROB to OB) "+fbreedstr, fstr);
    return "OB";
  }
  else if(fbreedstr =="AN") {
    simpleDebug("verifySireBreed()_Plausible sire breed "+fbreedstr, fstr);
    return "AN";
  }
  else if(fbreedstr =="AU") {
    simpleDebug("verifySireBreed()_Plausible sire breed "+fbreedstr, fstr);
    return "AU";
  }
  else if(fbreedstr =="CH") {
    simpleDebug("verifySireBreed()_Plausible sire breed "+fbreedstr, fstr);
    return "CH";
  }
  else if(fbreedstr =="LM") {
    simpleDebug("verifySireBreed()_Plausible sire breed "+fbreedstr, fstr);
    return "LM";
  }
  else if(fbreedstr == "HH") {
    simpleDebug("verifySireBreed()_Plausible sire breed "+fbreedstr, fstr);
    return "HH";
  }
  else if(fbreedstr == "AL") {
    simpleDebug("verifySireBreed()_Plausible sire breed "+fbreedstr, fstr);
    return "AL";
  }
  else if(fbreedstr =="BD") {
    simpleDebug("verifySireBreed()_Plausible sire breed "+fbreedstr, fstr);
    return "BD";
  }
  else if(fbreedstr =="SL") {
    simpleDebug("verifySireBreed()_Plausible sire breed "+fbreedstr, fstr);
    return "SL";
  }
  else if(fbreedstr =="PI") {
    simpleDebug("verifySireBreed()_Plausible sire breed "+fbreedstr, fstr);
    return "PI";
  }
  else{
    simpleDebug("verifySireBreed()_Setting sire breed to missing, because sire breed "+fbreedstr +" is not in the sire breed list (SI,OB,ROB,AN,AU,CH,LM,HH,AL,BD,SL,PI)", fstr);
    return CONSTANTS::STRING_NA;
  }

}


string calvingDataMap::verifyHerd(string herdstr, string idstr){

  if(herdstr ==""){
    simpleDebug("verifyHerd()_Setting herdstr to missing, because herdstr is missing", idstr);
    return CONSTANTS::STRING_NA;
  }else{
    simpleDebug("verifyHerd()_Plausible herdstr "+ herdstr, idstr);
  }

  return herdstr;

}


string calvingDataMap::verifyMandate(string mandatestr, string idstr){

  if(mandatestr != "3230" && mandatestr != "1893" && mandatestr != "2077"){
    simpleDebug("verifyMandate()_Setting mandatestr to missing, because mandatestr is not 3230 or 1893 or 2077 but "+ mandatestr, idstr);
    return CONSTANTS::STRING_NA;
  }else{
    simpleDebug("verifyMandate()_Plausible mandatestr "+ mandatestr, idstr);
    return mandatestr;
  }

}


int calvingDataMap::verifyLactationNumber(string lactnumberstr, string indstr){

  int lactnumberstrint = atoi(lactnumberstr.c_str());
  if(lactnumberstrint<1 || lactnumberstrint>19){
    simpleDebug("verifyLactationNumber()_Setting lactnumberstr to missing, because lactnumberstr "+lactnumberstr+" is bellow 1 or higher 19", indstr);
    return CONSTANTS::INT_NA;
  }else{
    simpleDebug("verifyLactationNumber()_plausible lactnumberstr "+lactnumberstr, indstr);
  }
  return lactnumberstrint;
}


int calvingDataMap::verifyET(string ETstr, string idstr){

  int ETint = atoi(ETstr.c_str());

  if(ETint < 0 || ETint > 1) {
    simpleDebug("verifyET()_Setting ETint to missing, because ETint "+to_string(ETint)+" is bellow 0 or higher 1", idstr);
    return CONSTANTS::INT_NA;
  }else{
    simpleDebug("verifyET()_Plausible ETint "+to_string(ETint), idstr);
  }

  return ETint;

}


int calvingDataMap::verifyRecordTypIns(string recordtypinsemstr, string idstr){

  int recordtypinsemint = atoi(recordtypinsemstr.c_str());

  // Erfassungsart der Belegung, Indexbedeutung gemäss vms-633:
  // 1 = manuelle Erfassung (Sachberarbeiter)
  // 2 = elektronische Erfassung (über redonline, von KBOs)
  // 3 = Erfassung über Geburtsmeldung
  // 4 = intern (Zusammenlegung bei der Migration im 2015 von VMS zu Qualitas)
  // 5 = extern (Sachbearbeiter von Schafen und Ziegen)
  // 6 = Automatischer Eintrag (VMS mit automatische Belegung)
  // 7 = DVS Erfassung (Smartcow)
  if(recordtypinsemint < 0 || recordtypinsemint > 7) {
    simpleDebug("verifyRecordTypIns()_Setting recordtypinsemint to missing, because recordtypinsemstr "+recordtypinsemstr+" is bellow 0 or higher 7", idstr);
    return CONSTANTS::INT_NA;
  }else{
    simpleDebug("verifyRecordTypIns()_Plausible recordtypinsemint "+to_string(recordtypinsemint), idstr);
  }

  return recordtypinsemint;

}


int calvingDataMap::verifySpermaTraitment(string spermatraitmentstr, string idstr){

  int spermatraitmentint = atoi(spermatraitmentstr.c_str());

  // Sperma Behandlungen (Inhalt Sexingmethode)
  // 0 = unbehandelt
  // 1 = gesext, Beltsville-Technologie
  // 2 = bovitel
  // 3 = heifer plus oder bull plus
  // 4 = affirm
  // 5 = spermvital
  // 6 = unbekannte Sexingmethode
  // 7 = Sexcel
  // 8 = SexedULTRA 4M

  if(spermatraitmentint < 0 || spermatraitmentint > 8) {
    simpleDebug("verifySpermaTraitment()_Setting spermatraitmentint to missing, because spermatraitmentint "+to_string(spermatraitmentint)+" is bellow 0 or higher 8", idstr);
    return CONSTANTS::INT_NA;
  }else{
    simpleDebug("verifySpermaTraitment()_Plausible spermatraitmentint "+to_string(spermatraitmentint), idstr);
  }

  return spermatraitmentint;

}


string calvingDataMap::verifyAnimNr(string animIDstr, string idstr){

  if(animIDstr == ""){
    simpleDebug("verifyAnimNr()_Setting animIDstr " + animIDstr +" to missing, because it is empty", idstr);
    return CONSTANTS::STRING_NA;
  }
  // check if it is only numeric
  else if (strspn(animIDstr.c_str(), CONSTANTS::NUMBERS) != animIDstr.length()){
    simpleDebug("verifyAnimNr()_Setting animIDstr " + animIDstr +" to missing, because it is not numeric", idstr);
    return CONSTANTS::STRING_NA;
  }else{
    simpleDebug("verifyAnimNr()_Plausible animIDstr " + animIDstr, idstr);
    return animIDstr;
  }

}


string calvingDataMap::getVerifiedITBNr(string itb, string indstr){

  // check for length of ITB-Nr
  if (itb.size() != CONSTANTS::ITB_NR_LENGTH){
    simpleDebug("getVerifiedITBNr()_Setting itb to missing, because ITB_NR_LENGTH is not correct", indstr);
    return CONSTANTS::STRING_NA;
  }else{
    simpleDebug("getVerifiedITBNr()_Plausible itb considering ITB_NR_LENGTH ", indstr);
  }

  // check whether first six positions of id are letters
  string breedCountrySexCode = itb.substr(0,CONSTANTS::BREED_COUNTRY_SEX_CODE_LENGTH);
  // countryCode should not be numeric
  if (strspn(breedCountrySexCode.c_str(), CONSTANTS::LETTERS) != CONSTANTS::BREED_COUNTRY_SEX_CODE_LENGTH){
    simpleDebug("getVerifiedITBNr()_Setting itb to missing, because first part (breed/country/sex) "+breedCountrySexCode+" are not letters", indstr);
    return CONSTANTS::STRING_NA;
  }else{
    simpleDebug("getVerifiedITBNr()_Plausible itb considering first part (breed/country/sex)", indstr);
  }

  // check whether second parts is only numeric
  string aniMM = itb.substr(CONSTANTS::BREED_COUNTRY_SEX_CODE_LENGTH);
  // aniMM must be all numbers
  if (strspn(aniMM.c_str(), CONSTANTS::NUMBERS) != (CONSTANTS::ITB_NR_LENGTH - CONSTANTS::BREED_COUNTRY_SEX_CODE_LENGTH)){
    simpleDebug("getVerifiedITBNr()_Setting itb to missing, because numeric part "+aniMM+" is not numeric", indstr);
    return CONSTANTS::STRING_NA;
  }else{
    simpleDebug("getVerifiedITBNr()_Plausible itb considering numeric part", indstr);
  }

  return itb;

}


date calvingDataMap::verifyCalvingDate(date calvingdate, string idstr){

  if (calvingdate.YearStr < CONSTANTS::FIRSTYEARDATA){

    simpleDebug("verifyCalvingDate()_Setting calvingdate to missing, because calvingdate.YearStr "+calvingdate.YearStr+" < CONSTANTS::FIRSTYEARDATA "+CONSTANTS::FIRSTYEARDATA, idstr);

    calvingdate.DayInt = CONSTANTS::INT_NA;
    calvingdate.DayStr = CONSTANTS::STRING_NA;
    calvingdate.MonthInt = CONSTANTS::INT_NA;
    calvingdate.MonthStr = CONSTANTS::STRING_NA;
    calvingdate.YearInt = CONSTANTS::INT_NA;
    calvingdate.YearStr = CONSTANTS::STRING_NA;
    calvingdate.isValid = false;
  }else{
    simpleDebug("verifyCalvingDate()_Plausible calvingdate", idstr);
  }

  return calvingdate;

}


date calvingDataMap::verifyInsemStart(date insemmotherstartdate, string idstr){

  if(insemmotherstartdate.YearStr < CONSTANTS::FIRSTYEARDATA-2){

    simpleDebug("verifyInsemStart()_Setting insemmotherstartdate to missing, because insemmotherstartdate.YearStr "+insemmotherstartdate.YearStr+" < CONSTANTS::FIRSTYEARDATA-2 "+(CONSTANTS::FIRSTYEARDATA-2), idstr);

    insemmotherstartdate.DayInt = CONSTANTS::INT_NA;
    insemmotherstartdate.DayStr = CONSTANTS::STRING_NA;
    insemmotherstartdate.MonthInt = CONSTANTS::INT_NA;
    insemmotherstartdate.MonthStr = CONSTANTS::STRING_NA;
    insemmotherstartdate.YearInt  = CONSTANTS::INT_NA;
    insemmotherstartdate.YearStr = CONSTANTS::STRING_NA;
    insemmotherstartdate.isValid = false;
  }else{
    simpleDebug("verifyInsemStart()_Plausible insemmotherstartdate", idstr);
  }

  return insemmotherstartdate;

}


date calvingDataMap::verifyInsemEnd(date insemmotherenddate, string idstr){

  if(insemmotherenddate.YearStr < CONSTANTS::FIRSTYEARDATA-2){

    simpleDebug("verifyInsemEnd()_Setting insemmotherenddate to missing, because insemmotherenddate.YearStr "+insemmotherenddate.YearStr+" < CONSTANTS::FIRSTYEARDATA-2"+(CONSTANTS::FIRSTYEARDATA-2), idstr);

    insemmotherenddate.DayInt = CONSTANTS::INT_NA;
    insemmotherenddate.DayStr = CONSTANTS::STRING_NA;
    insemmotherenddate.MonthInt = CONSTANTS::INT_NA;
    insemmotherenddate.MonthStr = CONSTANTS::STRING_NA;
    insemmotherenddate.YearInt = CONSTANTS::INT_NA;
    insemmotherenddate.YearStr = CONSTANTS::STRING_NA;
    insemmotherenddate.isValid = false;
  }else{
    simpleDebug("verifyInsemEnd()_Plausible insemmotherenddate", idstr);
  }

  return insemmotherenddate;

}


bool calvingDataMap::setSourceVMS(string mandatestr, string idstr){

  if(mandatestr == "3230"){
    simpleDebug("setSourceVMS()_Setting source VMS to true, because mandatestr VMS is 3230 = "+mandatestr, idstr);
    return true;
  }else{
    simpleDebug("setSourceVMS()_Setting source VMS to false, because mandatestr: "+mandatestr, idstr);
    return false;
  }

}


string calvingDataMap::setBreedComb(string mbreedstr, string fbreedstr, string idstr){

  string breedCombstr;

  if(mbreedstr != CONSTANTS::STRING_NA && fbreedstr != CONSTANTS::STRING_NA){
    breedCombstr = fbreedstr + "*" + mbreedstr;
    simpleDebug("setBreedComb()_Setting breedCombstr (father * mother) " + breedCombstr, idstr);
  }else{
    breedCombstr = CONSTANTS::STRING_NA;
    simpleDebug("setBreedComb()_Setting breedCombstr to missing, because fatherbreed ("+fbreedstr+") or motherbreed ("+mbreedstr+") is missing", idstr);
  }

  return breedCombstr;

}


long int calvingDataMap::calculateGL(date insemmotherstartdate, date insemmotherenddate, date calvingdate, string idstr){

  long int gestationLength;

  if(insemmotherstartdate.DateInDays == insemmotherenddate.DateInDays){
    if(insemmotherstartdate.isValid){
      if(calvingdate.DateInDays > 0 && insemmotherstartdate.DateInDays > 0 && insemmotherstartdate.DateInDays < calvingdate.DateInDays){
        gestationLength = calvingdate.DateInDays - insemmotherstartdate.DateInDays;
        simpleDebug("calculateGL()_Calculate gestationLength "+to_string(gestationLength)+" (case insemmotherstartdate=insemmotherenddate, insemmotherstartdate.isValid)", idstr);
      } else {
        simpleDebug("calculateGL()_Setting gestationLength to missing,  (case insemmotherstartdate=insemmotherenddate, insemmotherstartdate.isValid, but not the conditions calvingdate.DateInDays > 0 && insemmotherstartdate.DateInDays > 0 && insemmotherstartdate.DateInDays < calvingdate.DateInDays)", idstr);
        gestationLength = CONSTANTS::INT_NA;
      }
    } else{
      simpleDebug("calculateGL()_Setting gestationLength to missing,  (case insemmotherstartdate=insemmotherenddate, but insemmotherstartdate.isValid false)", idstr);
      gestationLength = CONSTANTS::INT_NA;
    }
  }
  else if(!insemmotherenddate.isValid){
    if(calvingdate.DateInDays > 0 && insemmotherstartdate.DateInDays > 0 && insemmotherstartdate.DateInDays < calvingdate.DateInDays){
      gestationLength = calvingdate.DateInDays - insemmotherstartdate.DateInDays;
      simpleDebug("calculateGL()_Calculate gestationLength "+to_string(gestationLength)+" (case !insemmotherenddate.isValid)", idstr);
    } else {
      simpleDebug("calculateGL()_Setting gestationLength to missing,  (case !insemmotherenddate.isValid, but not the conditions calvingdate.DateInDays > 0 && insemmotherstartdate.DateInDays > 0 && insemmotherstartdate.DateInDays < calvingdate.DateInDays)", idstr);
      gestationLength = CONSTANTS::INT_NA;
    }
  }
  else if(!insemmotherstartdate.isValid){
    simpleDebug("calculateGL()_Setting gestationLength to missing,  (case !insemmotherstartdate.isValid)", idstr);
    gestationLength = CONSTANTS::INT_NA;
  }
  else{
    simpleDebug("calculateGL()_Setting gestationLength to missing", idstr);
    gestationLength = CONSTANTS::INT_NA;
  }

  return gestationLength;

}


long int calvingDataMap::verifyGL(long int gestationLength, string idstr){

  if(gestationLength < 260 || gestationLength > 310){
    simpleDebug("verifyGL()_Setting gestationLength to missing, because gestationLength "+to_string(gestationLength)+" lower than 260 or higher than 310", idstr);
    return CONSTANTS::INT_NA;
  }else{
    simpleDebug("verifyGL()_gestationLength "+to_string(gestationLength)+" is in the range 260>=x<=310", idstr);
    return gestationLength;
  }

}


long int calvingDataMap::verifyCalvingAge(long int calvingAgeInDays, int laktNrDamInt, string idstr){

  int ug = CONSTANTS::MIN_FIRST_AGE_AT_CALVING + (CONSTANTS::MIN_CALVING_INTERVAL*(laktNrDamInt-CONSTANTS::FIRST_LACTATION));
  int og = CONSTANTS::MAX_FIRST_AGE_AT_CALVING + (CONSTANTS::MAX_CALVING_INTERVAL*(laktNrDamInt-CONSTANTS::FIRST_LACTATION));

  simpleDebug("verifyCalvingAge()_calvingAgeInDays "+to_string(calvingAgeInDays)+" with lactationnumber "+to_string(laktNrDamInt)+" should be check with ug: "+to_string(ug)+" and og:"+to_string(og), idstr);

  if(calvingAgeInDays >=ug*CONSTANTS::TRANSFORM_IN_DAYS && calvingAgeInDays <= og*CONSTANTS::TRANSFORM_IN_DAYS){
    simpleDebug("verifyCalvingAge()_calvingAgeInDays "+to_string(calvingAgeInDays)+" is verified", idstr);
    return calvingAgeInDays;

  }
  else{
    simpleDebug("verifyCalvingAge()_calvingAgeInDays is bellow the ug and higher og, so calvingAgeInDays is set to missing", idstr);
    return CONSTANTS::INT_NA;
  }
}


long int calvingDataMap::calculateCalvingAge(date calvingdate, date mbirthdate, int lnint, string idstr){

  long int calvingAge;

  if(calvingdate.DateInDays != CONSTANTS::INT_NA && mbirthdate.DateInDays != CONSTANTS::INT_NA){
    calvingAge = calvingdate.DateInDays - mbirthdate.DateInDays;
    if(lnint != CONSTANTS::INT_NA){
      simpleDebug("calculateCalvingAge()_calvingdate, mbirthdate and lactationnumber are available, so we can calculate calvingAge", idstr);
      calvingAge = verifyCalvingAge(calvingAge, lnint, idstr);
    }else{
      simpleDebug("calculateCalvingAge()_calvingdate, mbirthdate are available, however lactationnumber not, so calvingAge is set to missing", idstr);
      calvingAge = CONSTANTS::INT_NA;
    }
  }
  else{
    simpleDebug("calculateCalvingAge()_calvingdate and mbirthdate are not available, so calvingAge is set to missing", idstr);
    calvingAge = CONSTANTS::INT_NA;
  }

  return calvingAge;

}


int calvingDataMap::transformCalvingScore(int calvingscoreint, string indstr){

  if(calvingscoreint == 1){
    simpleDebug("transformCalvingScore()_Transforming calvingscorestr to 3, because calvingscorestr is 1 ", indstr);
    return 3;
  }
  else if(calvingscoreint == 2){
    simpleDebug("transformCalvingScore()_Transforming calvingscorestr to 2, because calvingscorestr is 2 ", indstr);
    return 2;
  }
  else if(calvingscoreint == 3){
    simpleDebug("transformCalvingScore()_Transforming calvingscorestr to 1, because calvingscorestr is 3 ", indstr);
    return 1;
  }
  else if(calvingscoreint == 4){
    simpleDebug("transformCalvingScore()_Transforming calvingscorestr to 1, because calvingscorestr is 4 ", indstr);
    return 1;
  }
  else{
    simpleDebug("transformCalvingScore()_Transforming calvingscorestr to missing", indstr);
    return CONSTANTS::INT_NA;
  }

  return calvingscoreint;


}


long int calvingDataMap::calculateCalvingInterval(date calvingdate, date calfbefore_calvingdate, string idstr){

  long int calvingInterval;

  if(calvingdate.DateInDays != CONSTANTS::INT_NA && calfbefore_calvingdate.DateInDays != CONSTANTS::INT_NA){
    calvingInterval = calvingdate.DateInDays - calfbefore_calvingdate.DateInDays;
    simpleDebug("calculateCalvingInterval()_calvingInterval is "+to_string(calvingInterval), idstr);
  }
  else{
    simpleDebug("calculateCalvingInterval()_calvingdate and calfbefore_calvingdate are not available, so calvingInterval is set to missing", idstr);
    calvingInterval = CONSTANTS::INT_NA;
  }

  return calvingInterval;

}


long int calvingDataMap::calculateFirstCalvingAge(date mbirthdate, date firstcalvingdate, string idstr){

  long int firstCalvingAge;

  if(mbirthdate.DateInDays != CONSTANTS::INT_NA && firstcalvingdate.DateInDays != CONSTANTS::INT_NA){
    firstCalvingAge = firstcalvingdate.DateInDays - mbirthdate.DateInDays;
    simpleDebug("calculateFirstCalvingAge()_firstCalvingAge is "+to_string(firstCalvingAge), idstr);
  }
  else{
    simpleDebug("calculateFirstCalvingAge()_mbirthdate and firstcalvingdate are not available, so firstCalvingAge is set to missing", idstr);
    firstCalvingAge = CONSTANTS::INT_NA;
  }

  return firstCalvingAge;

}
