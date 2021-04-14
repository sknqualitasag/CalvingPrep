#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <Rcpp.h>



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

  std::cout<<"-----------------------------------------------------------------"<< std::endl;
  std::cout << "START CalvingPrepare_main() " << std::endl;
  std::cout<<"-----------------------------------------------------------------"<< std::endl;

  std::cout<<"\n-----------------------------------------------------------------"<< std::endl;
  std::cout << "END CalvingPrepare_main() " << std::endl;
  std::cout<<"-----------------------------------------------------------------"<< std::endl;


  return 0;

};
