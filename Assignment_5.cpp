#include <iostream>
#include <string>
using namespace std;

// Base Class
class Student {
protected:
    int rollNo;
    string name;
public:
    virtual void input() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
    }

    virtual void display() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
    }

    virtual ~Student() {} // Virtual destructor for safe cleanup
};

// Derived Class 1
class Marks : public Student {
protected:
    float sub1, sub2, sub3;
public:
    void input() override {
        Student::input();
        cout << "Enter Marks of Subject 1: ";
        cin >> sub1;
        cout << "Enter Marks of Subject 2: ";
        cin >> sub2;
        cout << "Enter Marks of Subject 3: ";
        cin >> sub3;
    }

    void display() override {
        Student::display();
        cout << "\nSubject 1 Marks: " << sub1;
        cout << "\nSubject 2 Marks: " << sub2;
        cout << "\nSubject 3 Marks: " << sub3;
    }
};

// Derived Class 2
class Result : public Marks {
    float total;
    float percentage;
    char grade;
public:
    void calculate() {
        total = sub1 + sub2 + sub3;
        percentage = total / 3.0;

        if (percentage >= 75)
            grade = 'A';
        else if (percentage >= 60)
            grade = 'B';
        else if (percentage >= 45)
            grade = 'C';
        else
            grade = 'F';
    }

    void display() override {
        Marks::display();
        calculate();
        cout << "\nTotal Marks: " << total;
        cout << "\nPercentage: " << percentage << "%";
        cout << "\nGrade: " << grade << endl;
    }
};

// Main Function
int main() {
    Student* s; // Base class pointer
    Result r;   // Derived class object

    cout << "===== Student Result Management System =====\n";

    s = &r;  // Pointer of base pointing to derived class
    s->input();   // Calls derived input() using virtual function
    cout << "\n--- Student Result ---";
    s->display(); // Calls derived display() using runtime polymorphism

    return 0;
}