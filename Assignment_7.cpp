#include <iostream>
using namespace std;

// Function template for selection sort
template <class T>
void selectionSort(T arr[], int n) {
    int minIndex;
    T temp;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap elements
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Template function to display array
template <class T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;

    // Sorting integers
    cout << "Enter number of integer elements: ";
    cin >> n;
    int intArr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
        cin >> intArr[i];

    selectionSort(intArr, n);
    cout << "Sorted integers: ";
    display(intArr, n);

    // Sorting floats
    cout << "\nEnter number of float elements: ";
    cin >> n;
    float floatArr[n];
    cout << "Enter " << n << " float numbers: ";
    for (int i = 0; i < n; i++)
        cin >> floatArr[i];

    selectionSort(floatArr, n);
    cout << "Sorted floats: ";
    display(floatArr, n);

    return 0;
}