/*************************
Written by: Felina Kang

This program will take as input some text and count the total number of dominant letters.
A dominant letter is the letter that shows up the most in a word.
In this program, a "word" is any combination of one or more ASCII letters ('a-z' and/or
 'A-Z') that is surrounded by whitespace.

This file contains the main function.
*************************/

#include "hw1.h"
#include <iostream>
using namespace std;

int main() {
  int total = 0;
  string input;

  while (getline(cin, input))
    total += get_count(input);

  cout << "\nThe number of dominant letters is: " << total << endl;

  return 0;
}
