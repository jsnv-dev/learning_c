/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * Write a program that allows a user to input a text string. The program will
 *   print the text that was Inputted. The program will utilize dynamic memory
 *   allocation.
 * * The user can enter the limit of the string they are entering
 *   * you can use this limit when invoking malloc
 * * The program should create a char pointer only, no character arrays
 * * Be sure to release the memory that was allocated
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int string_size;
  char *str = NULL;

  // Get the size of the String
  printf("Please input size of the string: ");
  scanf("%i", &string_size);
  printf("Please input string: ");

  // Allocates the memory pointer for the String
  str = (char *)calloc(string_size, sizeof(char));

  // exit if the pointer can't be accomodated by the memory
  if (!str) {
    printf("Please re-run the program.\n");
    return 0;
  }

  // Get the string
  scanf("%s", str);

  // exit the program if string size is larger than the expected
  if (strlen(str) > string_size) {
    printf("The input string is larger than the expected size %d.\n",
           string_size);
    free(str);
    return 1;
  }

  // Display the input string then free it
  printf("The inpust string is '%s'\n", str);
  free(str);
  return 0;
}
