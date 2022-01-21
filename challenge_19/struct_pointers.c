/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * Write a C program that creates a structure pointer and passes it to a
 *   function
 *   * create a structure named item with the following members
 *     * itemName — pointer
 *     * quantity — int
 *     * price — float
 *     * amount — float (stores quantity * price)
 *   * create a function named readItem that takes a structure pointer of type
 *     item as a parameter
 *     * this function should read In (from the user) a product name, price, and
 *       quantity
 *     * the contents read in should be stored in the passed In structure to the
 *       function
 *   * create a function named print item that takes as a parameter a structure
 *     pointer of type item
 *     * function prints the contents of the parameter
 *   * the main function should declare an item and a pointer to the item
 *     * you will need to allocate memory for the itemName pointer
 *     * the item pointer should be passed into both the read and print item
 *       functions
 */
#include <stdio.h>
#include <stdlib.h>

// Defines read_item Structure
struct read_item {
  char *item_name;
  int quantity;
  float price;
  float amount;
};

void read_item(struct read_item *const items);
void print_item(const struct read_item *items);
// Explicitly declare library function
unsigned long strcspn(const char *, const char *);

int main() {
  // Initialize Structure
  struct read_item user_input;

  // Initilize the pointer for the Structure
  struct read_item *puser_input = &user_input;

  // Create allocation for the item_name and return 0 if memory is not available
  if (!(puser_input->item_name = (char *)calloc(50, sizeof(char)))) {
    printf("\e[33mPlease re-run the program\e[0m\n");
    return 0;
  }

  read_item(puser_input);
  print_item(puser_input);
  free(puser_input->item_name);

  return 0;
}

// Get item details from the user
void read_item(struct read_item *const items) {
  printf("Please input Item Name: ");
  // Reads item name even with space char
  fgets(items->item_name, 50, stdin);
  // Removes the newline feed at the end of the user input string
  items->item_name[strcspn(items->item_name, "\n")] = 0;

  printf("Please input the Quantity: ");
  scanf("%i", &items->quantity);
  printf("Please input Price: ");
  scanf("%f", &items->price);
  // Computes the value of ammount base on quantity and price
  items->amount = items->quantity * items->price;
}

// Prints the item details
void print_item(const struct read_item *items) {
  printf("\n\e[32mSee item's details below:\e[0m\n");
  printf("\t- name: %s\n", items->item_name);
  printf("\t- quantity: %d\n", items->quantity);
  printf("\t- price: %.2f\n", items->price);
  printf("\t- amount: %.2f\n", items->amount);
}
