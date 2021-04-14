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
