# Simple User and Product Management System

This is a basic C program designed to manage user and product information efficiently. It uses hash tables for organizing products and binary trees to track user browsing history. The entire program is contained in a single `main.c` file for simplicity.

---

## Features

### 1. **User Management**
- Create new users.
- Look up existing users.
- Update user details.

### 2. **Product Management**
- Add new products to the system.
- Update product details.
- View the full list of available products.

Products are stored in a **hash table**, grouped by their category:
- **Collision Handling:** The hash table uses **separate chaining** to manage collisions effectively.
- **Recommendations:** This grouping helps in providing relevant product recommendations to users.

### 3. **Browsing History**
- Each user has a **browsing history** stored as a **binary search tree (BST)**.
- When a user buys a product:
  - The product is added to their browsing history.
  - The system provides recommendations for similar products based on category.

### 4. **Buying Products and Recommendations**
- Users can browse a list of all available products and purchase items by their respective ID.
- When a product is purchased:
  - It is added to the user’s browsing history.
  - The system recommends other similar products from the same category.

---

## How It Works

### Products
- Stored in a **hash table**, where each category has its own **linked list** for related products.
- This design ensures easy access to similar items and improves recommendations.

### Browsing History
- Stored as a **binary search tree (BST)** for efficient insertion and retrieval.
- Helps display browsing history quickly and intuitively.

---

## Compilation and Execution

1. **Compile the Program**
   Use a C compiler like `gcc`:
   ```bash
   gcc main.c user.c product.c history.c recomendation.c -o shopping_system
   ```
   
2. **Run the Program**
   execute the compiled program with the following command:
   ```bash
   ./shopping_system
   ```
