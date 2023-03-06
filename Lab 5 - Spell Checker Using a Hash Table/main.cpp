/*
 * Name: Russell Welch
 * Date Submitted: 03/06/2023
 * Lab Section: 001 
 * Assignment Name: Lab 5 - Spell Checker Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
//  int main()
//  {
//      Stringset wordlist;
//      testStringset(wordlist);
//      return 0;
//  }
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
/**
 * Loads words from a file into a Stringset object
 * @param words The Stringset object to load the words into
 * @param filename The name of the file containing the words
 */
void loadStringset(Stringset& words, string filename) {
    // Open the file
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string word;
    // Read each word from the file and insert into the Stringset
    while (file >> word) {
        words.insert(word);
    }

    // Close the file
    file.close();
}

/**
 * Finds alternative spellings for a given word
 * @param words The Stringset object containing the dictionary of words
 * @param word The word to check for alternative spellings
 * @return A vector of strings containing the alternative spellings of the word
 */
vector<string> spellcheck(const Stringset& words, string word) {
    vector<string> alternatives;

    // Loop through each character in the input word
    for (int i = 0; i < word.length(); i++) {
        // Loop through each possible character substitution (a-z)
        for (char c = 'a'; c <= 'z'; c++) {
            // Generate a new word with the character substitution
            string newWord = word;
            newWord[i] = c;

            // Check if the new word exists in the dictionary and is not the original word
            if (words.find(newWord) && newWord != word) {
                alternatives.push_back(newWord);
            }
        }
    }
    return alternatives;
}