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
#include <chrono>
#include <ctime>
#include "pedMap.h"
#include <plog/Log.h>
#include "constants.h"
#include "calvingDataMap.h"


using namespace std;

pedMap::pedMap(){

  cout<<"\npedMap(): pedMap building "<<endl;
  cout<<"*****************************************************************"<< endl;

}


//' Make readable RRTDM-Pedigree from file pedfile
void pedMap::makeReadableRRTDMPedigree(string ipedfile, string opedfile){

  cout<<"\nmakeReadableRRTDMPedigree(): Reformatting the file "<<ipedfile<<" writing "<<opedfile<<endl;
  cout<<"*****************************************************************"<< endl;

  ifstream datafile(ipedfile.c_str());
  if(!datafile){
    cout<< "Cannot open file "<< ipedfile<<" in makeReadableRRTDMPedigree()! \n";
    exit(1);
  }

  ofstream outputfile(opedfile.c_str());
  if(!outputfile){
    cout<< "Cannot open output file! \n";
    exit(1);
  }


  datafile.setf(ios::skipws);
  string sep(" ");
  string indnumstr, sirenumstr, damnumstr, birthyearstr, itbidstr, inputStr, indstr, indbreedstr, indbirthdatestr, indactivstr, indhbstr, inditbbreedstr;
  Tokenizer colData;
  unsigned lineNumber=0, numCols;

  // reading RRTDM-pedigree file line by line
  while(getline(datafile,inputStr)){
    colData.getTokens(inputStr,sep);
    lineNumber++;
    numCols = colData.size();
    if(numCols == CONSTANTS::NUM_COL_RRTDM){

      indnumstr = colData[0];
      sirenumstr = colData[1];
      damnumstr = colData[2];
      birthyearstr = colData[3];
      itbidstr = colData[4];
      indstr = colData[5];
      indbirthdatestr = colData[6];
      indbreedstr = colData[7];
      indactivstr = colData[8];
      indhbstr = colData[9];
      inditbbreedstr = colData[10];

      outputfile<<indnumstr<<" "<<sirenumstr<<" "<<damnumstr<<" "<<birthyearstr<<" "<<itbidstr<<" "<<indstr<<" "<<indbirthdatestr<<" "<<indbreedstr<<" "
                <<indactivstr<<" "<<indhbstr<<" "<<inditbbreedstr<<endl;
    } else if(numCols == CONSTANTS::NUM_COL_RRTDM_WITH_MISSING){

      indnumstr = colData[0];
      sirenumstr = colData[1];
      damnumstr = colData[2];
      birthyearstr = "0000";
      itbidstr = colData[3];
      indstr = colData[4];
      indbirthdatestr = "00000000";
      indbreedstr = colData[5];
      indactivstr = colData[6];
      indhbstr = colData[7];
      inditbbreedstr = colData[8];

      outputfile<<indnumstr<<" "<<sirenumstr<<" "<<damnumstr<<" "<<birthyearstr<<" "<<itbidstr<<" "<<indstr<<" "<<indbirthdatestr<<" "<<indbreedstr<<" "
                <<indactivstr<<" "<<indhbstr<<" "<<inditbbreedstr<<endl;

    } else {
      cout << " *** ERROR: Read RRTDM-Ped for record: " << inputStr << " has the wrong number of columns"<<endl;
      cout << " ***        Observed number of columns: " << colData.size()<<endl;
      cout << " ***        Required number of columns for record with known birthdate: " << CONSTANTS::NUM_COL_RRTDM<<endl;
      cout << " ***        Required number of columns for record with missing birthdate: " << CONSTANTS::NUM_COL_RRTDM_WITH_MISSING<<endl;
      cout << " ***        Record ignored in outputfile: " << opedfile<<endl;
    }
  }

  datafile.close();
  outputfile.close();

}


//' Read RRTDM-Pedigree from file pedfile
//'
//' The content of pedfile is read line by line. A single space character
//' is used as column separator. The original RRTDM-pedigree identifies
//' animals, sires and dams based on their technical database ID.
//'
//' @param pedfile input file of RRTDM-pedigree
void pedMap::readRRTDMPedigree(string pedfileName){

  cout<<"\nreadRRTDMPedigree(): Reading RRTDM-pedigree from "<<pedfileName<<endl;
  cout<<"*****************************************************************"<< endl;

  ifstream datafile(pedfileName.c_str());
  if(!datafile){
    cout<< "Cannot open file "<< pedfileName<<" in readRRTDMPedigree()! \n";
    exit(1);
  }

  datafile.setf(ios::skipws);
  string sep(" ");
  string indnumstr, sirenumstr, damnumstr, birthyearstr, itbidstr, inputStr, indstr, indbreedstr, indbirthdatestr, indactivstr, indhbstr, inditbbreedstr;
  Tokenizer colData;
  unsigned lineNumber=0, numCols, rec = 0;

  // reading RRTDM-pedigree file line by line
  while(getline(datafile,inputStr)){
    colData.getTokens(inputStr,sep);
    lineNumber++;
    if (lineNumber==1){
      numCols = colData.size();
      cout<<"Number of columns: "<<numCols<<endl;
    }
    else if(colData.size() != numCols){
      cout<<"readRRTDMPedigree() Line "<<lineNumber<<" has "<<colData.size()<<" columns, "<<numCols<<" expected!"<<endl;
      cerr<<"record is: "<<inputStr<<endl;
      exit(8);
    }

    indnumstr = colData[0];
    sirenumstr = colData[1];
    damnumstr = colData[2];
    birthyearstr = colData[3];
    itbidstr = colData[4];
    indstr = colData[5];
    indbirthdatestr = colData[6];
    indbreedstr = colData[7];
    indactivstr = colData[8];
    indhbstr = colData[9];
    inditbbreedstr = colData[10];


    rec++;
    if(rec%100000==0){
      cout<<rec<<" records processed \r";
      cout.flush();
    }

    //pedigree constructor
    ped *pPtr = new ped(indnumstr, sirenumstr, damnumstr, itbidstr, indstr, indbirthdatestr, indbreedstr, inditbbreedstr, CONSTANTS::STRING_NA, CONSTANTS::STRING_NA, CONSTANTS::STRING_NA, CONSTANTS::STRING_NA);

    //build pedMap
    map<string,ped*>::iterator pit = this->find(pPtr->indnumStr);
    if(pit == this->end()){
      (*this)[pPtr->indnumStr] = pPtr;
    }
    else {
      cout<<"Numeric ID of animal "<<pPtr->indnumStr<<" is already in the map with rrtdm-input. Something is wrong!";
      exit(1);
    }
  }


  datafile.close();

  cout<<"\nnumber of records on pedigree file: "<<rec<<endl;
  cout<<this->size()<<" total number of records stored in map."<<endl;

}


void pedMap::fillITBParent(){

  cout<<"\nfillRaceParent(): "<<endl;
  cout<<"*****************************************************************"<< endl;

  //sireITBStr und damITBStr fuellen, falls die jeweiligen Eltern nicht missing im Pedigree sind
  for(map<string,ped*>::iterator it = this->begin(); it != this->end(); it++){

    if(it->second->sirenumStr != "0"){
      map<string,ped*>::iterator sit = this->find(it->second->sirenumStr);
      if(sit != this->end()){
        it->second->sireITB18Str = sit->second->indITB18Str;
      }
    }

    if(it->second->damnumStr != "0"){
      map<string,ped*>::iterator dit = this->find(it->second->damnumStr);
      if(dit != this->end()){
        it->second->damITB18Str = dit->second->indITB18Str;
      }
    }

  }

}
