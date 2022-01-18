/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * In this challenge, you are going to write a program that tests your
 *   understanding of char arrays
 * * write a function to count the number of characters in a string (length)
 *   * cannot use the strlen library function
 *   * function should take a character array as a parameter
 *   * should return an int (the length)
 * * write a function to concatenate two character strings
 *   * cannot use the strcat library function
 *   * function should take 3 parameters
 *     * char result[]
 *     * const char stri]}
 *     * const char str2|]
 *     * can return void
 * * write a function that determines if two strings are equal
 *   * cannot use strcmp library function
 *   * function should take two const char arrays as parameters and return a
 *     Boolean of true if they are equal and false otherwise
 */

#include <stdbool.h>
#include <stdio.h>

int str_len(char *string);
void str_concat(char *result, char *string1, char *string2);
bool str_eql(char *string1, char *string2);

int main() {
  // Initializes the variables
  char string1[100];
  char string2[100];
  char result[100];

  // Get input Strings
  printf("Input first input: ");
  scanf("%s", string1);
  printf("Input second input: ");
  scanf("%s", string2);

  // Prints the length of each Strings
  printf("\nFirst string length is %d.", str_len(string1));
  printf("\nSecond string length is %d.\n", str_len(string2));

  // Concatenate the Strings
  str_concat(result, string1, string2);
  printf("Concatenated string is '%s'.\n", result);

  // Checks if Strings are equal
  printf("Strings are%s equal.\n", str_eql(string1, string2) ? "" : " not");
  return 0;
}

int str_len(char *string) {
  int length;
  for (length = 0; string[length] != '\0'; ++length)
    ;
  return length;
}

void str_concat(char *result, char *string1, char *string2) {
  int i, j;
  for (i = 0; (result[i] = string1[i]) != '\0'; ++i)
    j = i + 1;
  for (i = 0; (result[j] = string2[i]) != '\0'; ++i, ++j)
    ;
  result[j] = '\0';
}

bool str_eql(char *string1, char *string2) {
  int i;
  bool eql = false;

  for (i = 0; string1[i] != '\0'; ++i) {
    if (string1[i] != string2[i])
      return false;
    eql = true;
  }

  return eql;
}
