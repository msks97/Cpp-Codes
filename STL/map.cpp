#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    map<string, string> contacts;

    contacts["Shaswat"] = "123456";
    contacts["Namita"] = "1234124";
    contacts["Abhishek"] = "6867856";

    for(auto element: contacts)
    {
        cout<<element.first<<" : "<<element.second<<endl;
    }



    return 0;
}