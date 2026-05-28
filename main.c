#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zeller_formula(int year, int month, int month_day);

int main()
{
  const char *week_days[7] = {"Saturday", "Sunday", "Monday", "Tuesday",
                              "Wednesday", "Thursday", "Friday"};

  const char *months[12] = {"january", "february", "march", "april",
                            "may", "june", "july", "august",
                            "september", "october", "november", "december"};

  char year_input[5];
  printf("Enter a year: ");
  fgets(year_input, sizeof(year_input), stdin);
  int year = atoi(year_input);

  if (year <= 0) {
    printf("You must enter a valid year.\n");
    exit(EXIT_FAILURE);
  }

  getchar();
  char month_input[12];
  printf("Enter a month: ");
  fgets(month_input, sizeof(month_input), stdin);
  month_input[strcspn(month_input, "\n")] = '\0';
  int month = getindex(months, sizeof(months) / sizeof(months[0]),
                        strlower(month_input));

  if (month == -1 || month > 11)
  {
    printf("You must enter a valid month.");
    exit(EXIT_FAILURE);
  }

  char month_day_input[5];
  printf("Enter a day number: ");
  fgets(month_day_input, sizeof(month_day_input), stdin);
  int month_day = atoi(month_day_input);

  int leap_year = isleap(year);

  // When it is a leap year and the user entered February and over 29
  // february still = 1 because it has not been changed
  if (leap_year == 1 && month == 1 && month_day > 29)
  {
    printf("%d is a leap year and February was selected, "
           "so you must enter a day that is less than or equal to 29.\n",
           year);
    exit(EXIT_FAILURE);
  }
  else if (leap_year != 1 && month == 1 && month_day > 28)
  {
    printf("February only has 28 days.\n");
    exit(EXIT_FAILURE);
  }

  // april, june, september, november all have 30 days
  const int thirty_day_months[4] = {3, 5, 8, 10};
  if (ismember(thirty_day_months, 4, month) == 1 && month_day > 30)
  {
    printf("That month only has 30 days.\n");
    exit(EXIT_FAILURE);
  }

  int week_day = zeller_formula(year, month, month_day);

  printf("That day will be a %s.\n", week_days[week_day]);

  return EXIT_SUCCESS;
}

int zeller_formula(int year, int month, int month_day)
{
  // month is not supposed to be 0-based
  month++;

  if (month < 3)
  {
    month += 12;
    year--;
  }

  int K = year % 100;
  int J = year / 100;

  // `+ 7 % 7` normalizes the number so that it is always 0 > x > 6
  // fixes 1 mar 1900 segfaulting
  int week_day =
      (((month_day + (13 * (month + 1) / 5) + K + (K / 4) + (J / 4) - (2 * J)) %
        7) +
       7) %
      7;

  return week_day;
}
