#include <stdio.h>

int userList[11]; // List of users. Max is 11 accounts/users
int userMoneyList[11]; // User's money IN bank

int main() {
    // Loop's var
    int i = 0;

    // Choice Var
    int choice, userPIN;

    printf("Welcome to This Bank\n");

    // Intro
    while (i == 0) {

        printf("\nWhat do you want to do?\n");
        printf("1 = Access Your Account\n2 = Create New Account\n3 = Check All Users\nYour Choice: ");
        scanf("%d", &choice);

        if(choice == 1) { // Access account function
            accessAcc(userPIN);
        }

        else if (choice == 2) { // Create new account function
            createAcc(userPIN);
        }

        else if (choice == 3) { // Check all registered users in the userList array
            checkUsersList();
        }

        else {
            printf("Wrong input. Please try again\n\n");
            continue;
        }
    }
}

// Access current user's account.
int accessAcc(int userPIN) {

    // Loop's var
    int i;
    // For choice
    int choice, withdraw, deposit;

    printf("\nPlease put your PIN number\n");
    scanf("%d", &userPIN);

    for(i = 0; i < 11; i++) {
        if(userPIN == userList[i]) {
            printf("\nAccount %d found\n", userPIN);
            printf("--------\n\n");

            printf("Account Details\n--------\n");

            printf("Account Number: %d\n", userPIN);
            printf("Money In Bank: %d\n\n", userMoneyList[i]);
            printf("--------");

            printf("What do you want to do?\n1 = Withdraw money\n2 = Deposit money\nYour Choice: ");
            scanf("%d", &choice);

            // Withdraw money
            if(choice == 1) {
                printf("\n\nHow much you want to withdraw?\n");
                scanf("%d", &withdraw);

                // If actually enough money to withdrawn
                if(withdraw <= userMoneyList[i]) {
                    printf("\n\nWithdrawal of RM%d from your account has been successful!", withdraw);
                    userMoneyList[i] -= withdraw;
                    printf("\nMoney In Bank: RM%d", userMoneyList[i]);
                    break;
                }

                // If not enough money to withdraw
                else if(withdraw > userMoneyList[i]) {
                    printf("\n\nYour money of RM%d is not enough for withdrawal of RM%d", userMoneyList[i], withdraw);
                    break;
                }
            }

            // Deposit
            if(choice == 2) {
                printf("\n\nHow much you want to deposit?\n");
                scanf("%d", &deposit);

                userMoneyList[i] += deposit;
                printf("Deposit of %d to your current account has been successful!\n", deposit);
                printf("Current Money: %d\n\n", userMoneyList[i]);
                break;
            }
        }

        else if (userPIN != userList[i]) { // If not found
            printf("\nAccount is not found. Please try again.\n\n");
            break;
        }
    }
}

// Create new user account
int createAcc(int userPIN) {

    // Loop's var
    int i = 0;
    // User's current money IN POCKET not in bank
    int userMoney;

    printf("\n\nWelcome to the User Creation Page. Please input your PIN numbers that you want\nPIN: ");
    scanf("%d", &userPIN);
    printf("\nHello %d, please input how much money you want to put in your newly created account.\nRM", userPIN);
    scanf("%d", &userMoney);

    while(i == 0) {
        // Detect if userPIN is already exist or not
        if(userPIN == userList[i]) {
            printf("\nPIN already exist. Please try other PIN numbers\n\n");
            break;
        }

        // If the PIN is not in the array, add it then
        else if (userPIN != userList[i]) {
            printf("\nPIN %d has added into the database\n\n", userPIN);

            // Shift all users' PIN downwards
             for(i = 1; i >= 0; i--) {
                userList[i+1] = userList[i];
                userMoneyList[i+1] = userMoneyList[i];
            }

            // Add to the first PIN
            userList[0] = userPIN;
            userMoneyList[0] = userMoney;
            break;
        }
    }
}

// Shows all the user
int checkUsersList() {

    // Loop's var
    int i;

    printf("\nList of Users\n");
    for(i = 0; i < 11; i++) {
        printf("%d. User %d", i, userList[i]);
        printf(" - %d\n", userMoneyList[i]);
    }
}
