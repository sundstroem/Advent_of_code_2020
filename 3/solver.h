#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

1. Parse input into an array of strings
2. Loop over the array and count the trees

 */

char **parse();
int count_trees(char **lines, int right, int down);
