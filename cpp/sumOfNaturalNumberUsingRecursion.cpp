#include<iostream>

int sumOfNnaturalNumbers(int n) {
    if (n==1) return 1;
    return n+sumOfNnaturalNumbers(n-1);
}

int main() {
    std::cout << "Sum of 5 natural numbers is: " << sumOfNnaturalNumbers(10);
    return 0;
}