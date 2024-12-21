#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;


string removePunction(string word)
{
    string result = "";
    for(char c : word)
    {
        if(isalnum(c))
        {
            result += c;
        }
    }

    return result;
}

vector<string> seperateWords(string sentence)
{
    istringstream ss(sentence);
    vector<string> words;
    string word;

    while(ss >> word)
    {
        words.push_back(removePunction(word));
    }
    return words;
}

void count_words(vector<string> words)
{
    unordered_map<string, int> wordCount;
    cout << endl;
    for(auto w: words)
    {
        wordCount[w]++;
    }

    for (auto pair : wordCount)
    {
        cout << pair.first << " : " << pair.second << endl;
    }
    cout << endl;
}

int main()
{
    unordered_map<string, int> wordCount;
    cout << "\nTHIS IS A WORD COUNTER THAT COUNTS THE FREQUENCY OF WORDS IN A SENTENCE\n";
    cout << "\nTest case 01: ";
    string sentence1 = "hello world how love hello world love";
    vector<string> words1 = seperateWords(sentence1);
    count_words(words1);

    cout << "\nTest case 02: ";
    string sentence2 = "this is a test sentence test test this";
    vector<string> words2 = seperateWords(sentence2);
    count_words(words2);

    cout << "\nTest case 03: ";
    string sentence3 = "apple orange banana apple apple banana";
    vector<string> words3 = seperateWords(sentence3);
    count_words(words3);

    cout << "\nTest case 04: ";
    string sentence4 = "hello! world, how are you doing today?";
    vector<string> words4 = seperateWords(sentence4);
    count_words(words4);

    cout << "\nTest case 05: ";
    string sentence5 = "lorem ipsum dolor sit amet lorem ipsum dolor";
    vector<string> words5 = seperateWords(sentence5);
    count_words(words5);

    cout << "\nTest case 07: ";
    string sentence6 = "the quick brown fox jumps over the lazy dog";
    vector<string> words6 = seperateWords(sentence6);
    count_words(words6);

    return 0;
}
