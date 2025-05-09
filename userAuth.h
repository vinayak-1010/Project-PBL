
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_USERS 100
#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define USER_FILE "users.txt"

struct User {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
};

// Function to register a new user
void registerUser() {
    struct User newUser;
    FILE *file = fopen(USER_FILE, "a");


    printf("Enter new username: ");
    scanf("%s", newUser.username);
    printf("Enter new password: ");
    scanf("%s", newUser.password);

    fprintf(file, "%s %s\n", newUser.username, newUser.password);
    fclose(file);

    printf("User registered successfully.\n");
}

// Function to authenticate user login
int loginUser() {
    struct User user;
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    int authenticated = 0;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *file = fopen(USER_FILE, "r");

    if (file == NULL) {
        printf("No registered users found. Please register first.\n");
        return 0;
    }

    while (fscanf(file, "%s %s", user.username, user.password) != EOF) {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            authenticated = 1;
            break;
        }
    }

    fclose(file);

    if (authenticated) {
        
        printf("Login successful. Welcome, %s!\n", username);
          
        return 1;
    } else {
        printf("Invalid username or password.\n");
        return 0;
    }
}

// Menu to choose between login and registration
bool authMenu() {
    int choice;
    do {
        printf("\nUser Authentication Menu:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    printf("Access granted.\n");  
                return true;
                }
                break;
            case 3:
                printf("Exiting authentication module.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
}


