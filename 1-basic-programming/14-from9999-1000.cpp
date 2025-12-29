#include <iostream>

using namespace std;

int main() {

    for (int i = 9999; i >= 1000 ; i--) {
        int a, b, c, d;
        a = i % 10;
        b = i / 10 % 10;
        c = i / 100 % 10;
        d = i / 1000;

        if(!(a == b || a == c || a == d || b == c || b == d || c == d))
            cout << i << endl;
    }

    return 0;
}
