/*****************************************************************
 
 @author Joshua Crum
 @version 01 November 2017
 *****************************************************************/
 
#include "product_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*****************************************************************
 
 *****************************************************************/
int empty_list(ELEMENT *head)
{
    head = (ELEMENT*) malloc(sizeof(ELEMENT));
    return 0;
}


/*****************************************************************
 
 *****************************************************************/
int create_product(ELEMENT *head, char* name, char* unit,
                   int price, int quantity)
{
    head = (ELEMENT*) malloc(sizeof(ELEMENT));
    head -> s = name;
    
    head -> next = (ELEMENT *) malloc(sizeof(ELEMENT));
    head -> next -> s = unit;
    
    head -> next -> next = (ELEMENT *) malloc(sizeof(ELEMENT));
    head -> next -> next -> d = price;
    
    head -> next -> next -> next =
        (ELEMENT *) malloc(sizeof(ELEMENT));
    head -> next -> next -> next -> d = quantity;
    
    head -> next -> next -> next -> next = NULL;
    
    return 0;
}


