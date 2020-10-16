
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int CountChars(string ipString);
bool isChar(char c);
int CountWords(string ipString);
int CountSent(string ipString);

int main(void)
{

    string ipString = get_string("Text: ");
    int CharCount = CountChars(ipString);
    int WordCount = CountWords(ipString);
    int SentCount = CountSent(ipString);
    
    float Coleman_L = ((float)CharCount / WordCount) * 100;
    float Coleman_S = ((float)SentCount / WordCount) * 100;
    float ColemanIndex = 0.0588 * Coleman_L - 0.296 * Coleman_S - 15.8;
    
    if (ColemanIndex < 1)
    {
        printf("Before Grade 1\n ");
    }
    else if (ColemanIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i \n", (int)round(ColemanIndex));
    }

}


bool isChar(char c)
{

    if ((c > 64 && c < 91) || (c > 96 && c < 123))
    {
        return true;
    }
    return false;

}


//counts the number of characters (a-z and A-Z) in a string
int CountChars(string ipString)
{
    int numChars = 0;
    for (int i = 0; i < strlen(ipString); i++)
    {
        // printf ("%i \n", ipString[i]);
        if (isChar(ipString[i]) == true)
        {
            numChars++;
            // printf ("%i chars", numChars);
        }
    }
    return numChars;
}



// counts the number of words (a-z and A-Z) in a string
int CountWords(string ipString)
{
    
    int numWords;
    
    if (ipString[0] == ' ')
    {
        numWords = 0;
    }
    else
    {
        numWords = 1;
    }
    
    
    for (int i = 0; i < strlen(ipString); i++)
    {

        if (ipString[i] == ' ' && isChar(ipString[i + 1]) == true)
        {
            numWords++;
            
        }
    }
    return numWords;
}

int CountSent(string ipString)
{
    int numSent = 0;
    
    // if(ipString[0] == '')
    // {
    //     numSent = 0;
    // }
    // else
    // {
    //     numSent = 1;
    // }
    
    for (int i = 0; i < strlen(ipString); i++)
    {

        if ((ipString[i] == '.' || ipString[i] == '?' || ipString[i] == '!'))
        {
            numSent++;
            
        }
    }
    return numSent;
    
}
