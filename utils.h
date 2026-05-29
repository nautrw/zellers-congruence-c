#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdbool.h>

int getindex(char **arr, size_t size, char *target);

char *strlower(char *str);

bool isleap(int year);

bool ismember(int *nums, size_t size, int target);

int getint(char *prompt, size_t size);

char *getstr(char *prompt, size_t size);

void exitfail(char *msg);

#endif
