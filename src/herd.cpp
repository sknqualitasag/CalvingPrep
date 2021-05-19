#include <iostream>
#include <math.h>
#include <cmath>
#include "herd.h"


using namespace std;

herd::herd(){}


void herd::increment(int transformedCalvingScoreInt){

  // trait
  string traitBW = "bw";
  string traitCE = "ce";

  // statistic per herd
  // birthweight
  map<string,statistic*> :: iterator bit = HerdStatistic.find(traitBW);
  if(bit == HerdStatistic.end()){
    statistic *sPtr = new statistic();
    sPtr->ObsPerHerd = 1;
    sPtr->trait = traitBW;
    sPtr->Quadriert += (double) transformedCalvingScoreInt * (double) transformedCalvingScoreInt;
    sPtr->Sum += (double) transformedCalvingScoreInt;
    HerdStatistic[traitBW] = sPtr;
  }else{
    bit->second->ObsPerHerd++;
    bit->second->Quadriert += (double) transformedCalvingScoreInt * (double) transformedCalvingScoreInt;
    bit->second->Sum += (double) transformedCalvingScoreInt;
  }

}
