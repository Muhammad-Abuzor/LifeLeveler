#include <stdbool.h>
#include <stdio.h>
#include "life.h"

void menu(){

    int a;
    bool isBad = false;

    printf("\e[1;1H\e[2J");

    printf("Welcome User, to the place you level up your life.\n");

    printf("Choose an option\n");
    printf("1.Task\n");
    printf("2.Quest\n");
    printf("3.Level\n");
    printf("4.Reward (comming soon) \n");
    printf("Please enter option (1,2,3,4): ");
    scanf("%d",&a);

    do {
        switch (a) {
            case 1:
                task();
                break;

            case 2:
                quest();
                break;

            case 3:
                level();
                break;

            case 4:
                printf("The Reward feature will be added soon");
                break;

            default:
                printf("please enter a valid option");
                isBad = true;
                break;
        }
    }while (isBad);

}
