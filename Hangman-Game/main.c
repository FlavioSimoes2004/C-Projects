#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int repeatedLetter(char* letters, char letter){
    for(int i = 0; i < strlen(letters); i++)
    {
        if(letters[i] == letter)
        {
            return 1;
        }
    }
    return 0;
}

//returns the number of different letters in a word
int getNumLetters(const char* word){
    int num_letters = 0;
    char letters[10];
    for(int i = 0; i < 10; i++)
    {
        letters[i] = '0';
    }
    letters[9] = '\0';

    for(int i = 0; i < strlen(word); i++)
    {
        if(repeatedLetter(letters, word[i]) == 0)
        {
            num_letters = num_letters + 1;
            //printf("letters array length = %i\n", strlen(letters));
            for(int j = 0; j < strlen(letters); j++)
            {
                if(letters[j] == '0')
                {
                    letters[j] = word[i];
                    //printf("Inserted inside letters, %i.\n", num_letters);
                    break;
                }
            }
        }
    }

    return num_letters;
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

    char test[10];
    printf("bbbbb%c\n", test[0]);

    int choice, chosenWord;
    int num_letters;
    int tries = 10, current_tries = tries;
    char userChoice;
    do
    {
        printf("0 - Game ends | 1 - Start new game\nChoose: ");
        scanf(" %i", &choice);
        while(choice < 0 || choice > 1)
        {
            printf("Invalid choice.");
            scanf(" %i", &choice);
        }

        if(choice == 1)
        {
            chosenWord = rand() % sizeof(words)/sizeof(char*);
            printf("Word chosen = %s\n", words[chosenWord]);

            num_letters = getNumLetters(words[chosenWord]);
            printf("Num letters = %i\n", num_letters);

            char letters_found[strlen(words[chosenWord])+1];
            letters_found[strlen(words[chosenWord])] = '\0';

            while(1)
            {
                //escolhe cor e tals
                printf("Choose a letter: ");
                scanf(" %c", &userChoice);

                if(repeatedLetter(words[chosenWord], userChoice) == 0)
                {
                    current_tries = current_tries - 1;
                }
                else
                {
                    num_letters = num_letters - 1;
                }

                if(num_letters == 0)
                {
                    printf("You found the word.\n");
                    break;
                }
                else if(current_tries == 0)
                {
                    printf("You lost. The word was: %s.\n", words[chosenWord]);
                    break;
                }
            }
            current_tries = tries;
        }
    } while (choice != 0);

    return 0;
}