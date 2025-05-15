#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data structures here
typedef struct Node{
    char name[50];
    float price;
    int quantity;
    struct Node* next;
}Product;

typedef struct list{
    int orderId[100];
    int count;
}OrderIDs;



	// Write functions here

Product* createProduct(char name[], float price, int quantity){
    Product* head = malloc (sizeof(Product));
    if (head ==NULL){
        printf("memory alloc failed");
        exit(1);
    }
    strcpy(head->name, name);
    head->price = price;
    head->quantity = quantity;
    head->next = NULL;
    
    
    return head;
}

void addProductToCart(Product** head, char name[], float price, int quantity){
    
    Product* newNode = createProduct(name, price, quantity);
    
    if (*head == NULL){
        *head = newNode;
        return;
    } 
        
        Product* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
           
        }
        
        temp->next = newNode;
        return;
    
    
}

void removeProductFromCart(Product** head, char name[]){
    Product* temp = *head;
    Product* prev = NULL;
    while(temp != NULL){
        if (strcmp(temp->name, name) == 0){
            if(prev == NULL){
                *head = temp->next;
            } else {
                prev->next = temp->next; //skip the thingy
            }
            free(temp);
            
            printf("Product '%s' removed from cart.\n", name);
            return;
        } 
        
        prev = temp;
        temp = temp->next; 
        
    }
    
    printf("Product '%s' not found in cart.\n", name);
    
    
}

void displayCart (Product* head){
    printf("\nShopping Cart:\n");
    float totalPrice = 0.0;
    Product* temp = head;
    
    if (head == NULL){
        printf("Your cart is empty.\n");
        return;
    }
    
    
    while (temp != NULL){
        printf("- %s (Quantity: %d, Price: %.2f)\n", temp->name, temp->quantity, temp->price);
        
        totalPrice += temp->price*temp->quantity;
        temp = temp->next;
    }
    
    printf("Total: %.2f\n", totalPrice);    
    
}

int checkout(Product** head, OrderIDs* list){
    if (*head == NULL){
        printf("Cannot checkout. Your cart is empty.\n");
        return -1; //cart empty
    }
    
    int id = 1000;
    list->count++;
    
    id += list->count;
    list->orderId[list->count] = id;
    
    
    Product* temp;
    
    while (*head != NULL){
        temp = *head;
        *head = temp->next;
        free(temp);
    }
    
    printf("Checkout successful! Your Order ID is: %d\n", id);
    
    return id;
    
    
}

void displayOrderIDs(OrderIDs* IDS){
    printf("\nOrder IDs:\n");
    if (IDS->count == 0){
        printf("No orders yet.\n");
        return;
    }
    for (int i = 1 ; i <= IDS->count; i++){
        printf("- %d\n", IDS->orderId[i]);
    }
    
    
}

void runTestCases() {
    int testCase;
    Product* cart = NULL;
    OrderIDs orderList = {0};

    printf("\nSelect a Test Case:\n");
    printf("1. Empty Cart Checkout\n");
    printf("2. Add and Remove Multiple Items\n");
    printf("3. Checkout with Multiple Items\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &testCase);

    switch (testCase) {
        case 1:
            printf("\nRunning Test Case 1: Empty Cart Checkout\n");
            int emptyCartOrderId = checkout(&cart, &orderList);
            if (emptyCartOrderId == -1) {
                printf("  PASS: Checkout on empty cart returns -1\n");
            } else {
                printf("  FAIL: Checkout on empty cart should return -1, but returned %d\n", emptyCartOrderId);
            }
            displayCart(cart);
            displayOrderIDs(&orderList);
            break;
        case 2:
            printf("\nRunning Test Case 2: Add and Remove Multiple Items\n");
            addProductToCart(&cart, "Item1", 10.0, 3);
            addProductToCart(&cart, "Item2", 20.0, 1);
            addProductToCart(&cart, "Item3", 5.0, 5);
            displayCart(cart);
            removeProductFromCart(&cart, "Item2");
            displayCart(cart);
            removeProductFromCart(&cart, "NonExistentItem");
            displayCart(cart);
            // Free memory
            while (cart) {
                Product* next = cart->next;
                free(cart);
                cart = next;
            }
            break;
        case 3:
            printf("\nRunning Test Case 3: Checkout with Multiple Items\n");
            addProductToCart(&cart, "Product1", 100.0, 2);
            addProductToCart(&cart, "Product2", 50.0, 3);
            int orderId = checkout(&cart, &orderList);
            if (orderId != -1) {
                printf("  PASS: Checkout successful, Order ID: %d\n", orderId);
            } else {
                printf("  FAIL: Checkout failed\n");
            }
            displayCart(cart);
            displayOrderIDs(&orderList);
            break;
        case 0:
            printf("Exiting Test Cases.\n");
            break;
        default:
            printf("Invalid test case choice.\n");
    }
    // Free memory
    while (cart) {
        Product* next = cart->next;
        free(cart);
        cart = next;
    }
}

int main() {
    Product* shoppingCart = NULL;
    OrderIDs orderList = {0}; // Initialize order count

    // Add some products to the cart
    addProductToCart(&shoppingCart, "Laptop", 1200.00, 1);
    addProductToCart(&shoppingCart, "Mouse", 25.00, 2);
    addProductToCart(&shoppingCart, "Keyboard", 75.00, 1);

    displayCart(shoppingCart);

    // Remove a product
    removeProductFromCart(&shoppingCart, "Mouse");
    displayCart(shoppingCart);

    // Checkout
    int orderId = checkout(&shoppingCart, &orderList);
    if (orderId != -1) {
        printf("Order placed successfully. Order ID: %d\n", orderId);
    }
    displayCart(shoppingCart); // Show empty cart after checkout

    // Add another order
    addProductToCart(&shoppingCart, "Monitor", 300.00, 1);
    int orderId2 = checkout(&shoppingCart, &orderList);
     if (orderId2 != -1) {
        printf("Order placed successfully. Order ID: %d\n", orderId2);
    }
    displayOrderIDs(&orderList);

    runTestCases();
    return 0;
}