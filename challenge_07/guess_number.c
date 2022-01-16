/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random seed
  time_t t;
  srand((unsigned)time(&t));

  // Initialize random number 0-20
  int random_number = rand() % 21;

  // Initialize variable
  int guess_number;
  char *comparison;
  char *tries;

  // Loop statement to get number from the user
  // and checks if it equal to the random number
  for (int count = 1; count < 6; ++count) {
    printf("Guess the number: ");
    scanf("%d", &guess_number);

    if (guess_number > 20) {
      printf("Please pick between 0 and 20.\n");
      return 1;
    }

    if (guess_number == random_number) {
      printf("\nYou're right, congratulations!!\n");
      tries = (count == 1) ? "y" : "ies";
      printf("You guessed it within %d tr%s\n", count, tries);
      return 0;
    } else {
      comparison = (guess_number < random_number) ? "more" : "less";
      printf("Sorry, %d is wrong. The number is %s that.\n", guess_number,
             comparison);
    }
  }

  printf("\nYou've tried 5 times already. The number is %d. Try again next "
         "time.\n",
         random_number);
  return 0;
}
