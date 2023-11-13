#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 5
#define USERNAME_LENGTH 50
#define PASSWORD_LENGTH 50

typedef struct
{
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} User;
union type
{
    bool isActive;

} activation;
User users[MAX_USERS];
int num_Users = 0;

void registerUser()
{
    if (num_Users >= MAX_USERS)
    {
        printf("Maximum number of users reached.\n");
        // i used exit when use retun the loop is infinity but exit(0) print and close program.

        exit(0);
    }

    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);

    // Check if the username already exists
    for (int i = 0; i < num_Users; i++)
    {
        if (strcmp(users[i].username, newUser.username) == 0)
        {
            printf("Username already exists. Please choose a different username.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[num_Users] = newUser;
    num_Users++;
    printf("Have you Active true[1],false[0]: ");
    scanf("%d", &activation.isActive);

    printf("Registration successful.\n");
}

void loginUser()
{
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < num_Users; i++)
    {
        if (activation.isActive && strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            printf("Login successful.\n");
            return;
        }
    }

    printf("Invalid username or password or Activetion is false[0].\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }
}