#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <limits>

using namespace std;

enum enTrim { Left = 1, Right = 2, Both = 3 };

// Split must be declared before functions that use it
vector<string> split(string s, string delimiter)
{
    vector<string> words;
    int pos;

    while ((pos = s.find(delimiter)) != string::npos)
    {
        if (pos > 0)
            words.push_back(s.substr(0, pos));

        s.erase(0, pos + delimiter.length());
    }

    if (!s.empty())
        words.push_back(s);

    return words;
}

void FirstLetter(string s)
{
    bool first = true;

    for (char c : s)
    {
        if (first && c != ' ')
            cout << c << endl;

        first = (c == ' ');
    }
}

string CapitalFirstLetter(string s)
{
    bool first = true;

    for (char& c : s)
    {
        if (first && c != ' ')
            c = toupper(c);

        first = (c == ' ');
    }

    return s;
}

string LowerFirstLetter(string s)
{
    bool first = true;

    for (char& c : s)
    {
        if (first && c != ' ')
            c = tolower(c);

        first = (c == ' ');
    }

    return s;
}

string lowerAll(string s)
{
    for (char& c : s)
        c = tolower(c);

    return s;
}

string UpperAll(string s)
{
    for (char& c : s)
        c = toupper(c);

    return s;
}

char invertletter(char c)
{
    if (isupper(c))
        return tolower(c);

    if (islower(c))
        return toupper(c);

    return c;
}

string invertAllLetter(string s)
{
    for (char& c : s)
        c = invertletter(c);

    return s;
}

int countUpper(string s)
{
    int count = 0;

    for (char c : s)
        if (isupper(c))
            count++;

    return count;
}

int countLower(string s)
{
    int count = 0;

    for (char c : s)
        if (islower(c))
            count++;

    return count;
}

string ReadString(string message)
{
    cout << message;

    string s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);

    return s;
}

int ReadNumber(string message)
{
    cout << message;

    int num;
    cin >> num;

    return num;
}

char ReadChar(string message)
{
    cout << message;

    char c;
    cin >> c;

    return c;
}

int countChar(string s, char c)
{
    int count = 0;

    for (char x : s)
        if (x == c)
            count++;

    return count;
}

int countletter(string s, char letter, bool MatchCase = true)
{
    int count = 0;

    for (char c : s)
    {
        if (MatchCase ? c == letter : tolower(c) == tolower(letter))
            count++;
    }

    return count;
}

bool isVowel(char c)
{
    c = tolower(c);

    return c == 'a' || c == 'e' || c == 'i' ||
        c == 'o' || c == 'u';
}

int countVowels(string s)
{
    int count = 0;

    for (char c : s)
        if (isVowel(c))
            count++;

    return count;
}

void printVowels(string s)
{
    for (char c : s)
        if (isVowel(c))
            cout << c << "  ";
}

void printWord(string s)
{
    vector<string> words = split(s, " ");

    for (string& word : words)
        cout << word << endl;
}

int countWords(string s)
{
    return static_cast<int>(split(s, " ").size());
}

string trim_left(string s)
{
    int pos = s.find_first_not_of(' ');

    return pos == string::npos ? "" : s.substr(pos);
}

string trim_right(string s)
{
    int pos = s.find_last_not_of(' ');

    return pos == string::npos ? "" : s.substr(0, pos + 1);
}

string trim(string s)
{
    return trim_left(trim_right(s));
}

string join(vector<string> words, string delim)
{
    if (words.empty())
        return "";

    string result = words[0];

    for (int i = 1; i < words.size(); i++)
        result += delim + words[i];

    return result;
}

string join(string arr[5], short size, string delim)
{
    if (size <= 0)
        return "";

    string result = arr[0];

    for (int i = 1; i < size; i++)
        result += delim + arr[i];

    return result;
}

string reverseString(string s)
{
    vector<string> words = split(s, " ");
    string result;

    for (int i = words.size() - 1; i >= 0; i--)
    {
        if (!result.empty())
            result += " ";

        result += words[i];
    }

    return result;
}

string reverseString1(string s)
{
    return reverseString(s);
}

string replaceWord(
    string s,
    string oldWord,
    string newWord,
    bool matchCase = true)
{
    vector<string> words = split(s, " ");

    for (string& word : words)
    {
        if (matchCase)
        {
            if (word == oldWord)
                word = newWord;
        }
        else
        {
            if (lowerAll(word) == lowerAll(oldWord))
                word = newWord;
        }
    }

    return join(words, " ");
}

string Myreplace(
    string s,
    string oldWord,
    string newWord,
    bool matchCase)
{
    size_t pos = s.find(oldWord);

    if (pos == string::npos)
        return s;

    string found = s.substr(pos, oldWord.length());

    if (matchCase ? found == oldWord
        : lowerAll(found) == lowerAll(oldWord))
    {
        s.replace(pos, oldWord.length(), newWord);
    }

    return s;
}

string removePunct(string s)
{
    string result;

    for (char c : s)
        if (!ispunct(c))
            result += c;

    return result;
}