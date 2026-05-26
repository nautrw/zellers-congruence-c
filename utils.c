#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int get_index(const char **arr, size_t size, char *target)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i], target) == 0)
			return i;
	}

	return -1;
}

char *strlower(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}

	return str;
}