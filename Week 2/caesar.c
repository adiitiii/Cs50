#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])

{
    //initializing 'a' to 'argv[1]'
    string a = argv[1];

    //checking count in the command- line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //checking whether command- line argument is an integer or not
    for (int i = 0; i < strlen(a); i++)
    {
        if (isalpha(a[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

//changing the datatype
    int key = atoi(a);

//gettinhg the input for plaintext from user
    string plaintext = get_string("plaintext:  ");

//printing ciphertext
    printf("ciphertext: ");
    for (int j = 0; j < strlen(plaintext); j++)
    {
        //rounding for the uppercase characters
        if (isupper(plaintext[j]))
    {
        printf("%c", (((plaintext[j] - 65) + key) % 26)
            + 65);
    }


    //rounding for the lowercase characters
    else if (islower(plaintext[j]))
    {
        printf("%c", (((plaintext[j] - 97) + key) % 26)
            + 97);
    }

    //as it is printing anything other than alphabets

    else
    {
        printf("%c", plaintext[j]);
    }
}
printf("\n");

return 0;
}
