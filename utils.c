#include "utils.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getindex(const char **arr, size_t size, char *target) {
  for (int i = 0; (unsigned int)i < size; i++) {
    if (strcmp(arr[i], target) == 0)
      return i;
  }

  return -1;
}

char *strlower(char *str) {
  for (int i = 0; str[i]; i++) {
    str[i] = tolower(str[i]);
  }

  return str;
}

bool isleap(int year) {
  if (year % 4 == 0 && year % 100 == 0) {
    return year % 400 == 0;
  } else {
    return true;
  }

  return false;
}

bool ismember(const int *nums, size_t size, int target) {
  for (int i = 0; (unsigned int)i < size; i++) {
    if (nums[i] == target) {
      return true;
    }
  }

  return false;
}

int getint(char *prompt, size_t size) {
  printf("%s", prompt);
  char input_str[size];
  fgets(input_str, size, stdin);
  return atoi(input_str);
}

char *getstr(char *prompt, size_t size) {
  char *input;
  // from my limited understanding, returning `input_str` would be wrong because
  // that pointer is in the stack, so it only exists for the duration of the
  // call, and thus would be immediately invalid if I returned it, thus I can
  // use malloc to allocate it on the heap and use it outside the function
  input = malloc(size * sizeof(*input));
  if (input == NULL) // malloc can fail
    return NULL;

  printf("%s", prompt);
  if (fgets(input, size, stdin) == NULL) {
    free(input);
    return NULL;
  }

  input[strcspn(input, "\n")] = '\0';
  return input;
}

void exitfail(char *msg) {
  printf("%s", msg);
  exit(EXIT_FAILURE);
}
