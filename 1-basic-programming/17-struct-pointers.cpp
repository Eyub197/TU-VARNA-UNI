#include <iostream>

using  namespace std;

struct Person {
    int age;
    char name[15];
};

void printStruct(Person * person) {
    cout << person -> name << endl;
    cout << person -> age << endl;
}

int main () {
    Person person1;
    cin >> person1.name;
    cin >> person1.age;

    printStruct(&person1);
}
