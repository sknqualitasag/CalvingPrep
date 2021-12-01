#ifndef Constants_h
#define Constants_h


class CONSTANTS {
public:
  // string corresponding to debuging
  static const char DEBUG[];
  // string corresponding to running debug all animal
  static const char RUNNING_DEBUGALL[];
  // string corresponding to running routine
  static const char RUNNING_ROUTINE[];
  //' string corresponding to debuging all animal
  static const char DEBUGALL[];
  // string corresponding to running debug
  static const char RUNNING_DEBUG[];
  // length of TVD-Nr in number of characters
  static const unsigned TVD_NR_LENGTH;
  // string corresponding to missing value code
  static const char STRING_NA[];
  // number of characters that correspond to the country code
  static const unsigned COUNTRY_CODE_LENGTH;
  // string that corresponds to all letters
  static const char LETTERS[];
  // string corresponding to all numbers
  static const char NUMBERS[];
  //' missing value code as integer
  static const int INT_NA;
  //' length of ITB-Nr in number of characters
  static const unsigned ITB_NR_LENGTH;
  //' length of breed,country and sex code in ITB-NR
  static const unsigned BREED_COUNTRY_SEX_CODE_LENGTH;
  //' string corresponding to firstYearData
  static const char FIRSTYEARDATA[];
  //' integer for min first age at calving is 17 months
  static const int MIN_FIRST_AGE_AT_CALVING;
  //' integer for max first age at calving is 50 months
  static const int MAX_FIRST_AGE_AT_CALVING;
  //' integer for min first age at calving is 11 months
  static const int MIN_CALVING_INTERVAL;
  //' integer for max first age at calving is 18 months
  static const int MAX_CALVING_INTERVAL;
  //' integer for transforming in days
  static const int TRANSFORM_IN_DAYS;
  //' integer for first lactation
  static const int FIRST_LACTATION;
  //' missing value code as double
  static const double DOUBLE_NA;
  //' minimum observation per herd year
  static const unsigned MIN_OBS_PER_HERDYEAR;
  //' minimum sires per herd year
  static const unsigned MIN_SIRE_PER_HERDYEAR;
  //' minimum observation per sire
  static const unsigned MIN_OBS_PER_SIRE;
  //' standarddeviation of zero for trait in herd
  static const double STD_TRAIT_ZERO_PER_HERD;
  //' minimum observation per breedcomb
  static const unsigned MIN_OBS_PER_BREEDCOMB;
  // string corresponding to interbeef
  static const char INTERBEEF[];
  // string corresponding to interbeef category Beef On Beef
  static const char INTERBEEF_CATEGORY_BEEFONBEEF[];
  // string corresponding to interbeef category Beef On Dairy
  static const char INTERBEEF_CATEGORY_BEEFONDAIRY[];
  // string corresponding to breed Limouusin interbeef
  static const char LM_INTERBEEFBREED[];
  // string corresponding to breed Charolais interbeef
  static const char CH_INTERBEEFBREED[];
  // string corresponding to breed Simmental interbeef
  static const char SM_INTERBEEFBREED[];
  // string corresponding to breed Angus interbeef
  static const char AN_INTERBEEFBREED[];
  // string corresponding to breed Simmental interbeef
  static const char HH_INTERBEEFBREED[];
  // string corresponding to trait birthweight interbeef
  static const char BWT_INTERBEEFTRAIT[];
  // string corresponding to trait calving ease interbeef
  static const char CAE_INTERBEEFTRAIT[];
  // string corresponding to single birth coming from the data
  static const char SINGLE_BIRTH[];
  // string corresponding to twin birth coming from the data
  static const char TWIN_BIRTH[];
  // string corresponding to triplet birth coming from the data
  static const char TRIPLET_BIRTH[];
  // string corresponding to single birth for interbeef
  static const char SINGLE_ITBBIRTH[];
  // string corresponding to twin birth for interbeef
  static const char TWIN_ITBBIRTH[];
  // string corresponding to triplet birth for interbeef
  static const char TRIPLET_ITBBIRTH[];
  //' number of columns of rrtdm-pedigree
  static const unsigned NUM_COL_RRTDM;
  //' number of columns of rrtdm-pedigree by missing informations
  static const unsigned NUM_COL_RRTDM_WITH_MISSING;
  // number of characters that correspond to the breed code
  static const unsigned BREED_CODE_LENGTH;
  //' missing value code for ITBid
  static const char MISSING_ITBID[];








};

#endif
