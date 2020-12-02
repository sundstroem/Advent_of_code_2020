#include <stdlib.h>
#include <stdio.h>

/*
The solver will
1. Parse the input data
1a. Parse the input into lines
1b. Parse the lines into usable data

  --- input.txt ---
=> char c
=> int min_amount
=> int max_amount
=> char *password

2. Have a function for checking password validity with the given constraints

3. Have a main function that calls the parser 1a. to get the lines,
   then parser 1b. and 2. for each line and then increments a counter 
   if 2. returns true value.
 
 */
typedef struct line {
  char character;
  int min_amount;
  int max_amount;
  char *password;
} line;

int parse(line *lines);
int check_line_A(line line);
int check_line_B(line line);
int main();
