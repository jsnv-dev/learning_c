/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * Write a program that sorts the strings of an array using a bubble sort
 *   * need to use the strcmp and strcpy functions
 *
 * Input number of strings: 3
 * Input string 3 :
 * zero
 * one
 * two
 *
 * Expected Output:
 * The strings appears after sorting:
 * one
 * two
 * zero
 */

#include <stdio.h>
#include <string.h>

void bubble_sort(char strings[50][50], int number_of_strings);

int main() {
  int number_of_strings, i;
  char string_inputs[50][50];

  printf("Input number of strings: ");
  scanf("%i", &number_of_strings);
  printf("Input %i strings:\n", number_of_strings);
  for (i = 0; i < number_of_strings; ++i)
    scanf("%s", string_inputs[i]);

  bubble_sort(string_inputs, number_of_strings);
  printf("\nThe strings appears after sorting:\n");
  for (i = 0; i < number_of_strings; ++i)
    printf("%s\n", string_inputs[i]);

  return 0;
}

// Bubble Sort is the simplest sorting algorithm that works by repeatedly
// swapping the adjacent elements if they are in wrong order. reference:
// https://www.geeksforgeeks.org/bubble-sort/
void bubble_sort(char strings[50][50], int number_of_strings) {
  int i, j, k;
  char temp[50];

  for (i = 0; i < number_of_strings; i++) {
    for (j = 0; j < (number_of_strings - i - 1); j++) {
      k = strncmp(strings[j], strings[j + 1], 50);
      if (k > 0) {
        strncpy(temp, strings[j], 50);
        strncpy(strings[j], strings[j + 1], 50);
        strncpy(strings[j + 1], temp, 50);
      }
    }
  }
}
