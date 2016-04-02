#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "searcher.h"

#include "sgrep_data.h"

int search_string(char *indata, sgrep_data* sdg) {

  /*Note: You can use the GNU Libc function called strcasestr if you
    want to find a string in a string ignoring case.*/
  
  return SEARCHER_OK_MATCHES;
}

int search_file(sgrep_data *sdg)  {
  
  int line = 1; 

  char input [512];
  if(sdg->reg_exp==NULL){
  	return SEARCHER_BAD_INDATA;
  }
  while(fgets( input, sizeof input, sdg->in) !=NULL) { //As long there is command line/file input to read... 

  char *res = NULL;

  if(sdg->i == 1) { //If flag 'i' is activated, the search is case insensitive 
    res=strcasestr(input, sdg->reg_exp);
  }   else{
 	res=strstr(input, sdg->reg_exp); //Comparing the input with the command line / text file. 
  }
    if (res!=NULL) {
      sdg->matches++;   
      if (sdg->n == 1 && !sdg->c) {
        printf("%d:%s",line,input); //Prints the hits on their corresponding lines. 
      }else{
        if(!sdg->c){
          printf("%s", input);
        }
      }
    }
    
  line++;

  }
  if (sdg->c == 1) { 
     printf("%d\n", sdg->matches);  //Prints number of matches. 
  }
  if (sdg->n == 1) {    
  }
  
  fclose(sdg->in);

  if(sdg->matches>0){
	return SEARCHER_OK_MATCHES;
  }else{
  	return SEARCHER_OK_NO_MATCHES;
  }
}
