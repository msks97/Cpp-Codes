#include <iostream>
#include <vector>
using namespace std;

int knapsack_brute(int values[], int weights[], int capacity, int n)
{
    cout<<"Knapsack_brute_force ("<<n<<", "<<capacity<<")"<<endl;
    if(capacity == 0 or n == 0) return 0;

    else if (weights[n-1]>capacity)
        return knapsack_brute(values, weights, capacity, n-1);

    else
    {
        int include = values[n-1]+ knapsack_brute(values, weights, capacity - weights[n-1], n-1);
        int exclude = knapsack_brute(values, weights, capacity, n-1);
        return max(include, exclude);
    }
}

vector<vector<int>> memo(100, vector<int>(100,-1));
int knapsack_memo(int values[], int weights[], int capacity, int n)
{
    if(memo[n][capacity] != -1)
    {
        cout<<"From Memory ("<<n<<", "<<capacity<<")"<<endl;
        return memo[n][capacity];
    } 

    int result;

    cout<<"Knapsack_memo ("<<n<<", "<<capacity<<")"<<endl;
    if(capacity == 0 or n == 0) result = 0;

    else if (weights[n-1]>capacity)
        result = knapsack_memo(values, weights, capacity, n-1);

    else
    {
        int include = values[n-1]+ knapsack_memo(values, weights, capacity - weights[n-1], n-1);
        int exclude = knapsack_memo(values, weights, capacity, n-1);
        result = max(include, exclude);
    }

    memo[n][capacity] = result;
    return result;
}

int knapsack_tabular(int values[], int weights[], int capacity, int n)
{
    vector<vector<int>> tab(n+1, vector<int>(capacity+1,0));

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=capacity; j++)
        {
            cout<<"Knapsack_tab ("<<i<<", "<<j<<")"<<endl;
            if (weights[i-1]<=j)
            {
                int include = values[i-1]+ tab[i-1][j-weights[i-1]];
                int exclude = tab[i-1][j];
                tab[i][j] = max(include, exclude);
            }
            else
            {
                tab[i][j] = tab[i-1][j];
            }

        }
    }

    return tab[n][capacity];

}





int main()
{
    int values[] = {300, 200, 400, 500};
    int n = sizeof(values)/sizeof(values[0]);
    int weights[] = {2, 1, 5, 3};
    int capacity = 10;
    int result = knapsack_brute(values, weights, capacity, n );
    cout<<"\nMaximum value in Knapsack_brute = "<<result<< endl;

    result = knapsack_memo(values, weights, capacity, n );
    cout<<"\nMaximum value in Knapsack_memo = "<<result<<endl;

    result = knapsack_tabular(values, weights, capacity, n );
    cout<<"\nMaximum value in Knapsack_memo = "<<result<<endl;

    return 0;
}