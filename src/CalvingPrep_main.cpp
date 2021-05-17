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

  std::string dataFile                                = parmMap.getString("dataFileName");
  unsigned numberDataFiles                            = parmMap.getUnsigned("numberDataFiles");
  int lastYearToConsiderData                          = parmMap.getInteger("lastYearToConsiderData");
  std::string parRunMode                              = parmMap.getString("DEBUG");//yes = turn on debugging


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
    cMap.inputCalvingData(fileName, aMap, lastYearToConsiderData);
  }


  // Minimum observations per herdyear
  cMap.countHerdYear();
  cMap.purgeHerdYear();
  // Variance in herd
  cMap.countHerd();


  // Minimum observation per sire
  cMap.countSire();
  cMap.purgeSire();


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
