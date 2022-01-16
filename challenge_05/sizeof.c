/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 */
#include <stdio.h>

int main() {
  // Initialize variables
  int int_size = sizeof(int);
  int char_size = sizeof(char);
  int long_size = sizeof(long);
  int long_long_size = sizeof(long long);
  int double_size = sizeof(double);
  int long_double_size = sizeof(long double);

  // Print sizes of the Data Types
  printf("int size is %u bytes\n", int_size);
  printf("char size is %u bytes\n", char_size);
  printf("long size is %u bytes\n", long_size);
  printf("long long size is %u bytes\n", long_long_size);
  printf("double size is %u bytes\n", double_size);
  printf("long double size is %u bytes\n", long_double_size);
  return 0;
}
