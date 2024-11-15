#include <stdio.h>

typedef struct Product {
  int id;
  char name[50];
  char category[20];
  struct Product* next;
} Product;

// get product table from product.c file
extern Product* product_table[];

// using chash and getProduct to get the related products
int cHash(char* category);
Product* getProduct(int id);

// traverses the list of all related products and prints them as recomendation
void recommendProduct(int product_id) {
  Product* product = getProduct(product_id);
  if(product == NULL) return;

  printf("\nrecommended products in category %s:\n", product->category);
  int index = cHash(product->category);
  Product* current = product_table[index];
    

  int count = 0;
  while(current != NULL && count < 3) {
  if(current->id != product_id) {
    printf("id: %d, name: %s",
    current->id, current->name);
    count++;
  }
  current = current->next;
  }
  printf("\n");
}