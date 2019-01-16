#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {

    short numbers[] = {10, 20, 30, 40, 50}; //two bytes
    // without brackets and a subscript, actually represents
    // the starting address of the array.
    cout << "The first element is " << *numbers << endl;

    return 0;
}
