#include <stdio.h>
#include <windows.h>
#include <time.h>

int main(){

    system("ADD8E6");
    int Pin = 1234, pinIn, Option, Choice = 1, Amount, Count = 0; 
    double Balance = 50000;

    time_t now;
    time(now);
    printf("\n\t\t\t %s",ctime(now));
    printf("\n\t\t\t\t\t\t\t\t\t\t*WELCOME TO KINGS BANKING SERVICES* ");

    while(Pin != pinIn){
        printf("\n\t\t\t Please enter your pin: ");
        scanf("%d", &pinIn);
        if(Pin != pinIn){
            Beep(610,500);
            printf("Invalid Pin.");
        }
        Count ++;
        if(Count == 3 && Pin != pinIn){
            exit(0);
        }
    }

    while(Option != 0){
        printf("\n\t\t\t\t\t\t\t\t\t\t Our Service: ");
        printf("/n/n/t/t1. Withdraw ");
        printf("/n/n/t/t1. Deposit ");
        printf("/n/n/t/t1. Balance ");
        scanf("%d", &Option);

        switch(Option){
            case 1:
                while(Amount % 5000 != 0){
                    printf("/n/t/t/t Please amount");
                    scanf("%d", &Amount);
                    if(Amount % 5000 != 0){
                        printf("/n/t/t/t The amount should be a multiple of 5000. ");
                    }
                }
                if(Balance < Amount){
                    printf("\n\t\t\t The amount is insufficient.");
                    Amount = 0;
                    break;
                }
                else{
                    Balance -= Amount;
                    printf("\n\t\t\t You have withdrawn Shs.%d. \n Your new balance is Shs.%.2lf", Amount, Balance);
                    printf("\n\t\t\t\t\t Thank you for banking with Kings Bank ");
                    Amount = 0;
                    break;
                }

            case 2:
                printf("\n \t\t\t\t\t Please enter the amount : ");
                scanf("%d", &Amount);
                Balance += Amount;
                printf("\n\t\t\t You have deposited Shs.%d. \n Your new balance is Shs.%.2lf", Amount, Balance);
                printf("\n\t\t\t\t\t Thank you for banking with Kings Bank ");
                Amount = 0;
                break;

            case 3:
                printf("\n\t\t\t Your balance is Shs.%.2lf", Balance);
                break;

            default:
                Beep(610, 500);
                printf("\n\t\t\t Invalid Option.");                
        }

    }

    printf("\n\t\t\t\t\t Do you wish to perform another transaction? Press 1[Yes] or 2[No]");
    scanf("%d", &Choice);

    return 0;
}