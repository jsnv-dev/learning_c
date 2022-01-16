/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 */
#include <stdio.h>

int main() {
  // Intialize variables
  double minutes;
  double minutes_in_year = 365.25 * 24 * 60;
  double years;
  double days;

  // Get input minutes from the user
  printf("Enter minutes to convert: ");
  scanf("%lf", &minutes);

  // Calcuates the years and days
  years = minutes / minutes_in_year;
  days = years * 365.25;

  // Prints the results
  printf("Input minutes = %.2f\n", minutes);
  printf("Equivalent years = %.10f\n", years);
  printf("Equivalent days = %.5f\n", days);
  return 0;
}
