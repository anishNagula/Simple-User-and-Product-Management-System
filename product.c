#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSIZE 10

typedef struct Product {
  int id;
  char name[50];
  char category[20];
  struct Product* next;
} Product;

// creating the table
Product* product_table[CSIZE];


// we use this function to get the respective index of the table
int cHash(char* category) {
  int sum = 0;
  for(int i = 0; category[i]; i++) {
    sum += category[i];
  }
  return sum % CSIZE;
}

// used to set the default values of the table as null
void initProductTable() {
  for(int i = 0; i < CSIZE; i++) {
    product_table[i] = NULL;
  }
}

//code to create a new product
void addProduct(int id, char* name, char* category) {
  int index = cHash(category);
  Product* new_product = (Product*)malloc(sizeof(Product));
  new_product->id = id;
  strcpy(new_product->name, name);
  strcpy(new_product->category, category);
  new_product->next = NULL;

  if(product_table[index] == NULL) {
    product_table[index] = new_product;
  } else {
    new_product->next = product_table[index];
    product_table[index] = new_product;
  }
}

//code to get product details
Product* getProduct(int id) {
  for(int i = 0; i < CSIZE; i++) {
    Product* current = product_table[i];
    while(current != NULL) {
      if(current->id == id) {
        return current;
      }
      current = current->next;
    }
  }
  return NULL;
}

//code to update product details using its id as input;
int updateProduct(int id, char* new_name) {
  Product* product = getProduct(id);
  if(product == NULL) {
    return 0;
  }

  strcpy(product->name, new_name);
  
  return 1;
}

//code to display product details using its id;
void displayProduct(int id) {
  Product* product = getProduct(id);
  if(product != NULL) {
    printf("product id: %d\n", product->id);
    printf("name: %s\n", product->name);
    printf("category: %s\n", product->category);
  } else {
    printf("product not found!\n");
  }
}

//code to display all product details present in the table
void displayProducts() {
  for(int i = 0; i < CSIZE; i++) {
    Product* current = product_table[i];
    if(current != NULL) {
      printf("\ncategory index %d:\n", i);
      while(current != NULL) {
        printf("id: %d, name: %s, category: %s\n",
        current->id, current->name, current->category);
        current = current->next;
      }
    }
  }
}