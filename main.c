#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  const char *week_days[7] = {"Saturday",  "Sunday",   "Monday", "Tuesday",
                              "Wednesday", "Thursday", "Friday"};

  const char *months[12] = {"january",   "february", "march",    "april",
                            "may",       "june",     "july",     "august",
                            "september", "october",  "november", "december"};

  int year;
  printf("Enter a year: "); scanf("%d", &year);

  getchar();
  char month_input[12];
  printf("Enter a month: ");
  fgets(month_input, sizeof(month_input), stdin);
  month_input[strcspn(month_input, "\n")] = '\0';
  int month = get_index(months, sizeof(months) / sizeof(months[0]),
                        strlower(month_input)) +
              1;

  if (month == -1 || month > 11) {
    printf("You must enter a valid month.");
    exit(EXIT_FAILURE);
  }

  int month_day;
  printf("Enter a day number: ");
  scanf("%d", &month_day);

  if (month < 3) {
    month += 12;
    year--;
  }

  int K = year % 100;
  int J = year / 100;

  int week_day =
      (month_day + (13 * (month + 1) / 5) + K + (K / 4) + (J / 4) - (2 * J)) %
      7;

  printf("That day will be a %s.\n", week_days[week_day]);

  return 0;
}
