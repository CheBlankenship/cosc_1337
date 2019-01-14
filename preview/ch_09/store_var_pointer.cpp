#include<iostream>
using namespace std;


int main(int argc, char const *argv[]) {

    int x = 25; //int var
    int *ptr = nullptr; // pointer var. can point to an int.

    cout << "The original x address is " << &x << endl;
    ptr = &x; //Store the address of x into ptr.
    cout << "The value in x is " << x << endl;
    cout << "The address of x is " << ptr << endl;


    // Indirection
    // Assign 100 to the location pointed to by ptr.
    // This will actually assign 100 to x.
    // Address wont change.
    *ptr = 100;
    cout << "\nAfter indirection" << endl;
    cout << "The value in x is " << x << endl;
    cout << "The address of x is " << ptr << endl;

    return 0;
}
