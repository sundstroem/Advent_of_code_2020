#include "solver.h"

#define MAX_ARRAY_SIZE 1000

char **parse(){
  char **lines = (char **) malloc(MAX_ARRAY_SIZE * sizeof(char *));
  int i = 0;
  FILE *file = fopen("input.txt", "r");
  size_t str_len = 30;
  if (file == NULL) {
    printf("Error opening file in the parse function!\n");
    return lines;
  } else {
    while (!feof(file)){
      lines[i] = (char *) malloc(str_len);
      str_len = getline(&lines[i], &str_len, file);
      if(i == 0) lines[i] = (char *) realloc(lines[i], str_len);
      i++;
    }
  }
  if (i == 0) {
    printf("No lines found in the parse function!");
    return lines;
  }
  lines = (char **) realloc(lines, (i + 1) * sizeof(char *));
  lines[i] = NULL;
  return lines;
}


int count_trees(char **lines, int right, int down) {
  int i = 0; // vertical index
  int j = 0; // horizontal index
  int trees = 0;
  if (lines[0] == NULL) return 0;
  size_t string_length = strlen(lines[0]);
  while (lines[i] != NULL) {
    //printf("coords: (%d/%d), str: %s\n", i, j, lines[i]);
    if ( *(lines[i] + j) == '#') trees++;
    i += down;
    j = (j + right) % (string_length - 1);
  }
  return trees;
}


int main() {
  char **lines = parse();
  int count_A = count_trees(lines, 1, 1);
  
  int count_B = count_trees(lines, 3, 1);
  int count_C = count_trees(lines, 5, 1);
  int count_D = count_trees(lines, 7, 1);
  int count_E = count_trees(lines, 1, 2);
  printf("Number of trees encountered: %d, %d, %d, %d, %d\n", count_A, count_B, count_C, count_D, count_E);
  printf("product of these: %ld\n", (long) count_A * count_B * count_C * count_D * count_E);
  for (int i = 0; lines[i] != NULL; i++) free(lines[i]);
  free(lines);
  return 0;
}
