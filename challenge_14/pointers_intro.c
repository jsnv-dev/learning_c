/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * In this challenge, you are going to learn how to create, initialize,
 *   assign, and access a pointer
 * * Write a program that creates an integer variable with a hard-coded value.
 *   Assign that variable’s address to a pointer variable
 * * Display as output the address of the pointer, the value of the pointer, and
 *   the value of what the pointer is pointing to.
 */

#include <stdio.h>

int main() {
  // initialize int
  int number = 1010;
  // initialize pointer to int
  int *pnumber = &number;

  // Displays the Addresses and Values.
  // Number in between % and p/d are number of spaces before printing the value
  //   just to make the print output prettier.
  printf("Address of the number: %45p\n", &number);
  printf("Address of the pnumber pointer: %36p\n", (void *)&pnumber);
  printf("Value of the pnumber pointer = address of the number: %p\n", pnumber);
  printf("Value of the number (referenced by pnumber): %13d\n", *pnumber);
  return 0;
}
