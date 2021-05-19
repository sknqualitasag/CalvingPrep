#ifndef Constants_h
#define Constants_h


class CONSTANTS {
public:
  // string corresponding to debuging
  static const char DEBUG[];
  // string corresponding to running debug all animal
  static const char RUNNING_DEBUGALL[];
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
  //' minimum observation per sire
  static const unsigned MIN_OBS_PER_SIRE;
  //' standarddeviation of zero for trait in herd
  static const double STD_TRAIT_ZERO_PER_HERD;





};

#endif
