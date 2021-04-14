#include <cstdlib>
#include "date.h"
#include "constants.h"
#include "util.h"
#include <plog/Log.h>



using namespace std;

date::date(){}


date::date(string datestr, int lastYearToConsiderData, string psRunningMode, string id){

  if(datestr.size() == 8){

    isValid = true;

    YearStr = datestr.substr(0,4).c_str();
    YearInt = atoi(YearStr.c_str());
    if(YearInt > lastYearToConsiderData || YearInt < 1950) {
      dateDebug("date()_Constructor called, YearInt "+to_string(YearInt)+" higer than lastYearToConsiderData or lower to 1950, so setting YearInt to missing", id, psRunningMode);
      dateDebug("date()_Constructor called, YearStr "+ YearStr+" higer than lastYearToConsiderData or lower to 1950, so setting YearStr to missing as well as isValid to false", id, psRunningMode);

      YearInt = CONSTANTS::INT_NA;
      YearStr = CONSTANTS::STRING_NA;
      isValid = false;

    }else{
      dateDebug("date()_Constructor called, plausibel YearInt " + to_string(YearInt), id, psRunningMode);
      dateDebug("date()_Constructor called, plausibel YearStr " + YearStr, id, psRunningMode);
      dateDebug("date()_Constructor called, plausibel YearStr, so setting isValid to true", id, psRunningMode);
    }

    MonthStr = datestr.substr(4,2).c_str();
    MonthInt=atoi(MonthStr.c_str());
    if(MonthInt<1 || MonthInt>12) {
      dateDebug("date()_Constructor called, MonthInt " + to_string(MonthInt)+" higer than 12 or lower to 1, so setting MonthInt to missing", id, psRunningMode);
      dateDebug("date()_Constructor called, MonthStr "+ MonthStr+" higer than 12 or lower to 1, so setting MonthStr to missing as well as isValid to false" , id, psRunningMode);

      MonthInt = CONSTANTS::INT_NA;
      MonthStr = CONSTANTS::STRING_NA;
      isValid = false;

    }else{
      dateDebug("date()_Constructor called, plausibel MonthInt " + to_string(MonthInt), id, psRunningMode);
      dateDebug("date()_Constructor called, plausibel MonthStr " + MonthStr, id, psRunningMode);
      dateDebug("date()_Constructor called , MonthStr is plausibel, so setting isValid to true ", id, psRunningMode);
    }

    DayStr = datestr.substr(6,2).c_str();
    DayInt=atoi(DayStr.c_str());
    if(DayInt<1 || DayInt>31) {
      dateDebug("date()_Constructor called, DayInt " + to_string(DayInt)+" higer than 31 or lower to 1, so setting DayInt to missing ", id, psRunningMode);
      dateDebug("date()_Constructor called, DayStr "+ DayStr+" higer than 31 or lower to 1, so setting DayStr to missing as well as isValid to false", id, psRunningMode);

      DayInt = CONSTANTS::INT_NA;
      DayStr = CONSTANTS::STRING_NA;
      isValid = false;

    }else{
      dateDebug("date()_Constructor called, plausibel DayInt " + to_string(DayInt), id, psRunningMode);
      dateDebug("date()_Constructor called, plausibel DayStr " + DayStr, id, psRunningMode);
      dateDebug("date()_Constructor called, DayStr is plausibel, so setting isValid to true ", id, psRunningMode);
    }

    DateInDays =  julDate(YearStr, MonthStr, DayStr);
    dateDebug("date()_Constructor called and DateInDays is " + to_string(DateInDays), id, psRunningMode);


  }else{
    YearInt = CONSTANTS::INT_NA;
    YearStr = CONSTANTS::STRING_NA;
    MonthInt = CONSTANTS::INT_NA;
    MonthStr = CONSTANTS::STRING_NA;
    DayInt = CONSTANTS::INT_NA;
    DayStr = CONSTANTS::STRING_NA;
    DateInDays = CONSTANTS::INT_NA;
    isValid = false;

    dateDebug("date()_Constructor called and date not equal to 8 digits, setting YearInt to missing " + to_string(YearInt), id, psRunningMode);
    dateDebug("date()_Constructor called and date not equal to 8 digits, setting YearStr to missing " + YearStr, id, psRunningMode);
    dateDebug("date()_Constructor called and date not equal to 8 digits, setting MonthInt to missing " + to_string(MonthInt), id, psRunningMode);
    dateDebug("date()_Constructor called and date not equal to 8 digits, setting MonthStr to missing " + MonthStr, id, psRunningMode);
    dateDebug("date()_Constructor called and date not equal to 8 digits, setting DayInt to missing " + to_string(DayInt), id, psRunningMode);
    dateDebug("date()_Constructor called and date not equal to 8 digits, setting DayStr to missing" + DayStr, id, psRunningMode);
    dateDebug("date()_Constructor called and date not equal to 8 digits, setting DateInDays to missing " + to_string(DateInDays), id, psRunningMode);
    dateDebug("date()_Constructor called and date not equal to 8 digits, setting isValid to false ", id, psRunningMode);

  }

}



// simple debug File
void date::dateDebug(string message, string tvdid, string psRunningMode){
  string localRunningMode = psRunningMode;
  if(localRunningMode == CONSTANTS::RUNNING_DEBUGALL){
    //here Develop-Output-Logfile
    LOGD <<"Message "<<message<<" of animal "<<tvdid;
  }
}
