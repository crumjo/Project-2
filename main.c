/*****************************************************************
 
 @author Joshua Crum
 @version 01 November 2017
 *****************************************************************/

#include "product_operations.h"

int main(int argc, char** argv) {
    
    welcome_msg();

    ELEMENT *head = (ELEMENT *) malloc(sizeof(ELEMENT));
    head -> next = NULL;
    
    insert_product(head);
    
    return 0;
}
