#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "life.h"

void signup() {
    printf("\e[1;1H\e[2J");

    FILE* pfile;
    char username[100];
    char line[100];
    int username_exists = 0;

    if (access("users.txt", F_OK) == 0) {
        pfile = fopen("users.txt", "r");
        if (pfile == NULL) {
            printf("Error opening file!\n");
            return;
        }

        printf("Enter desired username: ");
        scanf("%s", username);

        while (fgets(line, 100, pfile)) {
            line[strcspn(line, "\n")] = 0;
            if (strcmp(line, username) == 0) {
                printf("Username already exists! Please choose another.\n");
                username_exists = 1;
                fclose(pfile);
                return;
            }
        }
        fclose(pfile);

        if (!username_exists) {
            pfile = fopen("users.txt", "a");
            if (pfile == NULL) {
                printf("Error opening file for writing!\n");
                return;
            }
            fprintf(pfile, "%s\n", username);
            printf("Signup Successful!\n");
            fclose(pfile);
            menu();
        }
    }
    else {
        pfile = fopen("users.txt", "w");
        if (pfile == NULL) {
            printf("Error creating file!\n");
            return;
        }
        printf("Enter desired username: ");
        scanf("%s", username);
        fprintf(pfile, "%s\n", username);
        printf("Signup Successful!\n");
        fclose(pfile);
        menu();
    }
}
