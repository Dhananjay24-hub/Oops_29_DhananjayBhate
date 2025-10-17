#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Television {
    int modelNo;
    float price;
    float screenSize;

public:
    // Default constructor
    Television() {
        modelNo = 0;
        price = 0.0;
        screenSize = 0.0;
    }

    // Overloaded >> operator for input
    friend istream& operator>>(istream& in, Television& t) {
        cout << "\nEnter Model Number: ";
        in >> t.modelNo;
        cout << "Enter Price: ";
        in >> t.price;
        cout << "Enter Screen Size (in inches): ";
        in >> t.screenSize;

        // Exception handling block
        try {
            // Model number validation
            if (t.modelNo > 9999)
                throw runtime_error("Invalid Model Number! Must be 4 digits or less.");

            // Price validation
            if (t.price < 0 || t.price > 5000)
                throw runtime_error("Invalid Price! Must be between 0 and 5000.");

            // Screen size validation
            if (t.screenSize < 12 || t.screenSize > 70)
                throw runtime_error("Invalid Screen Size! Must be between 12 and 70 inches.");
        }
        catch (runtime_error& e) {
            cout << "\nException: " << e.what() << endl;
            // Reset invalid data to defaults
            t.modelNo = 0;
            t.price = 0;
            t.screenSize = 0;
        }

        return in;
    }

    // Overloaded << operator for output
    friend ostream& operator<<(ostream& out, const Television& t) {
        out << "\n--- Television Details ---";
        out << "\nModel Number: " << t.modelNo;
        out << "\nPrice: " << t.price;
        out << "\nScreen Size: " << t.screenSize << " inches\n";
        return out;
    }
};

int main() {
    Television tv;
    cout << "===== Television Data Entry =====" << endl;

    cin >> tv;   // Input using overloaded >> operator
    cout << tv;  // Output using overloaded << operator

    return 0;
}