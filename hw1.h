#include <string>
using namespace std;

//row and col size of the array to store the num of times a char appears in a word
//since the "word" does not have to be an actual word from the dictionary, all 26 letters
//can appear in a single "word", and thus an array that allows for 26 letters is required
const int ROW_CHAR_ARR = 2;
const int COL_CHAR_ARR = 26;

int get_count(string & input);
bool check_word(int & index, string & input, int num_char[][COL_CHAR_ARR]);
int count_word(int num_char[][COL_CHAR_ARR]);
void initialize(int array[][COL_CHAR_ARR]);
void arr_to_zero(int array[][COL_CHAR_ARR]);
