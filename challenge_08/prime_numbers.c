/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * Create a program that will find all the prime numbers from 3-100
 * * No input to the program
 * * The output will be each prime number separated by a space on a single line
 * * Create an array that will store each prime number as it iIs generated
 * * Hard-code the first two prime numbers (2 and 3) in the primes array
 * * Utilize loops to only find prime numbers up to 100 and a loop to print out
 *   the primes array
 */
#include <stdbool.h>
#include <stdio.h>

/* References:
 * * https://math.stackexchange.com/questions/783393/a-quick-way-to-determine-whether-a-number-is-prime-by-hand/783414
 * * https://www.geeksforgeeks.org/prime-numbers/
 */
bool isPrime(int n) {
  static int i = 2;

  // Corner cases
  if (n == 0 || n == 1)
    return false;

  // Checking Prime
  if (n == i)
    return true;

  // Base cases
  if (n % i == 0)
    return false;

  // Edge cases
  if (n == 5)
    return true;

  if ((n % 3 == 0) || (n % 5 == 0) || (n % 7 == 0))
    return false;

  ++i;
  return isPrime(n);
}

int main() {
  // Initialize variables
  int primes[50] = {2, 3};
  int i, j;

  // Iterate through odd numbers from 5 up to 100
  for (i = 5, j = 2; i < 101; i += 2, ++j) {
    if (isPrime(i))
      primes[j] = i;
  }

  // Print the elements of primes
  for (i = 0; i < 50; ++i) {
    if (primes[i] != 0)
      printf("%d ", primes[i]);

    if (i == 49)
      printf("\n");
  }

  return 0;
}
