/*****************************************************************
 
 @author Joshua Crum
 @version 01 November 2017
 *****************************************************************/
 
#include "product_operations.h"



/*****************************************************************
 
 *****************************************************************/
struct product create_product(char name[], char unit[],
                   int price, int quantity)
{
    struct product p;
    strcpy(p.name, name);
    strcpy(p.unit, unit);
    p.price = price;
    p.quantity = quantity;
    
    return p;
}


/*****************************************************************
 
 *****************************************************************/
int to_string(struct product p)
{
    printf("Name: %s\t Unit: %s\t Price: $%d\t Quantity: %d\t\n",
           p.name, p.unit, p.price, p.quantity);
    return 0;
}


/*****************************************************************
 
 *****************************************************************/
void insert_product(ELEMENT *head)
{
    char name[15];
    char unit[10];
    int price, quantity;
    
    printf("Enter a name for the product: ");
    scanf("%s", name);
    
    printf("Enter a unit of measurement for '%s': ", name);
    scanf("%s", unit);
    
    printf("Enter the price of '%s': ", name);
    scanf("%d", &price);
    
    printf("Enter the quantity of '%s': ", name);
    scanf("%d", &quantity);
    
    struct product temp = create_product(name, unit,
                                           price, quantity);
    list_add(head, temp);
}


/*****************************************************************
 
 *****************************************************************/
int list_add(ELEMENT *head, struct product prod)
{

    if (strcmp(head -> p.name, "") == 0 &&
        head -> next == NULL) {
        
        strcpy(head -> p.name, prod.name);
        strcpy(head -> p.unit, prod.unit);
        head -> p.price = prod.price;
        head -> p.quantity = prod.quantity;
        
        return 1;
    }
    
    struct node *temp = head;
    
    while (temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = (ELEMENT*) malloc(sizeof(ELEMENT));
                
    strcpy(temp -> next -> p.name, prod.name);
    strcpy(temp -> next -> p.unit, prod.unit);
    temp -> next -> p.price = prod.price;
    temp -> next -> p.quantity = prod.quantity;
                
    temp -> next -> next = NULL;
        
    return 0;
}


/*****************************************************************
 
 *****************************************************************/
void welcome_msg()
{
    printf("1: Create an empty list \t 2: Insert a product\n"
           "3: Delete a product \t\t 4: Delete the entire list\n"
           "5: Search a product \t\t 6: Display products in the "
           "list\n"
           "7: Purchase a product \t\t 8: Sell a product\n"
           "9: Save to file \t\t 0: Exit\n\n");
}


/*****************************************************************
 
 *****************************************************************/
int delete_item(ELEMENT **head, char p_name[15])
{
    struct node *p = *head;
    struct node *q;
    
    //Node is head of list.
    if ( strcmp((*head) -> p.name, p_name) == 0 ) {
        *head = (*head) -> next;
        free(p);
        return 1;
    }
    
    //Node is in the middle.
    while (p != NULL) {
        
        if ( strcmp(p -> next -> p.name, p_name) == 0 ) {
            q = p -> next;
            p -> next = p -> next -> next;
            free(q);
            return 1;
        }
        
        p = p -> next;
    }
    
    return 0;
}


/*****************************************************************
 
 *****************************************************************/
void delete_list(ELEMENT **head)
{
    struct node *p = *head;
    struct node *q;
    
    while (p != NULL) {
        q = p -> next;
        free(p);
        p = q;
    }
    
    *head = NULL;
}


/*****************************************************************
 
 *****************************************************************/
int search(ELEMENT *head, char p_name[15])
{
    while (head != NULL) {
        if (strcmp(head -> p.name, p_name) == 0) {
            return 1;
        }
        head = head -> next;
    }
    
    return 0;
}


/*****************************************************************
 
 *****************************************************************/
void print_list(ELEMENT *head)
{
    
}





