#include "algo2.h"

//a theroetic number for the numbers of letters from the alphabet of characters we use
//I used all numbers, letters and space " "
#define alphabetNumber 63

//implement functions in algo.h
void Rabin_Karp (string word, string text, int prime, list <int> &appearences) 
{  
    //length of word
    int wordLen = word.length(); 

    //length of text (text = pattern)
    int textLen = text.length();
    int i, j;  //indexes
    int wordHashValue = 0; // hash value for word  
    int textHashValue = 0; // hash value for txt  
    int h = 1;  
  
    // calculate hash  
    for (i = 0; i < wordLen - 1; i++)  
        h = (h * alphabetNumber) % prime;  
  
    // Calculate the hash value of word and first  
    // window of text  
    for (i = 0; i < wordLen; i++)  
    {  
        wordHashValue = (alphabetNumber * wordHashValue + word[i]) % prime;  
        textHashValue = (alphabetNumber * textHashValue + text[i]) % prime;  
    }  
  
    // Slide the word over text one by one  
    for (i = 0; i <= textLen - wordLen; i++)  
    {  
        //check if the hash values of current text window
        //and word match
        //if so check every character of those two
        if ( wordHashValue == textHashValue )  
        {  
            //check characters
            for (j = 0; j < wordLen; j++)  
            {  
                if (text[i + j] != word[j])
                    break;  
            }  
  
            //only if we reached the end of the word
            //we add the index in our list
            if (j == wordLen) {
                appearences.push_back(i);
            }
        }  
  
        // Calculate hash value for next window of text
        if ( i < textLen - wordLen )  
        {  
            textHashValue = (alphabetNumber * (textHashValue - text[i] * h) + text[i + wordLen]) %  prime;  
  
            //if hash value is negative, make it positive
            if (textHashValue < 0)  
                textHashValue = (textHashValue + prime);
        }  
    }  
}  