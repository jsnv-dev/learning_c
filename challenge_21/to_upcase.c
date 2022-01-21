/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * Write a program that converts all characters of a file to uppercase and
 *   write the results out to a temporary file. Then rename the temporary file
 *   to the original filename and remove the temporary filename
 * * Use the fgetc and fputc functions
 * * Use the rename and remove functions
 * * Use the islower function
 *   * Convert a character to upper case by subtracting 32 from it
 * * Display the contents of the original file to standard output
 *   * In uppercase
 */

#include <stdio.h>

int islower(int);

int main() {
  // Initialize variables for file pointers, names, and char holder
  FILE *ptemp_file, *porig_file, *porig_old;
  char temp_file[] = "file_temp.txt";
  char orig_file[] = "file.txt";
  char orig_old[] = "file.old";
  int c;

  // Open files
  ptemp_file = fopen(temp_file, "w+");
  porig_file = fopen(orig_file, "r");
  porig_old = fopen(orig_old, "w");

  // Prints original file contents, conver lowercase into uppercase
  printf("Original file:\n");
  while ((c = fgetc(porig_file)) != EOF) {
    printf("%c", c);
    // Save orig file content into backup file "file.old"
    fputc(c, porig_old);

    // converts the char case
    c = islower(c) ? (c - 32) : c;
    fputc(c, ptemp_file);
  }

  // Reset the pointer into the beginning
  rewind(ptemp_file);

  // Prints the new file contents
  printf("\nNew file:\n");
  while ((c = fgetc(ptemp_file)) != EOF)
    printf("\e[32m%c\e[0m", c);

  // Delete the original file
  remove(orig_file);
  // Rename the temp file into the original filename
  rename(temp_file, orig_file);

  fclose(ptemp_file);
  fclose(porig_file);
  fclose(porig_old);
  return 0;
}
