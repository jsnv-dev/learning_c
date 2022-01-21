/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * Write a program that declares a structure and prints out it's content
 *   * Create an employee structure with 3 members
 *     * name (character array)
 *     * hireDate (int)
 *     * salary (float)
 *   * Declare and initialize an instance of an employee type
 *   * Read In a second employee from the console and store it in a structure of
 *     type employee
 *   * Print out the contents of each employee
 */
#include <stdio.h>

int main() {
  // Define employee Structure
  struct employee {
    char name[100];
    int hire_date;
    float salary;
  };

  // Initialize first and second employee
  struct employee first_employee = {"Bob", 20220121, 1000000.00},
                  second_employee;

  // Get the details of the second employee
  printf("Please input second employee's name: ");
  scanf("%s", second_employee.name);
  printf("Please input second employee's hire_date: ");
  scanf("%i", &second_employee.hire_date);
  printf("Please input second employee's salary: ");
  scanf("%f", &second_employee.salary);

  // Print the details of the employees
  printf("\nFirst employee's details:\n\t- name: %s\n\t- hire date: %d\n\t- "
         "salary: %.2f\n",
         first_employee.name, first_employee.hire_date, first_employee.salary);
  printf("\nSecond employee's details:\n\t- name: %s\n\t- hire date: %d\n\t- "
         "salary: %.2f\n",
         second_employee.name, second_employee.hire_date,
         second_employee.salary);
  return 0;
}
