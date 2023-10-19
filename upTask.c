#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int id;
    char username[50];
    char password[50];

} UserInfo;

typedef struct
{
    bool active; // 0: not active, 1: active
} UserStatus;

typedef union test
{
    UserInfo info;
    UserStatus status;
} User;

User users[10];
int user_count = 0;

void register_user()
{
    User new_user;
    bool active;

    printf("Enter a username: ");
    scanf("%s", new_user.info.username);

    printf("Enter a password: ");
    scanf("%s", new_user.info.password);

    printf("Enter active status (0: not active, 1: active): ");
    scanf("%d", &active);

    new_user.info.id = user_count + 1;
    new_user.status.active = active;

    users[user_count++] = new_user;
    printf("Registration successful!\n");
}

int login()
{
    char username[50];
    char password[50];

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(users[i].info.username, username) == 0 && strcmp(users[i].info.password, password) == 0)
        {

            if (users[i].status.active == 1)
            {
                printf("Logged in successfully.\n");
                return 1;
            }
            else
            {
                printf("UserAccount is not active.\n");
                printf("Disable to Login\n");
                return 0;
            }
        }
    }

    printf("Incorrect password or Username.\n");
    return 0;
}

void menu()
{
    int choice;
    int logged_in = 0;
    while (1)
    {
        printf("-----Choose-----\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            register_user();
            break;
        case 2:
            if (logged_in)
            {
                printf("Already logged in.\n");
            }
            else
            {
                logged_in = login();
            }
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

int main()
{
    menu();
    return 0;
}