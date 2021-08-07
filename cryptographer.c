#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isDigit(string s);

int main(int argc, string argv[])
{
    //checks if the user used the right syntax and if the user input a digit
    if (argc == 2 && isDigit(argv[1]))
    {
        //convert user input string into int
        int key = atoi(argv[1]);

        //store user input into plaintext and make a new char array (string) with the same length as plaintext
        string plainText = get_string("plaintext: ");
        char cipherText[strlen(plainText)];
        strcpy(cipherText, plainText);

        //making cipher text from plain text here
        for (int i = 0; i < strlen(cipherText); i++)
        {
            //making sure to only change the alphabets, not the special characters
            if ((cipherText[i] >= 'a' && cipherText[i] <= 'z') || (cipherText[i] >= 'A' && cipherText[i] <= 'Z'))
            {
                if ((cipherText[i] >= 'a' && cipherText[i] <= 'z'))
                {
                    cipherText[i] = (cipherText[i] + key) % 122;
                    if (cipherText[i] < 97)
                    {
                        cipherText[i] = (cipherText[i] % 26) + 96;
                    }
                }
                else if ((cipherText[i] >= 'A' && cipherText[i] <= 'Z'))
                {
                    cipherText[i] = (cipherText[i] + key) % 90;
                    if (cipherText[i] < 65)
                    {
                        cipherText[i] = (cipherText[i] % 26) + 64;
                    }
                }
            }
        }

        printf("ciphertext: %s\n", cipherText);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}

//this function checks if the string is a decimal digit
bool isDigit(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        //checks if the character is between 0-9 and returns false if it's not
        if (!(s[i] >= '0' && s[i] <= '9'))
        {
            return false;
        }
    }

    return true;
}
