#include <iostream>
#include "../Utils/Utils.h"
#include <unordered_map>
using namespace std;

// Longest Word
// Have the function LongestWord(sen) take the sen parameter being passed and return the longest word in the string. If there are two or more words that are the same length, return the first word from the string with that length. Ignore punctuation and assume sen will not be empty. Words may also contain numbers, for example "Hello world123 567"
// Examples
// Input: "fun&!! time"
// Output: time
// Input: "I love dogs"
// Output: love

// TC: O(n) SC: O(1)
void LongestWord(string sentence)
{
    int nextStart = 0;
    int maxWordStart = 0;
    int maxWordLength = 0;
    int specialCharsCount = 0;
    string result;
    int fullLength = sentence.length();

    for (int i = 0; i < fullLength; i++)
    {
        // handling special characters
        if(sentence[i] == '&' || sentence[i] == '!')
            ++specialCharsCount;
        if (sentence[i] == ' ' || i == fullLength - 1)
        {
            // handling end index conditon to the correct length for the last word
            if(i == fullLength -1)
                specialCharsCount--;
            int currStart = nextStart;
            nextStart = i + 1;
            int wordLength = i - currStart -specialCharsCount;
            specialCharsCount = 0;
            if(wordLength > maxWordLength)
            {
                maxWordLength = wordLength;
                maxWordStart = currStart;
            }
        }
    }

    for ( int i = maxWordStart; i <= maxWordStart + maxWordLength; i++)
        cout << sentence[i];
    cout << endl;
}

int main(int argc, char *argv[])
{
    string sentence = "fthi time&&&!!!!";
    LongestWord(sentence);
}