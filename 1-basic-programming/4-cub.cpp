#include <iostream>
// cub a* a* a
int findCub(int a) {
    return a * a * a;
}

int main () {
    int a;
    int b;
    int sum;

    std::cout << "Enter side: ";
    std::cin >> a;

    sum = findCub(a);

    std::cout << "the cub: " << sum << std::endl;
}
