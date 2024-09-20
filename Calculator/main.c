#include <stdio.h>
#include <stdlib.h>

double sum(double, double);
double minus(double, double);
double times(double, double);
double division(double, double);

int main(){
    int choice;
    double mem[3] = {0, 0, 0};

    do
    {
        printf("OPERATIONS\n| 1 - SUM | 2 - MINUS | 3 - TIMES | 4 - DIVISION |\nChoose: ");
        scanf(" %i", &choice);
        while(choice < 0 || choice > 5)
        {
            printf("Invalid choice, choose again: ");
            scanf(" %i", &choice);
        }

        if(choice == 1)
        {
            
        }
        else if(choice == 2)
        {

        }
        else if(choice == 3)
        {

        }
        else if(choice == 4)
        {

        }

    } while(choice != 0);
    printf("Calculator closed.");
    

    return 0;
}