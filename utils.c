#include "utils.h"
#include <ctype.h>
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

int isleap(int year) {
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      return year % 400 == 0;
    }

    return 1;
  }

  return 0;
}

int ismember(const int *nums, size_t size, int target) {
  for (int i = 0; (unsigned int)i < size; i++) {
    if (nums[i] == target) {
      return 1;
    }
  }

  return 0;
}

int getint(char *prompt, size_t size) {
  printf("%s", prompt);
  char input_str[size];
  fgets(input_str, size, stdin);
  return atoi(input_str);
}

char *getstr(char *prompt, size_t size) {
  printf("%s", prompt);
  char input_str[size];
  fgets(input_str, size, stdin);
  input_str[strcspn(input_str, "\n")] = '\0';

  char *result = malloc(size);
  if (result == NULL) return NULL;
  strcpy(result, input_str);
  return result;
}
