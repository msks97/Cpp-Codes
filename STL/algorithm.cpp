#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v{1,7,4,2,0,6};

    cout<<"\nUnsorted vector:";
    for(int i : v)
    {
        cout<< i<<" ";
    }

    sort(v.begin(), v.end());

    cout<<"\nSorted vector:";
    for(int i : v)
    {
        cout<< i<<" ";
    }
    


}