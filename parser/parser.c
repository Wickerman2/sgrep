#include <stdio.h>
#include <string.h>
#include <unistd.h>


#include "parser.h"
#include "sgrep_data.h"

int parse(int argc, char **argv, sgrep_data *data) {
                                                      
  int flag;
  
  while ((flag = getopt(argc, argv, "icn")) !=-1) {   // Checking which flags are active (Active == 1, Inactive == 0)!
    switch (flag) {
      case 'i' :               
                data->i = 1;               
                break;
      case 'c' :               
                data->c = 1;
                break;
      case 'n' :                
                data->n = 1;                
                break;
      default  : 
                printf("%s\n", "default");                
    }
    

  }
  data->reg_exp = argv[optind];
  /* // Save the search word into the struct */

  if((argc-1)>optind){ 
/* // Is there any filenames for scanning? */

    /* // Save the filename into the struct */
    data->in = fopen(argv[optind+1], "r");

    if (data->in != NULL) { //Checking for bad input
          ; 
    }else{
          printf("The scanning of %s failed!\n", argv[optind+1]); 
          return PARSE_BAD_INDATA;
    }
  }
  else{
      data->in=stdin; /* // Save stdn as file into the struct */
  }

  return PARSE_OK;
}


