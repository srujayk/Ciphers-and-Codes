#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

char UpperCipher(int let, int key);
char LowerCipher(int let, int key);

int main(int argc, string argv[])
{
    if(argc > 2 || argc < 2 || argv[1] < 0)
    {
        printf("You didn\'t enter the correct number of arguments, or your key was less than 0. Please rerun the program with the correct number and type of inputs.\n");
        return 1;
    }
    
    string k = argv[1];
    int klen = strlen(k);
    int key[strlen(k)];
    
    for(int x = 0, y = strlen(k); x < y; x++)
    {
        if(isupper(k[x]))
        {
            key[x] = (k[x] - 65);
        }else if(islower(k[x]))
        {
            key[x] = (k[x] - 97);
        }else
        {
            printf("Your keyword was not composed of all alphabetic characters. Please rerun the program with a valid keyword.\n");
            return 1;
        }
    }
    
    string sentence = GetString();
    
    bool alpha, upper;
    int letter;
    int kcounter = 0;

    for(int i = 0, n = strlen(sentence); i < n; i++)
    {
        letter = sentence[i];
        alpha = isalpha(letter);
        upper = isupper(letter);
        
        if(alpha)
        {
            if(upper)
            {
                printf("%c", UpperCipher(letter, key[kcounter]));
                kcounter++;
            }else
            {
                printf("%c", LowerCipher(letter, key[kcounter]));
                kcounter++;
            }
        }else
        {
            printf("%c", letter);
        }
        
        if(kcounter == klen)
        {
            kcounter = 0;
        }
    }
    
    printf("\n");
    
    return 0;
}

char UpperCipher(int let, int key)
{
    let = let - 65;
    
    return ((let + key) % 26) + 65;
}

char LowerCipher(int let, int key)
{
    let = let - 97;
    
    return ((let + key) % 26) + 97;
}
    

