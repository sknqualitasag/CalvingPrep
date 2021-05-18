#include <iostream>
#include <math.h>
#include <cmath>
#include "herd.h"


using namespace std;

herd::herd(){}


void herd::increment(double birthWeightDbl){

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
    sPtr->Quadriert += birthWeightDbl * birthWeightDbl;
    sPtr->Sum += birthWeightDbl;
    HerdStatistic[traitBW] = sPtr;
  }else{
    bit->second->ObsPerHerd++;
    bit->second->Quadriert += birthWeightDbl * birthWeightDbl;
    bit->second->Sum += birthWeightDbl;
  }

}
