/*****************************************************************
 Header file for all the function operations.
 
 @author Joshua Crum
 @version 01 November 2017
 *****************************************************************/
#ifndef product_operations_h
#define product_operations_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#endif /* product_operations_h */


/*****************************************************************
 Structure for a product with a name, unit of measurement, price
 and quantity.
 *****************************************************************/
struct product
{
    char name[15];
    char unit[10];
    int price, quantity;
};
typedef struct product p;


/*****************************************************************
 Structure for a node in a linked list. Each node contains a
 product and a pointer to the next node.
 *****************************************************************/
struct node
{
    struct product p;
    struct node *next;
};
typedef struct node ELEMENT;


/*****************************************************************
 Creates a product that has a name, a unit of measurement, a price
 and a quantity.
 
 @param name the name of the product.
 @param unit the unit of measurement of the product.
 @param price the int price of the product.
 @param quantity the int quantity of the product.
 @return struct product the product that was created.
 *****************************************************************/
struct product create_product(char name[], char unit[],
                              int price, int quantity);


/*****************************************************************
 Deletes a product from the linked list based on its name.
 
 @param head a pointer to the pointer to the head node in the list.
 @param p_name the name of the product to be deleted.
 @return int 1 if delete was successful, 0 if otherwise.
 *****************************************************************/
int delete_item(ELEMENT **head, char p_name[15]);


/*****************************************************************
 Deletes the entire list.
 
 @param head a pointer to the pointer to the head node in the list.
 *****************************************************************/
void delete_list(ELEMENT **head);


/*****************************************************************
 Puts all products into a single string to be passed to
 write_file.
 
 @param head a pointer to the head node in the linked list.
 @param str an empty allocated string to store the products in.
 @return 0 after the string has been created.
 *****************************************************************/
int file_string(ELEMENT *head, char* str);


/*****************************************************************
 Gathers user input to create a product to pass to list_add.
 
 @param head a pointer to the head node in the linked list.
 *****************************************************************/
void insert_product(ELEMENT *head);


/*****************************************************************
 Adds a created product into the linked list.
 
 @param head a pointer to the head node in the linked list.
 @param prod the product to be added to the linked list.
 @return int 1 if product was added successfully, 0 otherwise.
 *****************************************************************/
int list_add(ELEMENT *head, struct product prod);


/*****************************************************************
 Prints all products in the list.
 
 @param head a pointer to the head node in the linked list.
 *****************************************************************/
void print_list(ELEMENT *head);


/*****************************************************************
 Purchases a product by increasing the quantity if the product
 exists.
 
 @@param head a pointer to the head node in the linked list.
 @param p_name the name of the product to purchase.
 @return int 1 if purchase was successful, 0 if not.
 *****************************************************************/
int purchase(ELEMENT *head, char p_name[15]);


/*****************************************************************
 Sells a product by decreasing the quantity if the product exists.
 
 @param head a pointer to the head node in the linked list.
 f@param p_name the name of the product to sell.
 *****************************************************************/
int sell(ELEMENT **head, char p_name[15]);


/*****************************************************************
 Search for a product in the list by name.
 
 @param head a pointer to the head node in the linked list.
 @param p_name the name of the product to search for.
 @return 1 if the product was found, 0 if not.
 *****************************************************************/
int search(ELEMENT *head, char p_name[15]);


/*****************************************************************
 Prints out the contents of a product struct.
 
 @param p the product to print out.
 *****************************************************************/
void to_string(struct product p);


/*****************************************************************
 Write the contents of the buffer into a new or existing file.
 
 @param filename the name of the output file to write to.
 @param buffer the char array from which to write.
 @param size the number of elements to write to the output file.
 @return int 0 if the code executed correctly, 1 otherwise.
 *****************************************************************/
int write_file( char* filename, char *buffer, int size );


/*****************************************************************
 Prints out the welcome message with a list of possible commands
 to enter.
 *****************************************************************/
void welcome_msg();
