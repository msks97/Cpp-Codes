#include <iostream>
#include <stack>
#include <string>
using namespace std;

void storeReverse(string origString, stack<char> &reverseString)
{
    for (char c:origString)
    {
        reverseString.push(c);
    }
}
bool checkPalindrome(string origString)
{
    stack<char> reverseString;
    storeReverse(origString, reverseString);

    bool result = true;

    if(origString.length() == reverseString.size())
    {
        for( char c: origString)
        {
            char currChar = reverseString.top();
            if(currChar != c)
            {
                result = false;
                break;
            }
            reverseString.pop();
        }
    }
    else
    {
        result = false;

    }
    return result;
}

void printResult(string origString)
{
    cout<<"\nIs "<<origString<<" a palindrome? - "<<boolalpha<<checkPalindrome(origString);
}



int main()
{
    string origString[5];

    origString[0] = "racecar";
    origString[1] = "malayalam";
    origString[2] = "civic";
    origString[3] = "good";
    origString[4] = "dog";

    for (string str:origString)
    {
        printResult(str);
    }

    
    return 0;
}