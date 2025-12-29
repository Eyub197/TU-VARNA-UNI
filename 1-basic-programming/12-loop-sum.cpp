#include <iostream>

using namespace std;

int main() {
    double sum = 0.0;

    for (int i = 1; i <= 50 ; i++) {
        sum += 1.0 / i;
    }

    cout << "the sum is: " << sum << endl;
    return 0;
}
