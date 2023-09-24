#include <stdio.h>

typedef struct {
    char name[50];
    int income;
    int birthYear;
    int hasCar;
} User;

int main() {
    int n, sum = 0, average, yearStatistics = 0, carStatistics = 0, incomeStatistics = 0;
    printf("How many people do you want to register?: ");
    scanf("%d", &n);
    User userArray[n];

    for (int i = 0; i < n; i++) {
        printf("Enter your name: \n");
        scanf("%s", &userArray[i].name);
        fflush(stdin);
        printf("Enter your income: \n");
        scanf("%d", &userArray[i].income);
        printf("Enter your birth year: \n");
        scanf("%d", &userArray[i].birthYear);
        printf("Do you have a car? [0] No / [1] Yes : \n");
        scanf("%d", &userArray[i].hasCar);

        sum += userArray[i].income;
    }

    average = sum / n;

    for (int i = 0; i < n; i++) {
        if (userArray[i].birthYear >= 1960 && userArray[i].birthYear <= 1980)
            yearStatistics += 1;

        if (userArray[i].hasCar == 1)
            carStatistics += 1;

        if (userArray[i].income > average)
            incomeStatistics += 1;
    }

    printf("\nNumber of clients with income above average: %d", incomeStatistics);
    printf("\nNumber of clients who have a car: %d", carStatistics);
    printf("\nNumber of clients born between [1960 - 1980]: %d", yearStatistics);

    return 0;
}
