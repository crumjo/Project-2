/*****************************************************************
 
 @author Joshua Crum
 @version 01 November 2017
 *****************************************************************/

#include "product_operations.h"

int main(int argc, char** argv) {
    
    welcome_msg();
    
    int initial = 0;
    scanf("%d", &initial);
    while (initial != 1) {
        printf("Enter a 1 to initialize an empty list first.\n");
        scanf("%d", &initial);
    }
    ELEMENT *head = (ELEMENT *) malloc(sizeof(ELEMENT));
    head -> next = NULL;
    printf("Empty list created.\n");
    
    int com = -1;
    scanf("%d", &com);
    while (com != 0) {
        scanf("%d", &com);
        
        if (com == 2) {
            insert_product(head);
            printf("Product added to list.\n");
        }
        
        if (com == 3) {
            char p_name[15];
            printf("Enter the name of the product to delete: ");
            scanf("%s\n", p_name);
            
            if (search(head, p_name) == 1) {
                delete_item(&head, p_name);
            } else {
                printf("The product '%s' does not exist.", p_name);
            }
        }
        
        if (com == 4) {
            delete_list(&head);
            printf("List deleted.");
        }
        
        if (com == 6) {
            print_list(head);
        }
        
    }
    
    delete_list(&head);
    exit(0);
    
    return 0;
}
