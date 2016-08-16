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
    
    int k = atoi(argv[1]);
    
    string sentence = GetString();
    
    bool alpha, upper;
    int letter;

    for(int i = 0, n = strlen(sentence); i < n; i++)
    {
        letter = sentence[i];
        alpha = isalpha(letter);
        upper = isupper(letter);
        
        if(alpha)
        {
            if(upper)
            {
                printf("%c", UpperCipher(letter, k));
            }else
            {
                printf("%c", LowerCipher(letter, k));
            }
        }else
        {
            printf("%c", letter);
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
    


bool consistent(int tnum1, int tnum2, double conv, int len, int number1[], int number2[], double conversion[]) {
    printf ("call: %i %i %lf\n", tnum1, tnum2, conv);
    for (int i=0; i< len; i++) {
        
         if (number1[i] == tnum1 &&  number2[i] == tnum2 && conversion[i] == conv ) return true;
         else if (number1[i] == tnum2 &&  number2[i] == tnum1 && conversion[i] == (1 / conv )) return true;
         else  if (number2[i] == tnum1) {
             if (number1[i] == number2[i]) continue;
              printf ("R1call: %i %i %lf\n", tnum2, number2[i], conv / conversion[i]);
           if (consistent(tnum2, number2[i], conv / conversion[i], len, number1, number2, conversion)) continue;
            else return false;
        }else if (number1[i] == tnum2) {
             if (number1[i] == number2[i]) continue;
              printf ("R2call: %i %i %lf\n", tnum1, number2[i], conv / conversion[i]);
            if (consistent(tnum1, number2[i], conv / conversion[i], len, number1, number2, conversion)) continue;
            else return false;
        }
          
       
       
      
    }
    
    return true;
}
