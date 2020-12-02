#include "solver.h"

#define MAX_ARRAY_SIZE 1000
#define MAX_PASSWORD_SIZE 30

int parse(line *lines){
  int i = 0;
  FILE *file = fopen("test_input", "r");
 
  if (file == NULL) {
    printf("Error opening file in the parse function!\n");
    return 0;
  } else {
    while (!feof(file)){
      lines[i].password = (char *) malloc(MAX_PASSWORD_SIZE);
      fscanf(file, "%d-%d %c: %s \n", &lines[i].min_amount, &lines[i].max_amount,
	     &lines[i].character, lines[i].password);
      i++;
    }
  }
  //lines = (line *) realloc(lines, (i + 1) * sizeof(line));
  return i;
}

int check_line_A(line line) {
  char *ptr = line.password;
  char c = *ptr;
  int count = 0;

  while (c != '\0') {
    if (c == line.character) count++;
    ptr++;
    c = *ptr;

  }
  
  return (count >= line.min_amount && count <= line.max_amount);
}

int check_line_B(line line) {
  char *ptr = line.password;
  char c = *ptr;
  int count = 0;
  int index = 0;
  
  while (c != '\0') {
    if (index == line.min_amount - 1 || index == line.max_amount - 1){
      if (c == line.character) count++;
    }
    index++;
    c = *(ptr + index);
  }
  return (count == 1);
}

int main() {
  line *lines = (line *) malloc(MAX_ARRAY_SIZE * sizeof(line));
  int nof_lines = parse(lines);
  int count_A = 0;
  int count_B = 0;
  for (int i = 0; i < nof_lines; i++) {
    if (check_line_A(lines[i])) count_A++;
    if (check_line_B(lines[i])) count_B++;
    free(lines[i].password);
  }
  printf("Number of valid passwords: %d\n", count_A);
  printf("Number of valid passwords (in part two): %d\n", count_B);
  free(lines);
  return 0;
}
