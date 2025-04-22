#include <iostream>
#include <cstring>

int main() {
    char str1[10] = "Hello";
    char str2[] = "123456";  // 6 chars + null terminator

    // Safe concatenation
    int s1 = sizeof(str1);
    int s2 = strlen(str1);
    strncat(str1, str2, sizeof(str1) - strlen(str1) - 1);
    
    std::cout << str1 << std::endl;   // Output: Hello1234

    return 0;
}