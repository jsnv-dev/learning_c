/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Initializes the variables
  // atof converts char into double

  double height = atof(argv[1]);
  double width = atof(argv[2]);
  double perimeter = 0.0;
  double area = 0.0;

  // Computation
  perimeter = 2.0 * (height + width);
  area = height * width;

  // Prints the values
  printf("The computed perimeter is: %.2f\n", perimeter);
  printf("The computed area is: %.2f\n", area);
  return 0;
}
