#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;
    string gender;

public:
    void inputPersonDetails() {
        cout << "\nEnter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Gender: ";
        getline(cin, gender);
    }

    void displayPersonDetails() {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nGender: " << gender;
    }
};

// Derived Class: Doctor
class Doctor : public Person {
    string specialization;
    int experience;
public:
    void inputDoctorDetails() {
        inputPersonDetails();
        cout << "Enter Specialization: ";
        getline(cin, specialization);
        cout << "Enter Years of Experience: ";
        cin >> experience;
    }

    void displayDoctorDetails() {
        cout << "\n--- Doctor Details ---";
        displayPersonDetails();
        cout << "\nSpecialization: " << specialization;
        cout << "\nExperience: " << experience << " years\n";
    }
};

// Derived Class: Nurse
class Nurse : public Person {
    string department;
    string shift;
public:
    void inputNurseDetails() {
        inputPersonDetails();
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter Shift (Day/Night): ";
        getline(cin, shift);
    }

    void displayNurseDetails() {
        cout << "\n--- Nurse Details ---";
        displayPersonDetails();
        cout << "\nDepartment: " << department;
        cout << "\nShift: " << shift << "\n";
    }
};

// Derived Class: Admin
class Admin : public Person {
    string role;
    int salary;
public:
    void inputAdminDetails() {
        inputPersonDetails();
        cout << "Enter Role: ";
        getline(cin, role);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayAdminDetails() {
        cout << "\n--- Admin Details ---";
        displayPersonDetails();
        cout << "\nRole: " << role;
        cout << "\nSalary: " << salary << "\n";
    }
};

// Main Program
int main() {
    Doctor d;
    Nurse n;
    Admin a;
    int choice;

    do {
        cout << "\n===== Hospital Management System =====";
        cout << "\n1. Add & Display Doctor Details";
        cout << "\n2. Add & Display Nurse Details";
        cout << "\n3. Add & Display Admin Details";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                d.inputDoctorDetails();
                d.displayDoctorDetails();
                break;
            case 2:
                n.inputNurseDetails();
                n.displayNurseDetails();
                break;
            case 3:
                a.inputAdminDetails();
                a.displayAdminDetails();
                break;
            case 4:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "\nInvalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}