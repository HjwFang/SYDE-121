#ifndef LETTERCOUNT_H
#define LETTERCOUNT_H

#include <iostream>
#include <fstream> 
#include <string>
#include <cctype>
using namespace std;

struct letter_track{
    char letter;
    int count;
};

void count_letters(ifstream& instream, ofstream& outstream);

void read_input(ifstream& instream, string& text);

void true_count(const string& text, letter_track letters[]);

void sort(letter_track letters[]);

void output(ofstream& outstream, const letter_track letters[]);


#endif