/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * We need to get some practice writing functions
 * * * Better organized code
 * * * Avoid duplication
 * * For this challenge you are to write three functions in a single program
 * * Write a function which finds the greatest common divisor of two
 * non-negative integer values and to return the result
 * * * gcd, takes two ints as parameters
 * * Write a function to calculate the absolute value of a number
 * * * Should take as a parameter a float and return a float
 * * * Test this function with ints and floats
 * * Write a function to compute the square root of a number
 * * * If a negative argument is passed then a message is display and -1.0
 * should be returned
 * * * Should use the absoluteValue function as implemented in the above step
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int get_gcd(int first, int second);
float get_absolute(float number);
float get_square_root(float number);

int main(int argc, char *argv[]) {
  // Initialize variables
  int first = atof(argv[1]);
  int second = atof(argv[2]);
  float third = atof(argv[3]);
  float fourth = atof(argv[4]);

  // Get the values from the functions
  int gcd = get_gcd(first, second);
  float absolute_number = get_absolute(third);
  float square_root = get_square_root(fourth);

  // Print the computed values
  printf("The GCD for %i and %i is %i.\n", first, second, gcd);
  printf("Absolute number of %.2f is %.2f.\n", third, absolute_number);
  printf("The Square Root of %.2f is %.2f.\n", fourth, square_root);
  return 0;
}

// Computes Greates Common Divisor of two numbers
int get_gcd(int first, int second) {
  int common;
  int i, j;

  for (i = 1; i < first + 1; ++i) {
    if (first != 0 && first % i == 0) {
      for (j = 1; j < second + 1; ++j) {
        if (second != 0 && second % j == 0 && i == j)
          common = i;
      }
    }
  }
  return common;
}

// Returns absolute value of a number
float get_absolute(float number) { return fabs(number); }

// Computes square root of the number
float get_square_root(float number) {
  float square_root;
  square_root = sqrt(get_absolute(number));

  if (number < 0)
    return -1.0 * square_root;

  return square_root;
}
