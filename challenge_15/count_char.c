/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * Write a function that calculates the length of a string
 *   * the function should take as a parameter a const char pointer
 *   * the function can only determine the length of the string using pointer
 *     arithmetic
 *     * incrementation operator (++pointer) to get to the end of the string
 *   * you are required to use a while loop using the value of the pointer to
 *     exit
 *   * the function should subtract two pointers (one pointing to the end of the
 *     string and one pointing to the beginning of the string)
 *   * the function should return an int that is the length of the string
 *     passed into the function
 */
#include <stdio.h>

int string_length(const char *input_string);

int main() {
  char input_string[100];
  int string_len;

  printf("Type the string to count: ");
  scanf("%s", input_string);

  string_len = string_length(input_string);
  printf("The string '%s' length is %d.\n", input_string, string_len);
  return 0;
}

int string_length(const char *input_string) {
  const char *start = input_string;

  // '\0' is zero == false which will stop the loop
  while (*input_string)
    input_string++;

  return input_string - start;
}
