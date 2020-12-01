#include <stdlib.h>
#include <stdio.h>

#define MAX_ARRAY_SIZE 200

int *parser(int *A) {
  int i = 0;
  int current_array_size = 10;
  int current;
  
  FILE *file = fopen("input.txt", "r");
  if (file == NULL) {
    printf("Error opening file!\n");
    return A;
  } else {
    while (fscanf(file, "%d", &current) != EOF) {
      A[i] = current;
      i++;
    }
  }
  return A;
}

int main() {

  int A[MAX_ARRAY_SIZE];
  parser(A);
  for (int i = 0; i < MAX_ARRAY_SIZE - 1; i++) {
    for (int j = i + 1; j < MAX_ARRAY_SIZE; j++) {
      if (A[i] + A[j] == 2020) {
	printf("result: %d\n", A[i] * A[j]);
	return 0;	
      }
    }
  }
  printf("Result not found!\n");
  return -1;
}
