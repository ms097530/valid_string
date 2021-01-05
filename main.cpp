// The isValid function is designed to solve the problem given at
// https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
// The function passes all tests on the website

#include <map>
#include <string>
#include <iostream>

using namespace std;

// Complete the isValid function below.
string isValid(string s) 
// the problem wants the function to return "YES" if all characters in a given string s have the same count, or
// if a single character can be removed to meet this condition, and return "NO" otherwise
{
    map<char, int> charDict;
    for (char start = 'a'; start <= 'z'; ++start)
    {
        charDict[start] = 0;
    }
    
    for (int i = 0; i < s.length(); ++i)
    // count num occurences of each character
    {
        ++charDict[s[i]];
    }
        
    int count = 0;

    // used to keep track of the number of characters with a count of 1,
    // this may allow for a valid string to be made by removing this character altogether
    // i.e., a = 3, b = 3, c = 3, d = 1
    // if we remove d, a = b = c, thus the return value should be "YES"
    int numOne = 0;   
    int min = INT_MAX;    
    for (char ch = 'a'; ch <= 'z'; ++ch)
    // find minimum number of counts for a character
    {
        if (charDict[ch] < min && charDict[ch] != 0)
            min = charDict[ch];
        if (charDict[ch] == 1)
            ++numOne;
    }
    if (numOne == 1)    // find next lowest value
    {
        for (char ch = 'a'; ch <= 'y'; ++ch)
        {
            if (charDict[ch] > 1 && charDict[ch] <= charDict[ch+1])
                min = charDict[ch];
        }
    }
    
    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        if (charDict[ch] > min)        
            count += (charDict[ch] - min);            
    }
    
    if (numOne == 1 && count == 0)
        return "YES";
    else if (numOne == 1 && count > 0)
        return "NO";         
    else if (count >= 2)
        return "NO";
    else
        return "YES";
}

int main()
{
    cout << "Expected: NO " << "Actual: " << isValid("aabbccdddd") << endl;
    cout << "Expected: YES " << "Actual: " << isValid("aaabbbcccd") << endl;
    return 0;
}