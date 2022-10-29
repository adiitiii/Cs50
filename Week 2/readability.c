#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int index(int a, int b, int c);

int main(void)
{
    // Prompting the user for an string input
    string text = get_string("Enter your text here: ");
    int letters_count = count_letters(text);
    int words_count = count_words(text);
    int sentences_count = count_sentences(text);

    index(letters_count, words_count, sentences_count);
}


//Defyning a fn() which counts the letters taken as an input from the text
int count_letters(string text)
{
    //Keeping the track of letter
    int letter_count = 0;
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letter_count++;
        }
    }
    printf("%i letters\n", letter_count);

    return letter_count;
}

//Defyning a fn() which counts the words taken as an input from the text
int count_words(string text)
{
    //Keeping track of the word count
    int word_count = 0;
    //initializing strlen a variable
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == ' ')
        {
            word_count++;
        }
    }
    printf("%i words\n", word_count + 1);

    return word_count + 1;
}

//Defyning a fn() which counts the sentences taken as an input from the text
int count_sentences(string text)
{
    int sentence_count = 0 ;
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }
    printf("%i sentences\n", sentence_count);
    return sentence_count;
}

int index(int letters, int words, int sentences)
{
    // Average of letters per 100 words
    float L = ((float)letters / (float)words) * 100.0;
    // Average of sentences per 100 words
    float S = ((float)sentences / (float)words) * 100.0;
    int calc = round(0.0588 * L - 0.296 * S - 15.8);

    // Rounding up to nearest digit
    int index = round(calc);
    printf("Index: %i\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    return 0;
}

