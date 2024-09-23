#include <stdio.h>
#include <string.h>

// Define a struct to represent a product
typedef struct {
    int code;
    char description[50];
    float unitPrice;
    int quantity;
} Product;

// Function prototypes
void addProduct(Product products[], int *size);
void consultProduct(Product products[], int size);
void listProducts(Product products[], int size);
void deleteProduct(Product products[], int *size);

int main() {
    int choice;
    int size = 0;
    Product products[100]; // Array to store up to 100 products

    while (1) {
        // Display menu
        printf("Menu:\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Consultar Produto para Alteração\n");
        printf("3. Listar todos os produtos\n");
        printf("4. Exclusão do Produto\n");
        printf("Enter your choice: ");

        // Read user input
        scanf("%d", &choice);

        // Call corresponding function based on user input
        switch (choice) {
            case 1:
                addProduct(products, &size);
                break;
            case 2:
                consultProduct(products, size);
                break;
            case 3:
                listProducts(products, size);
                break;
            case 4:
                deleteProduct(products, &size);
                break;
            default:
                printf("Invalid choice. Exiting...\n");
                return 1;
        }
    }

    return 0;
}

// Function to add a new product
void addProduct(Product products[], int *size) {
    printf("Enter product code: ");
    scanf("%d", &products[*size].code);
    printf("Enter product description: ");
    scanf("%49s", products[*size].description);
    printf("Enter unit price: ");
    scanf("%f", &products[*size].unitPrice);
    printf("Enter quantity: ");
    scanf("%d", &products[*size].quantity);
    (*size)++;
    printf("Product added successfully!\n");
}

// Function to consult and alter a product
void consultProduct(Product products[], int size) {
    int code;
    printf("Enter product code to consult: ");
    scanf("%d", &code);
    for (int i = 0; i < size; i++) {
        if (products[i].code == code) {
            printf("Product found!\n");
            printf("Description: %s\n", products[i].description);
            printf("Unit price: %.2f\n", products[i].unitPrice);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Enter new description (or press enter to keep current): ");
            scanf("%49s", products[i].description);
            printf("Enter new unit price (or press enter to keep current): ");
            scanf("%f", &products[i].unitPrice);
            printf("Enter new quantity (or press enter to keep current): ");
            scanf("%d", &products[i].quantity);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

// Function to list all products
void listProducts(Product products[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Product %d:\n", i + 1);
        printf("Code: %d\n", products[i].code);
        printf("Description: %s\n", products[i].description);
        printf("Unit price: %.2f\n", products[i].unitPrice);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Stock value: %.2f\n", products[i].quantity * products[i].unitPrice);
    }
}

// Function to delete a product
void deleteProduct(Product products[], int *size) {
    int code;
    printf("Enter product code to delete: ");
    scanf("%d", &code);
    for (int i = 0; i < *size; i++) {
        if (products[i].code == code) {
            printf("Product found!\n");
            printf("Are you sure you want to delete this product? (y/n): ");
            char response;
            scanf(" %c", &response);
            if (response == 'y') {
                for (int j = i; j < *size - 1; j++) {
                    products[j] = products[j + 1];
                }
                (*size)--;
                printf("Product deleted successfully!\n");
            } else {
                printf("Deletion cancelled.\n");
            }
            return;
        }
    }
    printf("Product not found!\n");
}