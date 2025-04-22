#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto arr = make_unique<int[]>(5); // note the [] here

    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
        cout << arr[i] << " ";
    }

    // Automatically calls delete[] when arr goes out of scope
    return 0;
}