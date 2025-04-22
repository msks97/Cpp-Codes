#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(vector<int> &num, int x) {
    int carry = 0;
    for (int i = 0; i < num.size(); i++) {
        int prod = num[i] * x + carry;
        num[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry) {
        num.push_back(carry % 10);
        carry /= 10;
    }
    return num;
}

void factorial(int n) {
    vector<int> res = {1}; // initially 1
    for (int i = 2; i <= n; ++i)
        res = multiply(res, i);

    // Print the result in reverse
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
    cout << "\n";
}

int main()
{
    int n = 5;
    cout<< "Factorial of "<<n<<" is: ";
    factorial(n);
    cout<<endl;
}