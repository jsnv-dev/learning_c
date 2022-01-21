/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * Create a file that contains some lines of text
 * * Open your test file
 * * Use the fgetc function to parse characters in a file until you get to the
 *   EOF
 *   * If EOF increment counter
 * * Display as output the total number of lines In the file
 */

#include <stdio.h>

int main() {
  // Initialize variables
  FILE *pfile = NULL;
  int count = 0, i, c;

  // Open the file.txt
  // Exit if there's an error opening the file
  if (!(pfile = fopen("file.txt", "w+"))) {
    printf("There's an error opening 'file.txt'.\n");
    return 1;
  }

  // Write 10 lines into file.txt
  for (i = 1; i < 11; ++i)
    fprintf(pfile, "Line %d\n", i);

  // Reset the pointer into the beginning of the file
  rewind(pfile);

  // Read the file char by char and count for every newline
  while ((c = fgetc(pfile)) != EOF) {
    if (c == '\n')
      count++;
  }

  // Close the file and display the number of lines
  fclose(pfile);
  pfile = NULL;
  printf("Total lines in the file is %d.\n", count);
  return 0;
}
