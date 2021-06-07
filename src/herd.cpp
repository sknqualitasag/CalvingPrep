#include <iostream>
#include <math.h>
#include <cmath>
#include "herd.h"


using namespace std;

herd::herd(){}


void herd::increment(int transformedCalvingScoreInt, double birthWeightDbl){

  // trait
  string traitCE = "ce";
  string traitBW = "bw";

  // statistic per herd
  // calving ease
  map<string,statistic*> :: iterator bit = HerdStatistic.find(traitCE);
  if(bit == HerdStatistic.end()){
    statistic *sPtr = new statistic();
    sPtr->ObsPerHerd = 1;
    sPtr->trait = traitCE;
    sPtr->Quadriert += (double) transformedCalvingScoreInt * (double) transformedCalvingScoreInt;
    sPtr->Sum += (double) transformedCalvingScoreInt;
    HerdStatistic[traitCE] = sPtr;
  }else{
    bit->second->ObsPerHerd++;
    bit->second->Quadriert += (double) transformedCalvingScoreInt * (double) transformedCalvingScoreInt;
    bit->second->Sum += (double) transformedCalvingScoreInt;
  }
  // birthweight
  map<string,statistic*> :: iterator wit = HerdStatistic.find(traitBW);
  if(wit == HerdStatistic.end()){
    statistic *sPtr = new statistic();
    sPtr->ObsPerHerd = 1;
    sPtr->trait = traitBW;
    sPtr->Quadriert += birthWeightDbl * birthWeightDbl;
    sPtr->Sum += birthWeightDbl;
    HerdStatistic[traitBW] = sPtr;
  }else{
    wit->second->ObsPerHerd++;
    wit->second->Quadriert += birthWeightDbl * birthWeightDbl;
    wit->second->Sum += birthWeightDbl;
  }

}


void herd::incrementHYS(string herdStr, string YearStr, string sireStr){

  map<string,statisticHYS*> :: iterator bit = HerdYearStatistic.find(herdStr+"."+YearStr);
  if(bit != HerdYearStatistic.end()){
    bit->second->ObsPerHerdyear++;

    if(bit->second->sireCounted.find(sireStr) == bit->second->sireCounted.end()){
      bit->second->sireCounted.insert(sireStr);
      bit->second->SiresPerHerdyear++;
    }

  }else{
    cout<<"incrementHYS: do not find herd.year to increment."<<endl;
  }

}
