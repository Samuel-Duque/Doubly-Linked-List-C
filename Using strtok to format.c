#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    while (1) {

        char name[100];
        printf("Enter a full name or 'exit' to quit: ");
        fgets(name, sizeof(name), stdin);

        name[strcspn(name, "\n")] = '\0';

        for (int i = 0; name[i]; i++) {
            name[i] = tolower(name[i]); // Formatting to make all letters lowercase
        }

        if (strcmp(name, "exit") == 0)
            break;

        // Make a copy of the string to count the names
        char nameCopy[100];
        strcpy(nameCopy, name);

        char *token;
        char *lastName = NULL;
        char *firstName = NULL;
        char *middleName = NULL;
        int counter_1 = 0;
        int counter_2 = 0;

        // Split the string by names using spaces
        token = strtok(nameCopy, " ");

        // Count how many names are in the string
        while (token != NULL) {
            counter_2++;
            token = strtok(NULL, " ");
        }

        // Reset the token to compare it with the counter_2 I created to know the first (1) and last name
        token = strtok(name, " ");

        while (token != NULL) {
            counter_1++;
            if (counter_1 == 1) {
                firstName = token;
                firstName[0] = toupper(firstName[0]);
            }
            else if (counter_1 == counter_2) {
                lastName = token;
                lastName[0] = toupper(lastName[0]);
            }
            else {
                if (middleName == NULL) {
                    // Allocate memory in the variable to use strcpy
                    middleName = (char *)malloc(strlen(token) + 1);
                    strcpy(middleName, token);
                    middleName[0] = toupper(middleName[0]);
                }
                else {
                    // If there are more than 3 names, add to the middle name variable
                    strcat(middleName, " ");
                    token[0] = toupper(token[0]);
                    strcat(middleName, token);
                }
            }
            token = strtok(NULL, " ");
        }

        if (firstName != NULL && lastName != NULL) {
            printf("%s, %s", lastName, firstName);
            if (middleName != NULL) {
                printf(" %s", middleName);
            }
            printf("\n");
        }
        else {
            printf("Invalid input format. Please enter a name with at least a first and a last name.\n");
        }

        free(middleName); // Release allocated memory
    }
    return 0;
}
