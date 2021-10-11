#include <Rcpp.h>
#include "constants.h"

using namespace Rcpp;

//' string corresponding to debuging
const char CONSTANTS::DEBUG[] = "yes";
//' string corresponding to debuging all animal
const char CONSTANTS::DEBUGALL[] = "all";
// string corresponding to running routine
const char CONSTANTS::RUNNING_ROUTINE[] = "routine";
// string corresponding to running debug all animal
const char CONSTANTS::RUNNING_DEBUGALL[] = "all";
// string corresponding to running debug
const char CONSTANTS::RUNNING_DEBUG[] = "debug";
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
//' minimum sires per herd year
const unsigned CONSTANTS::MIN_SIRE_PER_HERDYEAR = 2;
//' minimum observation per sire
const unsigned CONSTANTS::MIN_OBS_PER_SIRE = 5;
//' standarddeviation of zero for trait in herd
const double CONSTANTS::STD_TRAIT_ZERO_PER_HERD = 0.0001;
//' minimum observation per breedcomb
const unsigned CONSTANTS::MIN_OBS_PER_BREEDCOMB = 100;
// string corresponding to interbeef
const char CONSTANTS::INTERBEEF[] = "yes";
// string corresponding to interbeef category Beef On Beef
const char CONSTANTS::INTERBEEF_CATEGORY_BEEFONBEEF[] = "BeefOnBeef";
// string corresponding to interbeef category Beef On Dairy
const char CONSTANTS::INTERBEEF_CATEGORY_BEEFONDAIRY[] = "BeefOnDairy";
// string corresponding to breed Limouusin interbeef
const char CONSTANTS::LM_INTERBEEFBREED[] = "LM";
// string corresponding to breed Charolais interbeef
const char CONSTANTS::CH_INTERBEEFBREED[] = "CH";
// string corresponding to breed Simmental interbeef
const char CONSTANTS::SM_INTERBEEFBREED[] = "SI";
// string corresponding to breed Angus interbeef
const char CONSTANTS::AN_INTERBEEFBREED[] = "AN";
// string corresponding to breed Simmental interbeef
const char CONSTANTS::HH_INTERBEEFBREED[] = "HH";
// string corresponding to trait birthweight interbeef
const char CONSTANTS::BWT_INTERBEEFTRAIT[] = "BWT";
// string corresponding to trait calving ease interbeef
const char CONSTANTS::CAE_INTERBEEFTRAIT[] = "CAE";
// string corresponding to single birth coming from the data
const char CONSTANTS::SINGLE_BIRTH[] = "0";
// string corresponding to twin birth coming from the data
const char CONSTANTS::TWIN_BIRTH[] = "1";
// string corresponding to triplet birth coming from the data
const char CONSTANTS::TRIPLET_BIRTH[] = "2";
// string corresponding to single birth for interbeef
const char CONSTANTS::SINGLE_ITBBIRTH[] = "1";
// string corresponding to twin birth for interbeef
const char CONSTANTS::TWIN_ITBBIRTH[] = "2";
// string corresponding to triplet birth for interbeef
const char CONSTANTS::TRIPLET_ITBBIRTH[] = "2";


