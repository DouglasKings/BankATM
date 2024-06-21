#include <stdio.h>//is part of the C standard library and provides functions for performing input and output operations. 
#include <windows.h>//is essential for developing applications that interact with the Windows operating system
#include <time.h>//is part of the C standard library and provides functions for manipulating dates and times.

int main() {
    // Clearing the console screen
    system("cls");

    // Initializing variables
    int Pin = 1234, pinIn, Option, Choice = 1, Amount, Count = 0, exitFlag = 0; // Flag to indicate if the user wants to exit; 
    double Balance = 50000; // Initial balance

    // Getting current time and print welcome message
    time_t now; 
    time(&now); 
    printf("\n\t\t\t\t\t\t\t    %s", ctime(&now)); 
    printf("\n\t\t\t\t\t\t\t*WELCOME TO KINGS BANKING SERVICES* \n");

    // PIN verification loop
    while (pinIn != Pin) {
        printf("\n\t\t\t Please enter your pin: ");
        scanf("%d", &pinIn);
        if (Pin!= pinIn) {
            Beep(610, 500); // Playing beep sound for incorrect PIN
            printf("\n\t\t\t Invalid Pin.\n"); // Inform user about invalid PIN
        }
        Count++; // Incrementing count for failed attempts
        if (Count == 3 && Pin!= pinIn) { // Exiting after 3 failed attempts
            exit(0);
        }
    }

    // Main service menu loop
    while (Choice!= 0 && !exitFlag) {
        printf("\n\t\t\t\t\t\t\t Our Service: ");
        printf("\n\n\t\t\t\t1. Withdraw\n");
        printf("\n\n\t\t\t\t2. Deposit\n");
        printf("\n\n\t\t\t\t3. Balance\n");
        printf("\n\n\t\t\t\t4. Exit\n");
        printf("\n\n\t\t\t\tPlease enter your choice: ");
        scanf("%d", &Option);

        switch (Option) {
            case 1: // Withdrawal option
                while (Amount % 5000!= 0) { // Ensuring withdrawal amount is a multiple of 5000
                    printf("\n\t\t\t\tPlease enter the amount: ");
                    scanf("%d", &Amount);
                    if (Amount % 5000!= 0) {
                        printf("\n\t\t\t\tThe amount should be a multiple of 5000.\n");
                    }
                }
                if (Balance < Amount) { // Checking if balance is sufficient
                    printf("\n\t\t\t\tThe amount is insufficient.\n");
                    Amount = 0;
                    break;
                } else {
                    Balance -= Amount; // Deducting amount from balance
                    printf("\n\t\t\t\tYou have withdrawn Shs.%d. \n\t\t\t\tYour new balance is Shs.%.2lf\n", Amount, Balance);
                    printf("\n\t\t\t\t\t\t Thank you for banking with Kings Bank.\n");
                    Amount = 0;
                    break;
                }

            case 2: // Deposit option
                printf("\n \t\t\t\tPlease enter the amount: ");
                scanf("%d", &Amount);
                Balance += Amount; // Adding deposit amount to balance
                printf("\n\t\t\t\tYou have deposited Shs.%d. \n Your new balance is Shs.%.2lf\n", Amount, Balance);
                printf("\n\t\t\t\t\t\t Thank you for banking with Kings Bank.\n");
                Amount = 0;
                break;

            case 3: // Balance inquiry option
                printf("\n\t\t\t\tYour balance is Shs.%.2lf\n", Balance);
                break;

            case 4: // Exit
                printf("\n\t\t\t\t\t\t Thank you for banking with Kings Bank.\n");
                exitFlag = 1; // Set the exit flag
                break;

            default: // Invalid option
                Beep(610, 500); // Playing beep sound for invalid option
                printf("\n\t\t\t\tInvalid Option.\n");                
        }
    }

    // Asking user if they want to perform another transaction
    printf("\n\t\t\t Do you wish to perform another transaction? Press 1[Yes] or 2[No]: ");
    scanf("%d", &Choice);
    if (scanf("%d", &Choice)!= 1) {
        printf("Invalid input. Please enter a number.\n");
    }

    return 0;
}