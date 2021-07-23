#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <Rcpp.h>
#include "parmMap.h"
#include "calvingDataMap.h"
#include "animalMap.h"
#include <plog/Log.h>
#include <plog/Formatters/MessageOnlyFormatter.h>
#include "constants.h"


using namespace Rcpp;


//' @title Main Entry Function To Check Data Consistency and Coding For Birth Evaluation
//'
//' @description
//' This is the main entry function to check consistency and coding birth data.
//'
//' @param paramFileName input paramter file name
//'
//' @export CalvingPrep_main
// [[Rcpp::export]]
int CalvingPrep_main(std::string paramFileName) {

  //Time tracking
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  time_t start_time = std::chrono::system_clock::to_time_t(start);

  std::cout<<"-----------------------------------------------------------------"<< std::endl;
  std::cout << "START CalvingPrepare_main() at " << std::ctime(&start_time) << std::endl;
  std::cout<<"-----------------------------------------------------------------"<< std::endl;


  //Read parameter-file
  ParmMap parmMap;
  parmMap.fileName = paramFileName;
  parmMap.inputParms();

  std::string dataFile                        = parmMap.getString("dataFileName");
  unsigned numberDataFiles                    = parmMap.getUnsigned("numberDataFiles");
  int lastYearToConsiderData                  = parmMap.getInteger("lastYearToConsiderData");
  std::string parRunMode                      = parmMap.getString("DEBUG");//yes = turn on debugging
  unsigned proportion                         = parmMap.getUnsigned("proportion");//1 = draw sample on herds; 0 = not draw sample
  unsigned seed                               = parmMap.getUnsigned("seed");//0 = not draw sample;
  bool parSampling                            = parmMap.getBoolean("sampling");//true = sampling; false = not sampling
  int startYearSampling						            = parmMap.getInteger("startYearSampling");
  int endYearSampling						              = parmMap.getInteger("endYearSampling");
  bool parselectSplitBeefDairy                = parmMap.getBoolean("selectSplitBeefDairy");//true = yes; false = no select
  bool parselectSplitMandantBeef              = parmMap.getBoolean("selectSplitMandantBeef");//true = yes; false = no select
  bool parselectSplitMotherbreedBeef          = parmMap.getBoolean("selectSplitMotherbreedBeef");//true = yes; false = no select
  bool parselectSplitMandantDairy             = parmMap.getBoolean("selectSplitMandantDairy");//true = yes; false = no select
  bool parselectSplitMotherbreedDairy         = parmMap.getBoolean("selectSplitMotherbreedDairy");//true = yes; false = no select
  bool parwithMaternalEffect                  = parmMap.getBoolean("withMaternalEffect");//true = yes; false = no including maternal



  //Declare Map
  calvingDataMap cMap;
  animalMap aMap;


  //Create DEBUG-File
  if (parRunMode == CONSTANTS::DEBUG){
    plog::init(plog::debug, "DEBUG_CalvingPrepare.txt");
    cMap.setRunningMode(CONSTANTS::RUNNING_DEBUGALL);
  }


  //Read raw calving-data and check the field of the data-record
  for(unsigned i=0; i<numberDataFiles; i++){
    string fileName = cMap.getFileName(i,dataFile);
    cMap.inputCalvingData(fileName, aMap, lastYearToConsiderData, parSampling, startYearSampling, endYearSampling,\
                          parselectSplitBeefDairy, parselectSplitMandantBeef, parselectSplitMotherbreedBeef, parselectSplitMandantDairy, parselectSplitMotherbreedDairy);
  }

  // Minimum observations per breedcombination
  cMap.countBreedComb();
  cMap.purgeBreedComb();

  // Minimum observation per dam
  cMap.countDam(parwithMaternalEffect);

  // Minimum observations per herdyear
  // Minimum sires per herdyear
  cMap.countHerdYearSire();
  cMap.purgeHerdYear();
  cMap.purgeHerdYearSire();


  // Check Variance per herd
  cMap.countHerd();
  cMap.stdHerd();
  cMap.purgeHerd();


  // Minimum observation per sire
  cMap.countSire();
  cMap.purgeSire();


  // Draw a sample of data based on herds
  cMap.drawHerd(proportion, seed);


  //Coding the effects
  cMap.codeEffects();


  //Phenotyp Output
  cMap.pheno_out();


  //Time tracking
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  std::cout<<"\n-----------------------------------------------------------------"<< std::endl;
  std::cout << "END CalvingPrepare_main() at " << std::ctime(&end_time)
            << "elapsed time: " << elapsed_seconds.count() << " s"<<std::endl;
  std::cout<<"-----------------------------------------------------------------"<< std::endl;


  return 0;

};
