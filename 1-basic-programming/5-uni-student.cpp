#include <iostream>
#include <ostream>

struct Student {
    char name[15];
    int studentNumber;
    float mathGrade;
    float basicProgrammingGrade;
};

float studentGpa(Student student){
    return (student.mathGrade + student.basicProgrammingGrade) / 2;
}

int main () {
    Student studentOne;
    std::cin >> studentOne.name;
    studentOne.studentNumber = 1234531;
    studentOne.mathGrade = 5.50;
    studentOne.basicProgrammingGrade = 6.00;

    std::cout << "avarage: " << studentOne.name <<  " " <<  studentGpa(studentOne) << std::endl;
}
