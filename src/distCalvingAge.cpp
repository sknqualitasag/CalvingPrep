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
#include "distCalvingAge.h"


using namespace std;


distCalvingAge::distCalvingAge(double age, string breedcombstr){
  breedCombStr = breedcombstr;
  mean = age;
  var = age*age;
  num = 1;
}
