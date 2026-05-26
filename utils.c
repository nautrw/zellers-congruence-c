#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getindex(const char **arr, size_t size, char *target) {
  for (int i = 0; i < size; i++) {
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
  for (int i = 0; i < size; i++) {
    if (nums[i] == target) {
      return 1;
    }
  }

  return 0;
}
