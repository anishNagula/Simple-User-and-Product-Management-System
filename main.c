#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
  int id;
  char name[50];
  char password[50];
  struct User* next;
} User;

typedef struct Product {
  int id;
  char name[50];
  char category[20];
  float price;
  int stock;
  struct Product* next;
} Product;

void initUserTable();
void createUser(int id, char* name, char* password);
User* getUser(int id);
int updateUser(int id, char* new_name, char* new_password);
void displayUser(int id);
void initProductTable();
void addProduct(int id, char* name, char* category);
Product* getProduct(int id);
int updateProduct(int id, char* new_name);
void displayProduct(int id);
void displayProducts();
void recommendProduct(int product_id);
void addToHistory(int user_id, int product_id);
void displayUserHistory(int user_id);

void displayMenu() {
  printf("\n=== Shopping System ===\n");
  printf("1. Create new user\n");
  printf("2. Update user details\n");
  printf("3. Display user details\n");
  printf("4. Add new product\n");
  printf("5. Update product details\n");
  printf("6. Display product details\n");
  printf("7. Display all products\n");
  printf("8. Buy product\n");
  printf("9. View user history\n");
  printf("10. Exit\n");
  printf("Enter your choice: ");
}

int main() {
  initUserTable();
  initProductTable();
  
  // we added some sample data to start of the program
  addProduct(1, "Laptop", "Electronics");
  addProduct(2, "Smartphone", "Electronics");
  addProduct(3, "Headphone", "Electronics");
  addProduct(4, "T-shirt", "Clothing");
  addProduct(5, "Jeans", "Clothing");
  
  int choice;
  do {
    displayMenu();
    scanf("%d", &choice);
    
    switch(choice) {
      case 1: {
        int id;
        char name[50], password[50];
        printf("Enter user ID: ");
        scanf("%d", &id);
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter password: ");
        scanf("%s", password);
        createUser(id, name, password);
        printf("User created successfully!\n");
        break;
      }
      case 2: {
        int id;
        char name[50], password[50];
        printf("Enter user ID to update: ");
        scanf("%d", &id);
        printf("Enter new name: ");
        scanf("%s", name);
        printf("Enter new password: ");
        scanf("%s", password);
        if(updateUser(id, name, password)) {
          printf("User updated successfully!\n");
        } else {
          printf("User not found!\n");
        }
        break;
      }
      case 3: {
        int id;
        printf("Enter user ID: ");
        scanf("%d", &id);
        displayUser(id);
        break;
      }
      case 4: {
        int id;
        char name[50], category[20];
        printf("Enter product ID: ");
        scanf("%d", &id);
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter category: ");
        scanf("%s", category);
        addProduct(id, name, category);
        printf("Product added successfully!\n");
        break;
      }
      case 5: {
        int id;
        char name[50], category[20];
        float price;
        printf("Enter product ID to update: ");
        scanf("%d", &id);
        printf("Enter new name: ");
        scanf("%s", name);
        if(updateProduct(id, name)) {
          printf("Product updated successfully!\n");
        } else {
          printf("Product not found!\n");
        }
        break;
      }
      case 6: {
        int id;
        printf("Enter product ID: ");
        scanf("%d", &id);
        displayProduct(id);
        break;
      }
      case 7: {
        displayProducts();
        break;
      }
      case 8: {
        int user_id, product_id;
        printf("Enter user ID: ");
        scanf("%d", &user_id);
        displayProducts();
        printf("Enter product ID to buy: ");
        scanf("%d", &product_id);
        
        User* user = getUser(user_id);
        Product* product = getProduct(product_id);
        
        if(user && product) {
          addToHistory(user_id, product_id);
          printf("Product purchased successfully!\n");
          recommendProduct(product_id);
        } else {
          printf("Invalid user or product ID!\n");
        }
        break;
      }
      case 9: {
        int user_id;
        printf("Enter user ID: ");
        scanf("%d", &user_id);
        displayUserHistory(user_id);
        break;
      }
      case 10:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice! Please try again.\n");
    }
  } while(choice != 10);
  
  return 0;
}