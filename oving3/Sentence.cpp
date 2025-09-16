#include "Sentence.hpp"
#include <iostream>

using namespace std;

void testSentence() {
  string word1, word2, word3;
  cout << "Skriv inn tre ord: ";
  cin >> word1 >> word2 >> word3;

  string sentence = word1 + " " + word2 + " " + word3 + ".";
  cout << "Setning: " << sentence << endl;

  cout << "Lengde på word1: " << word1.size() << endl;
  cout << "Lengde på word2: " << word2.size() << endl;
  cout << "Lengde på word3: " << word3.size() << endl;
  cout << "Lengde på setningen: " << sentence.size() << endl;

  string sentence2 = sentence;
  if (sentence2.size() > 12) {
    sentence2.replace(10, 3, "xxx");
  }
  cout << "Setning: " << sentence << endl;
  cout << "Setning2: " << sentence2 << endl;

  if (sentence.size() >= 5) {
    string sentence_start = sentence.substr(0, 5);
    cout << "Setning: " << sentence << endl;
    cout << "Start på setning: " << sentence_start << endl;
  }

  if (sentence.find("hallo") != string::npos) {
    cout << "Setningen inneholder 'hallo'" << endl;
  } else {
    cout << "Setningen inneholder ikke 'hallo'" << endl;
  }

  size_t pos = sentence.find("er");
  while (pos != string::npos) {
    cout << "Fant 'er' på posisjon " << pos << endl;
    pos = sentence.find("er", pos + 2);
  }
}
