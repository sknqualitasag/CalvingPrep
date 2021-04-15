#include <Rcpp.h>
#include "constants.h"

using namespace Rcpp;

//' string corresponding to debuging
const char CONSTANTS::DEBUG[] = "yes";
// string corresponding to running debug all animal
const char CONSTANTS::RUNNING_DEBUGALL[] = "all";
//' length of TVD-Nr in number of characters
const unsigned CONSTANTS::TVD_NR_LENGTH = 14;
//' missing value code as string
const char CONSTANTS::STRING_NA[] = "-9999";
//' length of country code in TVD-NR
const unsigned CONSTANTS::COUNTRY_CODE_LENGTH = 2;
//' all letters in a string
const char CONSTANTS::LETTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//' string corresponding to all numbers
const char CONSTANTS::NUMBERS[] = "0123456789";
//' missing value code as integer
const int CONSTANTS::INT_NA = -9999;
//' length of ITB-Nr in number of characters
const unsigned CONSTANTS::ITB_NR_LENGTH = 19;
//' length of breed,country and sex code in ITB-NR
const unsigned CONSTANTS::BREED_COUNTRY_SEX_CODE_LENGTH = 7;
//' string corresponding to firstYearData
const char CONSTANTS::FIRSTYEARDATA[] = "1994";
