#ifndef ALGO_H
#define ALGO_H

#include <list>
#include <iostream>
#include <string.h>
using namespace std;

//the header for the function(s) that solves your problem
void Knuth_Morris_Pratt(string word, string text, list <int> &appearences);

void computeLPSArray(string word, int wordLength, int* lps);

#endif
