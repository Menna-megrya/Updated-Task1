#include <stdio.h>
#include <string.h>

typedef struct Info
{
    char username[20];
    char password[20];
} User;

User users[10];
int totalUsers = 0;

// Function to register a new user
void registerUser()
{
    if (totalUsers == 10)
    {
        printf("Maximum number of users reached.\n");
        return;
    }

    char username[20];
    char password[20];

    printf("Enter a username: ");
    scanf("%s", username);
    printf("Enter a password: ");
    scanf("%s", password);

    for (int i = 0; i < totalUsers; i++)
    {
        if (strcmp(username, users[i].username) == 0)
        {
            printf("Username already exists. Please choose a different username.\n");
            return;
        }
    }

    // Add the new user
    strcpy(users[totalUsers].username, username);
    strcpy(users[totalUsers].password, password);
    totalUsers++;
    printf(" [ User Register Successfully ]\n");
}

int loginUser()
{
    char username[20];
    char password[20];

    strcpy(users[0].username, "menna");
    strcpy(users[0].password, "pass234");
    totalUsers++;

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    for (int i = 0; i < totalUsers; i++)
    {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
        {
            printf("Login successfully!!\n");
            return 1;
        }
    }

    printf("Invalid username or password.\n");
    return 0;
}

void displayMenu()
{
    printf("-----Choose-----\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("0. Exit\n");
    printf("Your option: ");
}

int main()
{
    
    int choice;
    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 0);

    return 0;
}