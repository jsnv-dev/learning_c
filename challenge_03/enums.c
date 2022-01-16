/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 */
#include <stdio.h>

int main() {
  // Create custom enum
  enum company { GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT };

  // Declare company variables
  enum company google = GOOGLE;
  enum company xerox = XEROX;
  enum company ebay = EBAY;

  printf("Xerox has value of: %i\n", xerox);
  printf("Google has value of: %i\n", google);
  printf("Ebay has value of: %i\n", ebay);
  return 0;
}
