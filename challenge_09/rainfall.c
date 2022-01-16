/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * In this challenge, you are to create a C program that uses
 *     two-dimensional array in a weather program.
 * * The program will find the total rainfall for each year, the average yearly
 *     rainfall, and the average rainfall for each month
 * * Input will be a 2D array with hard-coded values for rainfall amounts for
 *     the past 5 years
 * * * The array should have 5 rows and 12 columns
 * * * Rainfall amounts can be floating point numbers
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize seed
  time_t t;
  srand((unsigned)time(&t));

  // Initialize variables
  float rainfall[5][12];
  float yearly_sum[5];
  float monthly_sum[12];
  float total;
  int year, month;

  // Initialize random float numbers for rainfall matrix
  printf("RAINFALL MATRIX:\n");
  for (year = 0; year < 5; ++year) {
    for (month = 0; month < 12; ++month) {
      rainfall[year][month] = ((float)rand() / (float)(RAND_MAX)) * 10;
      printf("%.2f ", rainfall[year][month]);

      if (month == 11)
        printf("\n");
    }
  }

  // Calculates Yearly sum of rainfall
  printf("\nYEAR    RAINFALL\n");
  for (year = 0; year < 5; ++year) {
    for (month = 0; month < 12; ++month) {
      yearly_sum[year] += rainfall[year][month];
    }
    total += yearly_sum[year];
    printf("Year-%d   %.2f\n", year + 1, yearly_sum[year]);
  }

  printf("\nThe yearly average is %.2f inches.\n", total / 5);

  // Calculates Monthly average of rainfall
  printf("\nMONTHLY AVERAGES: \n");
  printf("Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
  for (month = 0; month < 12; ++month) {
    for (year = 0; year < 5; ++year) {
      monthly_sum[month] += rainfall[year][month];
    }
    printf("%.2f ", monthly_sum[month] / 5.0);

    if (month == 11)
      printf("\n");
  }

  return 0;
}
