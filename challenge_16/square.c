/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * write a function that squares a number by itself
 *   * the function should define as a parameter an int pointer
 */
#include <stdio.h>

void square_number(int *const number);

int main() {
  int number;

  printf("Input number: ");
  scanf("%i", &number);

  square_number(&number);
  printf("Input number's square is %d.\n", number);
  return 0;
}

void square_number(int *const number) { *number *= *number; }
