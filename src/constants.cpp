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
const char CONSTANTS::FIRSTYEARDATA[] = "2006";
//' integer for min first age at calving is 17 months
const int CONSTANTS::MIN_FIRST_AGE_AT_CALVING = 17;
//' integer for max first age at calving is 50 months
const int CONSTANTS::MAX_FIRST_AGE_AT_CALVING = 50;
//' integer for min first age at calving is 11 months
const int CONSTANTS::MIN_CALVING_INTERVAL = 11;
//' integer for max first age at calving is 18 months
const int CONSTANTS::MAX_CALVING_INTERVAL = 18;
//' integer for transforming in days
const int CONSTANTS::TRANSFORM_IN_DAYS = 31;
//' integer for first lactation
const int CONSTANTS::FIRST_LACTATION = 1;
//' missing value code as string
const double CONSTANTS::DOUBLE_NA = -9999.;
//' minimum observation per herd year
const unsigned CONSTANTS::MIN_OBS_PER_HERDYEAR = 5;
//' minimum observation per sire
const unsigned CONSTANTS::MIN_OBS_PER_SIRE = 5;
