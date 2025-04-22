//find common characters in two vectors

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

bool itemInCommon(vector<int> v1, vector<int> v2)
{
    unordered_map<int, bool> myMap;
    
    for(auto i : v1)
    {
        myMap.insert({i,true});
    }
    
    int flag=0;

    for (auto j : v2)
    {
        if(myMap[j])
        {
            cout<<"Item "<<j<<" matches"<<endl;
            flag =1;
        } 
            
    }

    if(flag == 0) return false;
    else return true;
}


int main()
{

    vector<int> v1{2,4,5};
    vector<int> v2{1,3,6,4,5};

    bool match = itemInCommon(v1, v2);
    cout<<"Is there any item matching: "<<boolalpha<<match<<endl;
    return 0;
}