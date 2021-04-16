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
#include <ctype.h>
#include "animalMap.h"
#include "animal.h"
#include "constants.h"
#include <plog/Log.h>



using namespace std;


animalMap::animalMap(){}


void animalMap::addAnimal(calvingData *ptr){

  constructorDebug("addAnimal()_ptr of calvingData is used to build up the animal constructor", ptr->idStr, ptr->psRunningModeStr);

  animal *aptr = new animal(ptr);

  map<string, animal*>::iterator ait = this->find(ptr->idStr);
  if(ait == this->end()){
    (*this)[ptr->idStr]= aptr;

    constructorDebug("addAnimal()_Build animalMap ", aptr->idStr, aptr->psRunningModeStr);
  }

};


void animalMap::constructorDebug(string message, string tvdid, string psRunningMode){
  string localRunningMode = psRunningMode;
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}
