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


    string mstr = getVerifiedTvdNr(colData[0]);
    string mbreedstr = verifyBreed(colData[1],mstr);
    string mvbreedstr = verifyBreed(colData[2],"");
    string idstr = getVerifiedTvdNr(colData[6]);


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
