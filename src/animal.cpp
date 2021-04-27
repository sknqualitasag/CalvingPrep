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
#include <cstring>
#include "animal.h"
#include "calvingData.h"
#include "constants.h"
#include <plog/Log.h>
#include "date.h"




using namespace std;


animal::animal(calvingData *ptr){

  idCode=-1;
  sireCode=-1;
  damCode=-1;

  psRunningModeStr = ptr->psRunningModeStr;

  if(ptr->idStr != CONSTANTS::STRING_NA){
    idStr=ptr->idStr;
    constructorDebug("constructor animal()_idStr is set", idStr, psRunningModeStr);
  }else {
    idStr=CONSTANTS::STRING_NA;
    cout<<"Something is wrong, trying to generate an animal with a missing ID!"<<endl;
    exit(7);
  }

  idBreedStr = ptr->idBreedStr;
  constructorDebug("constructor animal()_idBreedStr is set "+ idBreedStr, idStr, psRunningModeStr);

  damStr = ptr->damStr;
  constructorDebug("constructor animal()_damStr is set "+ damStr , idStr, psRunningModeStr);

  damBreedStr = ptr->damBreedStr;
  constructorDebug("constructor animal()_damBreedStr is set "+ damBreedStr, idStr, psRunningModeStr);

  sireStr = ptr->sireStr;
  constructorDebug("constructor animal()_sireStr is set "+ sireStr, idStr, psRunningModeStr);

  sireBreedStr = ptr->sireBreedStr;
  constructorDebug("constructor animal()_sireBreedStr is set "+ sireBreedStr, idStr, psRunningModeStr);

  birthdate=ptr->calvingdate;
  constructorDebug("constructor animal()_birthdate.YearInt " + to_string(birthdate.YearInt), idStr, psRunningModeStr);
  constructorDebug("constructor animal()_birthdate.YearStr " + birthdate.YearStr, idStr, psRunningModeStr);
  constructorDebug("constructor animal()_birthdate.MonthInt " + to_string(birthdate.MonthInt), idStr, psRunningModeStr);
  constructorDebug("constructor animal()_birthdate.MonthStr " + birthdate.MonthStr, idStr, psRunningModeStr);
  constructorDebug("constructor animal()_birthdate.DayInt " + to_string(birthdate.DayInt), idStr, psRunningModeStr);
  constructorDebug("constructor animal()_birthdate.DayStr " + birthdate.DayStr, idStr, psRunningModeStr);
  constructorDebug("constructor animal()_birthdate.DateInDays " + to_string(birthdate.DateInDays), idStr, psRunningModeStr);
  constructorDebug("constructor animal()_birthdate.isValid " + to_string(birthdate.isValid), idStr, psRunningModeStr);

  sexStr = ptr->idSexStr;
  constructorDebug("constructor animal()_sexStr is set "+ sexStr, idStr, psRunningModeStr);

};


void animal::constructorDebug(string message, string tvdid, string psRunningMode){
  string localRunningMode = psRunningMode;
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}
