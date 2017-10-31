/*****************************************************************
 Main method for creating a linked list, adding and deleting
 products, purchasing and selling products, printing all the
 products in the list, and writing the list to a file.
 
 @author Joshua Crum
 @version 01 November 2017
 *****************************************************************/

#include "product_operations.h"

int main(int argc, char** argv) {
    
    //Print out the valid commands.
    welcome_msg();
    
    //User needs to enter a 1 to make a new list first.
    int initial = 0;
    scanf("%d", &initial);
    while (initial != 1) {
        printf("Press 1 to initialize an empty list first: ");
        scanf("%d", &initial);
    }
    
    //Make a new list after 1 is pressed.
    ELEMENT *head = (ELEMENT *) malloc(sizeof(ELEMENT));
    head -> next = NULL;
    printf("Empty list created.\n");
    
    //User's command is stored in com.
    int com = -1;
    while (com != 0) {
        scanf("%d", &com);
        
        //Add a new product to list.
        if (com == 2) {
            insert_product(head);
            printf("Product added to list.\n");
        }
        
        //Delete a product from the list.
        if (com == 3) {
            char p_name[15];
            printf("Enter the name of the product to delete: ");
            scanf("%s", p_name);
            
            if (search(head, p_name) != 1) {
                printf("The product '%s' does not exist.\n",
                       p_name);
            } else {
                int i = delete_item(&head, p_name);
                
                if (i != 0) {
                    printf("The product: '%s' has been deleted.\n",
                           p_name);
                }
                
            }
        
        }
        
        //Delete the entire list.
        if (com == 4) {
            delete_list(&head);
            printf("List deleted. Press 1 to create a new list.\n");
            
            int initial = 0;
            scanf("%d", &initial);
            
            //Prompt user to create a new list.
            while (initial != 1) {
                printf("Press 1 to initialize an empty list first: ");
                scanf("%d", &initial);
            }
            ELEMENT *head = (ELEMENT *) malloc(sizeof(ELEMENT));
            head -> next = NULL;
            printf("Empty list created.\n");
            
        }
        
        //Search for a product.
        if (com == 5) {
            char p_name[15];
            printf("Enter the name of the product to search for: ");
            scanf("%s", p_name);
            
            if (search(head, p_name) != 1) {
                printf("The product '%s' could not be found in the list.\n",
                       p_name);
            } else {
                printf("The product '%s' was found in the list.\n",
                       p_name);
            }
        }
        
        //Print the contents of the list.
        if (com == 6) {
            if (strcmp(head -> p.name, "") == 0 &&
                strcmp(head -> p.unit, "") == 0) {
                printf("The list is empty.\n");
            } else {
                print_list(head);
            }
        }
        
        //Purchase a product.
        if (com == 7) {
            char p_name[15];
            printf("Enter the name of the product to purchase: ");
            scanf("%s", p_name);
            
            if (search(head, p_name) != 1) {
                printf("The product '%s' could not be found in the list.\n",
                       p_name);
            } else {
                purchase(head, p_name);
                printf("The product '%s' has been purchased.\n",
                       p_name);
            }
        }
        
        //Sell a product.
        if (com == 8) {
            char p_name[15];
            printf("Enter the name of the product to sell: ");
            scanf("%s", p_name);
            
            if (search(head, p_name) != 1) {
                printf("The product '%s' could not be found in the list.\n",
                       p_name);
            } else {
                
                int x = sell(&head, p_name);
                
                if (x != 0) {
                    printf("The product '%s' has been sold.\n",
                           p_name);
                }
            }
        }
        
        //Write list to file 'out.txt'.
        if (com == 9) {
            int size = 1024 * sizeof(char);
            char* str = (char*) malloc(size);
            file_string(head, str);
            write_file("out.txt", str, size);
            printf("List has been saved to file 'out.txt'.\n");
        }
        
    }
    
    //Delete the list and exit when 0 is pressed.
    delete_list(&head);
    exit(0);
    
    return 0;
}
