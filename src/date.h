#ifndef Date_h
#define Date_h
#include <sstream>

using namespace std;

class date{
public:

  int YearInt;
  string YearStr;
  int MonthInt;
  string MonthStr;
  int DayInt;
  string DayStr;
  long int DateInDays;
  bool isValid;


  date(string datestr, int lastYearToConsiderData, string psRunningMode, string id);
  date();


  // running mode indicating whether debug information should be printed or not
  string runningMode;
  // list of TVD-Ids for which we want to output debugging information
  void dateDebug(string message, string tvdid, string psRunningMode);

};

#endif
