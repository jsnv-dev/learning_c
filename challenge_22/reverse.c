/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * Write a program that will print the contents of a file in reverse order
 * * Use the fseek function to seek to the end of the file
 * * Use the ftell function to get the position of the file pointer
 * * Display as output the file in reverse order
 */

#include <stdio.h>

int main() {
  // Initialize the varialbes
  char orig_text[] = "This will be printed in reverse order.";
  FILE *pfile = NULL;
  int end_file = 0;

  // Opens the file and terminate the program if unsuccessful
  if (!(pfile = fopen("file.txt", "w+")))
    return 1;

  // Write the orig_text string into the file
  fputs(orig_text, pfile);

  // Move the pointer at the end of the file
  fseek(pfile, 0, SEEK_END);
  // Get the number of bytes from the beginning of the file until the end.
  end_file = ftell(pfile);

  // Print out the char from the end up to the beginning of the file
  // pointer is move backwards using the fseek()
  for (; end_file > -1; --end_file) {
    fseek(pfile, end_file, SEEK_SET);
    printf("%c", getc(pfile));
  }
  printf("\n");

  // Close the file
  fclose(pfile);
  return 0;
}
