#include <stdio.h>
#include <stdlib.h>

typedef struct historynode {
    int product_id;
    struct historynode* left;
    struct historynode* right;
} HistoryNode;

typedef struct userhistory {
    int user_id;
    HistoryNode* root;
    struct userhistory* next;
} UserHistory;

UserHistory* history_list = NULL;

// used to create a new history node with product id
HistoryNode* createHistoryNode(int product_id) {
    HistoryNode* node = (HistoryNode*)malloc(sizeof(HistoryNode));
    node->product_id = product_id;
    node->left = node->right = NULL;
    return node;
}

// used to insert a product id into the history bst
HistoryNode* insertHistory(HistoryNode* root, int product_id) {
    if(root == NULL) {
        return createHistoryNode(product_id);
    }
    if(product_id < root->product_id) {
        root->left = insertHistory(root->left, product_id);
    } else if(product_id > root->product_id) {
        root->right = insertHistory(root->right, product_id);
    }
    return root;
}

// used to add a product id to a users browsing history
void addToHistory(int user_id, int product_id) {
    UserHistory* current = history_list;
    while(current != NULL) {
        if(current->user_id == user_id) {
            current->root = insertHistory(current->root, product_id);
            return;
        }
        current = current->next;
    }
    
    UserHistory* new_history = (UserHistory*)malloc(sizeof(UserHistory));
    new_history->user_id = user_id;
    new_history->root = createHistoryNode(product_id);
    new_history->next = history_list;
    history_list = new_history;
}

// used to print the product ids in history bst
void printHistoryTree(HistoryNode* root) {
    if(root != NULL) {
        printHistoryTree(root->left);
        printf("%d ", root->product_id);
        printHistoryTree(root->right);
    }
}

// used to display the browsing history of a user
void displayUserHistory(int user_id) {
    UserHistory* current = history_list;
    while(current != NULL) {
        if(current->user_id == user_id) {
            printf("\nbrowsing history for user %d: ", user_id);
            printHistoryTree(current->root);
            printf("\n");
            return;
        }
        current = current->next;
    }
    printf("no history found for user %d\n", user_id);
}