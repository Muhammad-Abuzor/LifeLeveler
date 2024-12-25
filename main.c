#include <stdio.h>
#include "life.h"

int main(){

    int a;

    printf("\e[1;1H\e[2J");

    printf("Welcome user, would you like to: \n");
    printf("1.Signup? \n");
    printf("2.Login? \n");
    scanf("%d",&a);
    if (a == 1 || a ==  2) {
        if (a == 1 ) {
            signup();
        }
        else if (a == 2) {
            login();
        }
        else {
            printf("enter a better option");
        }
    }

   return 0;

}
