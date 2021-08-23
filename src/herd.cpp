#include <iostream>
#include <math.h>
#include <cmath>
#include "herd.h"


using namespace std;

herd::herd(){}


void herd::increment(int transformedCalvingScoreInt, int birthWeightInt){

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
    sPtr->Quadriert += birthWeightInt * birthWeightInt;
    sPtr->Sum += birthWeightInt;
    HerdStatistic[traitBW] = sPtr;
  }else{
    wit->second->ObsPerHerd++;
    wit->second->Quadriert += birthWeightInt * birthWeightInt;
    wit->second->Sum += birthWeightInt;
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
    statisticHYS *sPtr = new statisticHYS();
    sPtr->ObsPerHerdyear = 1;
    sPtr->sireCounted.insert(sireStr);
    sPtr->SiresPerHerdyear = 1;
    (HerdYearStatistic)[herdStr+"."+YearStr] = sPtr;

  }

}
