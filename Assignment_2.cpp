#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    float price;

    void input() {
        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
        cout << "Enter Book Price: ";
        cin >> price;
    }

    void display() {
        cout << "\nBook ID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nPrice: " << price << endl;
    }
};

int main() {
    Book books[100];
    int count = 0;
    int choice;

    do {
        cout << "\n===== Book Management System =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display All Books";
        cout << "\n3. Search Book";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                books[count].input();
                count++;
                cout << "\nBook Added Successfully!\n";
                break;
            }

            case 2: {
                if (count == 0) {
                    cout << "\nNo books to display!\n";
                } else {
                    cout << "\n--- Book Details ---";
                    for (int i = 0; i < count; i++) {
                        books[i].display();
                    }
                }
                break;
            }

            case 3: {
                if (count == 0) {
                    cout << "\nNo books available!\n";
                    break;
                }

                int searchId;
                cout << "\nEnter Book ID to search: ";
                cin >> searchId;
                bool found = false;

                for (int i = 0; i < count; i++) {
                    if (books[i].id == searchId) {
                        cout << "\nBook Found:\n";
                        books[i].display();
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "\nBook not found!\n";

                break;
            }

            case 4:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}