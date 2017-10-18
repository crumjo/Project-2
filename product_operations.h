/*****************************************************************
 
 @author Joshua Crum
 @version 01 November 2017
 *****************************************************************/

#ifndef product_operations_h
#define product_operations_h

#include <stdio.h>

#endif /* product_operations_h */

struct node
{
    char* s;
    int d;
    struct node *next;
};

typedef struct node ELEMENT;


int empty_list();
int create_product(ELEMENT *head, char* name, char* unit, int price, int quantity);
