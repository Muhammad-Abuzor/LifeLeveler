#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "life.h"

void login() {
    printf("\e[1;1H\e[2J");

    FILE* pfile;
    char username[100];
    char line[100];

    if (access("users.txt", F_OK) == 0) {
        pfile = fopen("users.txt", "r");
        if (pfile == NULL) {
            printf("Error opening file!\n");
            return;
        }

        printf("Enter your username: ");
        scanf("%s", username);

        while (fgets(line, 100, pfile)) {
            line[strcspn(line, "\n")] = 0;

            if (strcmp(line, username) == 0) {
                printf("Login Successful!\n");
                fclose(pfile);
                menu();
                return;
            }
        }
        printf("Login Failed!\n");
        fclose(pfile);
    }
    else {
        pfile = fopen("users.txt", "w");
        if (pfile == NULL) {
            printf("Error creating file!\n");
            return;
        }
        printf("New data file created, please re-run program!\n");
        fclose(pfile);
    }
}
