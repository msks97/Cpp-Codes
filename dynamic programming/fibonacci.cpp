#include <iostream>
#include <vector>

using namespace std;

static int counter = 0; 

vector<int> memo(100,-1);
int fib(int n) //memoization
{
    counter++;
    if(memo[n]!= -1)
    {
        return memo[n];
    }

    if (n==0 || n ==1) return n;

    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int normalfib(int n)
{
    counter++;
    if(n==0) return 0;

    if (n==1) return 1;

    return normalfib(n-1)+normalfib(n-2);
}

//bottom up approach 
//this is without memoization as memoization is not a worthed trade off here since that will also give O(n)
int bottomupfib(int n) 
{
    vector<int> fiblist(n+1);
    fiblist[0] = 0;
    fiblist[1] = 1;

    for(int index = 2; index<= n;index++)
    {  
        counter++;
        fiblist[index] = fiblist[index-1]+ fiblist[index-2];
    }
    return fiblist[n];
}

int main()
{
    int n = 8;
    cout<<"Fib sequence for "<<n<<" is : "<<fib(n)<<endl;

    cout<<"Counter: "<<counter<<endl;

    return 0;
}