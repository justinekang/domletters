/************************************
This file contains the implementation for all of the functions that will do the actual
counting of dominant letters (get_count and count_word). It also contains the implementaion
for the function to check if a word is a "word" (check_word).

based on the example the first word will be considered a "word" even though it doesn't
technically start with a whitespace. Only thing that matters is if it is followed by
a whitespace
     example: "the " counts, not "the."
therefore there will be one check for the first word and then one check for the rest
************************************/
#include "hw1.h"
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

//gets the total num of dom letters of each word. calls check_word function for each word
//calls count_word for each word
int get_count(string & input) {
  int index = 0;
  int total = 0; //total
  int num_char[ROW_CHAR_ARR][COL_CHAR_ARR]; //num of occurrances of each letter in a word
  initialize(num_char);

  //check first word. beginning of file counts as whitespace
  if (check_word(index, input, num_char)) {
    total += count_word(num_char);
    arr_to_zero(num_char);
  }

  //checks the rest of the words
  //check_word will always pass back the index of the next char, so no need to incr
  while (input[index] != '\r' && input[index] != '\0') {
    if (isspace(input[index])) {
      if (check_word(++index, input, num_char)) {
        total += count_word(num_char);
      }
    }
    else
      ++index;
    arr_to_zero(num_char);
  }

  return total;
}


//checks if the word is a "word". it will also return the index of the char after the last
//char it checked, which should either be a whitespace or another non-alpha character.
//the char at the index that is passed in should be an alpha char and not a whitespace, since
//the first word does not have a whitespace in front. The calling function should check if
//there is a whitespace in front
bool check_word(int & index, string & input, int num_char[][COL_CHAR_ARR]) {
  int arr_ind = 0;

  if (input[index] == '\r' || input[index] == '\0')
    return false;

  //if passed in index points to something that is not a alpha char
  //pass back the next char
  if (isalpha(input[index]) == 0) {
    ++index;
    return false;
  }

  //else loop through word until char is not an alpha, then check for whitespace
  //if not a whitespace, then return false
  while (isalpha(input[index]) != 0) {
    //mod lowercase char by 26 to find the char in the table, then add 1 to 2 row of same col
    arr_ind = tolower(input[index]);
    arr_ind = arr_ind % 26;
    num_char[1][arr_ind] += 1;
    ++index;
  }

  //if last word does not have a whitespace, it is also considered a word
  if (isspace(input[index]) || input[index] == '\r' || input[index] == '\0')
    return true;
  else
    return false;
}


//goes through the entire second row of num_char and looks for the largest number
int count_word(int num_char[][COL_CHAR_ARR]) {
  int largest = 0;

  for (int j = 0; j < COL_CHAR_ARR; ++j)
    if (num_char[1][j] > largest)
      largest = num_char[1][j];

  return largest;
}


//initializes the whole array
void initialize(int array[][COL_CHAR_ARR]) {
  for (int j = 0; j < COL_CHAR_ARR; ++j) {
    array[0][j] = j;
    array[1][j] = 0;
  }
}


//sets the second row to 0
void arr_to_zero(int array[][COL_CHAR_ARR]) {
  for (int j = 0; j < COL_CHAR_ARR; ++j)
    array[1][j] = 0;
}
