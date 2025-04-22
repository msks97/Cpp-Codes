#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int balancedString(string s) {
        
    unordered_map<char, int> freq;

    for(char c:s)
    {
        freq[c]++;
    }

    int n=s.length();
    
    int window =n;
    int m=n/4; 
    int i=0, l=0;   
       
    while(i<n)
    {
        freq[s[i]]--;
        while(freq['Q']<=m && freq['W']<=m && freq['E']<=m && freq['R']<=m)
        {  
            freq[s[l]]++;
            window=min(window,i-l+1);    // Update window size 
            l++;                         // remove l'th character from window
            
            if(l>=n)                     // If it reaches to n simply back of
                break;
        }
        i++;
    }
    return window;

    /*
    for(char c:{'Q', 'W', 'E', 'R'})
    {
        if(freq.find(c)!= freq.end() && freq[c]> (n/4))
        {
            count += abs(freq[c] - (n/4));
        }
            
    }*/

    //return count;
}

int main()
{
    string s = "WWEQERQWQWWRWWERQWEQ"; //q5w8e4r3
    int result = balancedString(s);
    cout<<"Count: "<<result<<endl;
    return 0;
}