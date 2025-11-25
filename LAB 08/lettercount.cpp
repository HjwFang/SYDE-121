#include "lettercount.h"

const int NUM_LETTERS = 26;
/*
int main(){
    string filename;
    cout << "Enter the input filename: ";
    cin >> filename;

    ifstream instream(filename);
    if (instream.fail()){
        exit(1);
    }

    ofstream outstream("output.txt");
    if (outstream.fail()){
        exit(1);
    }

    count_letters(instream, outstream);

    instream.close();
    outstream.close();

    cout << "Results exported to output.txt." << endl;

    return 0;
}
*/

void read_input(ifstream& instream, string& text){
    getline(instream, text);
    return;
}

void true_count(const string& text, letter_track letters[]){
    //initialize
    for (int i = 0; i < 26; i++){
        letters[i].letter = 'a' + i;
        letters[i].count = 0;
    }
    
    //count
    for (int i = 0; i < text.length(); i++){
        if (islower(text[i])){
            int index = text[i] - 'a';
            letters[index].count++;
        }
    }

    return;
}

void sort(letter_track letters[]){
    for (int i = 1; i < NUM_LETTERS; i++){
        for (int j = i - 1; j >= 0; j--){
            if (letters[j].count < letters[j + 1].count ||
                (letters[j].count == letters[j + 1].count && 
                 letters[j].letter > letters[j + 1].letter)) {
                
                letter_track temp = letters[j];
                letters[j] = letters[j + 1];
                letters[j + 1] = temp;
            } else {
                break;
            }
        }
    }
}

void output(ofstream& outstream, letter_track letters[]){
    outstream << "Letter\tOccurrence" << endl;

    for (int i = 0; i < NUM_LETTERS; i++) {
        if (letters[i].count > 0) {
            outstream << letters[i].letter << "\t" << letters[i].count << endl;
        }
    }
}

void count_letters(ifstream& instream, ofstream& outstream){
    string text;
    letter_track letters[26];
    int num_letters = 0;

    read_input(instream, text);

    true_count(text, letters);

    sort(letters);

    output(outstream, letters);
}