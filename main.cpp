#include <iostream>
#include <vector>

std::vector<int> twice(int x) {
    return {x, x};
}
int main() {
    std::cout << "Hello, C++!" << std::endl;
    std::cout << "Twice of 5: " << twice(5)[0] << ", " << twice(5)[1] << std::endl;
    return 0;
}