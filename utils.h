#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

int getindex(const char **arr, size_t size, char *target);

char *strlower(char *str);

int isleap(int year);

int ismember(const int *nums, size_t size, int target);

#endif
