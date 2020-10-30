#include "algo1.h"

//create vector lps that holds the match of the prefixes and the sufixes
//of the word we are searching: example: ABCXABC has the following
//prefix - sufix match: A-A, AB-AB, ABC-ABC
void computeLPSArray(string word, int wordLength, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // calculate lps[i] for each character in word 
    int i = 1; 
    while (i < wordLength){ 
        //found sufix-prefix match
        if (word[i] == word[len]) { 
            len ++; 
            lps[i] = len; 
            i ++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
           if (len != 0) { 
           	len = lps[len - 1]; 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i ++; 
            } 
        } 
    } 
}

void Knuth_Morris_Pratt(string word, string text, list <int> &appearences) {
	int wordLen = word.length();
	int textLen = text.length();

	//the longest prefix sufix for word
	int lps[wordLen];

	//calculate lps vector for word
    computeLPSArray(word, wordLen, lps); 

    int i = 0; // index for text[] 
    int j = 0; // index for word[] 
    while (i < textLen) { 
        //match
        if (word[j] == text[i]) { 
            j++; 
            i++; 
        } 
        
        //reached the end of the word, so we found a complete match
        if (j == wordLen) { 
            //add index we found complete match in the list of indexes
            appearences.push_back(i - j);
            j = lps[j - 1]; 
        } 
  
        //the end of the text was notreached
        //and word doesn't match the text
        else if (i < textLen && word[j] != text[i]) {
            //choose index j where to begin the next comparison between
            //word and text
            if (j != 0) 
                j = lps[j - 1]; 
            else //j == 0
                //lps[0] is always 0 because it is the first character
                //so we increment i
                i = i + 1; 
        } 
    } 
}