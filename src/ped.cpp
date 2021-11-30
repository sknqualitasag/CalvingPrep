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
#include "ped.h"




using namespace std;


ped::ped(string indnumstr, string sirenumstr, string damnumstr, string itbidstr, string indstr, string indbirthdatestr, string indbreedstr, string inditbbreedstr, string sirebreedstr, string dambreedstr, string sireITBstr, string damITBStr){

  indnumStr = indnumstr;
  sirenumStr = sirenumstr;
  damnumStr = damnumstr;
  indITB18Str = itbidstr;
  indTVDstr = indstr;
  indBirthdateStr = indbirthdatestr;
  indRaceStr = indbreedstr;
  indITBRaceStr = inditbbreedstr;
  sireRaceStr = sirebreedstr;
  damRaceStr = dambreedstr;
  sireITB18Str = sireITBstr;
  damITB18Str = damITBStr;

}
