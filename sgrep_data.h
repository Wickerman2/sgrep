#ifndef SGREP_DATA_H
#define SGREP_DATA_H

typedef struct sgrep_data{
  char *reg_exp; 
  FILE *in;
  int matches; 
  int dummy_var_to_to_make_gcc_shut_up;
  int i; //Flag to make sgrep case insensitive
  int c; //Flag to count the number of matches and print them out
  int n; //Flag to print the number of line where the match was found

} sgrep_data;


#endif /* SGREP_DATA_H */
