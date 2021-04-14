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
