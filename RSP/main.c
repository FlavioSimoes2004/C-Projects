#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int userChoice, randChoice;
    do
    {
        printf("0 - Ends the game\n1 - Rock | 2 - Scissors | 3 - Paper\nYour choice: ");
        scanf(" %i", &userChoice);
        if(userChoice < 0 || userChoice > 3)
        {
            printf("Invalid choice.\n");
            scanf(" %i", &userChoice);
        }


        if(userChoice != 0)
        {
            randChoice = (rand() % 3) + 1;
            printf("Rand = %i\n", randChoice);
            
            if(userChoice == randChoice)
            {
                printf("Tie.");
            }
            else if(userChoice == 1)
            {
                if(randChoice == 2)
                {
                    printf("You won.");
                }
                else
                {
                    printf("You lost.");
                }
            }
            else if(userChoice == 2)
            {
                if(randChoice == 1)
                {
                    printf("You lost.");
                }
                else
                {
                    printf("You won.");
                }
            }
            else //userChoice == 3
            {
                if(randChoice == 1)
                {
                    printf("You won.");
                }
                else
                {
                    printf("You lost.");
                }
            }
            printf("\n");
        }
    } while (userChoice != 0);

    printf("Game ended.");
}