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

// Solves the first problem of the first day
void solve_part_1(int A[]) { 
  for (int i = 0; i < MAX_ARRAY_SIZE - 1; i++) {
    for (int j = i + 1; j < MAX_ARRAY_SIZE; j++) {
      if (A[i] + A[j] == 2020) {
	printf("The result for part 1: %d\n", A[i] * A[j]);
	return;	
      }
    }
  }
  printf("Result not found! (part 1)\n");
}

// Solves the second problem of the first day
void solve_part_2(int A[]) {
  for (int i = 0; i < MAX_ARRAY_SIZE - 2; i++) {
    for (int j = i + 1; j < MAX_ARRAY_SIZE - 1; j++) {
      for (int k = j + 1; k < MAX_ARRAY_SIZE; k++) {
	if (A[i] + A[j] + A[k] == 2020) {
	  printf("The result for part 2: %d\n", A[i] * A[j] * A[k]);
	  return;
	}
      }
    }
  }
  printf("Result not found! (part 2)\n");
}

int main() {
  int A[MAX_ARRAY_SIZE];
  parser(A);

  solve_part_1(A);
  solve_part_2(A);

  return 0;
}
