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

void getWord(char* word, char* tried_letters){
    char secretWord[strlen(word) + 1];
    for(int i = 0; i < strlen(word); i++)
    {
        secretWord[i] = '_';
    }
    secretWord[strlen(word)] = '\0';
    int pos = 0;

    for(int i = 0; i < strlen(word); i++)
    {
        for(int j = 0; j < strlen(tried_letters); j++)
        {
            if(word[i] == tried_letters[j])
            {
                secretWord[pos] = word[i];
                break;
            }
        }
        pos = pos + 1;
    }

    printf("Word progress: %s\n", secretWord);
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

            int length = tries + num_letters + 1;
            char tried_letters[length];
            for(int i = 0; i < length; i++)
            {
                tried_letters[i] = '_';
            }
            tried_letters[length - 1] = '\0';

            while(1)
            {
                //escolhe cor e tals
                printf("Choose a letter: ");
                scanf(" %c", &userChoice);

                if(repeatedLetter(tried_letters, userChoice) == 1) //the letter was already used
                {
                    printf("You already tried this letter.\n");
                }
                else if(repeatedLetter(words[chosenWord], userChoice) == 0) //the word does not contain the letter
                {
                    tried_letters[length - (current_tries + num_letters + 1)] = userChoice;
                    current_tries = current_tries - 1;
                }
                else //the word contain this letter
                {
                    tried_letters[length - (current_tries + num_letters + 1)] = userChoice;
                    num_letters = num_letters - 1;
                }

                if(num_letters == 0)
                {
                    printf("You found the word. The word was: %s.\n", words[chosenWord]);
                    break;
                }
                else if(current_tries == 0)
                {
                    printf("You lost. The word was: %s.\n", words[chosenWord]);
                    break;
                }
                else
                {
                    printf("Letters used: %s\n", tried_letters);
                    getWord(words[chosenWord], tried_letters);
                }
            }
            current_tries = tries;
        }
    } while (choice != 0);

    return 0;
}