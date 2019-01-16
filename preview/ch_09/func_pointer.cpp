#include <iostream>
#include <iomanip>
using namespace std;


void getNumber(int *input) {
    cout << "Enter an integer number: ";
    cin >> *input;
}

void doubleValue(int *val) {
    *val *= 2;
}


// Set val address
void setTwo(int *val) {
    *val = 2;
    cout << "The first element is " << val << endl;
    //return val;
}


 int main() {
    int number;
    // Call getNumber and pass the address of number.
    getNumber(&number);
    // Call doubleValue and pass the address of number.
    doubleValue(&number);
    // Display the value in number.
    cout << "That value doubled is " << number << endl;
    return 0;
}
