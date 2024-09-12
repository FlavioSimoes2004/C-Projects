#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//returns the number of different letters in a word
int getNumLetters(const char* word){
    int letters = 0;

    printf("Length word = %i\n", sizeof(word)/sizeof(char));

    return letters;
}

int main(){
    srand(time(NULL));

    const char* words[] = {
        "test",
        "hello",
        "bye",
        "good",
        "great",
        "bad",
        "worse"
    };
    printf("Length = %i\n", sizeof(words)/sizeof(char*));
    //printf("%s\n", words[0]);

    int choice, chosenWord;
    int num_letters;
    int tries = 10, current_tries = tries;
    do
    {
        printf("0 - Game ends | 1 - Start new game\nChoose: ");
        scanf(" %i", &choice);
        while(choice < 0 || choice > 1)
        {
            printf("Invalid choice.");
            scanf(" %i", &choice);
        }

        while(choice == 1 && current_tries > 0)
        {
            chosenWord = rand() % sizeof(words)/sizeof(char*);
            printf("Word chosen = %s\n", words[chosenWord]);
            num_letters = getNumLetters(words[chosenWord]);
            break;
        }
    } while (choice != 0);

    return 0;
}