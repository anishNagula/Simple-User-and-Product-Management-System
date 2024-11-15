#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USIZE 100

typedef struct User {
	int id;
	char name[50];
	char password[50];
	struct User* next;
} User;

// creating the table
User* user_table[USIZE];


// we use this function to get the respective index of the table
int hash(int id) {
	return id % USIZE;
}

// used to set the default values of the table as null
void initUserTable() {
	for(int i = 0; i < USIZE; i++) {
		user_table[i] = NULL;
	}
}

//code to create a new user
void createUser(int id, char* name, char* password) {
	int index = hash(id);
	User* new_user = (User*)malloc(sizeof(User));
	new_user->id = id;
	strcpy(new_user->name, name);
	strcpy(new_user->password, password);
	new_user->next = NULL;

	if(user_table[index] == NULL) {
		user_table[index] = new_user;
	} else {
		new_user->next = user_table[index];
		user_table[index] = new_user;
	}
}

//code to get user details
User* getUser(int id) {
	int index = hash(id);
	User* current = user_table[index];
	while(current != NULL) {
		if(current->id == id) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

//code to update user details using his id as input;
int updateUser(int id, char* new_name, char* new_password) {
	int index = hash(id);
	User* current = user_table[index];
	
	while(current != NULL) {
		if(current->id == id) {
			strcpy(current->name, new_name);
			strcpy(current->password, new_password);
			return 1;
		}
		current = current->next;
	}
	return 0;
}

//code to display user details using his id;
void displayUser(int id) {
	User* user = getUser(id);
	if(user != NULL) {
		printf("user id: %d\n", user->id);
		printf("name: %s\n", user->name);
		printf("password: %s\n", user->password);
	} else {
		printf("user not found!\n");
	}
}