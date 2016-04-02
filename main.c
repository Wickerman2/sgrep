#include <stdio.h>

#include "parser.h"
#include "searcher.h"
#include "sgrep_data.h"

int main(int argc, char **argv) {
  int ret_val;
  sgrep_data sgd; // Creating an instance of the struct sgrep_data
  sgd.matches = 0; // Number of hits
  /* Calling parser */
  ret_val=parse(argc, argv, &sgd); // Calling parser with arguments from the command line and the adress of the struct 
  if(ret_val!=PARSE_OK){
    return 2; //Failure! 
  }

  /* Test for NULL */
  /* Call search_file */
  ret_val=search_file(&sgd);
  /* check return values ...*/
  return ret_val; // Will use the codes from searcher.h
}
