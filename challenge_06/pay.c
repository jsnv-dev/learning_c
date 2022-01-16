/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 */
#include <stdio.h>

int main() {
  // Intialize variables
  double hours;
  double pay_rate = 12.00;
  double gross_pay;
  double net_pay;
  double taxes;

  // Get working hours from the user
  printf("Input your working hours this week: ");
  scanf("%lf", &hours);

  // Calculates Gross pay
  /* Basic pay rate = $12.00/hr
   * Overtime (in excess of 40 hours) = time and a half
   */
  if (hours > 40) {
    gross_pay = 40 * pay_rate + (hours - 40) * 1.5 * pay_rate;
  } else {
    gross_pay = hours * pay_rate;
  }

  // Calculates taxes
  /* Tax rate:
   *   - 15% of the first $300
   *   - 20% of the next $150
   *   - 20% of the rest
   */
  if (gross_pay > 450) {
    taxes = (gross_pay - 450) * .25 + (150 * .2) + (300 * .15);
  } else if (gross_pay > 300) {
    taxes = (gross_pay - 300) * .2 + (300 * .15);
  } else {
    taxes = gross_pay * .15;
  }

  // Calculates Net pay
  net_pay = gross_pay - taxes;

  printf("Total working hours: %.2f\n", hours);
  printf("Gross Pay: %.2f\n", gross_pay);
  printf("Total Tax: %.2f\n", taxes);
  printf("Net Pay: %.2f\n", net_pay);
  return 0;
}
