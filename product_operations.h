/*****************************************************************
 
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

struct product
{
    char name[15];
    char unit[10];
    int price, quantity;
};

typedef struct product p;

struct node
{
    struct product p;
    struct node *next;
};

typedef struct node ELEMENT;

void welcome_msg();
int empty_list();
struct product create_product(char name[], char unit[], int price,
                   int quantity);
int to_string(struct product);
void insert_product(ELEMENT *head);
int list_add(ELEMENT *head, struct product p);
int delete_item(ELEMENT **head, char p_name[15]);
void delete_list(ELEMENT **head);
int search(ELEMENT *head, char p_name[15]);
void print_list(ELEMENT *head);
int purchase(ELEMENT *head, char p_name[15]);
int sell(ELEMENT **head, char p_name[15]);
int file_string(ELEMENT *head, char* str);
int write_file( char* filename, char *buffer, int size );
