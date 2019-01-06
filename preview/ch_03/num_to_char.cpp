#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int number = 65;

    // Display the value number in type int.
    cout << number << endl;

    // Display the value number in type char.
    cout << static_cast<char>(number) << endl;
    
    return 0;
}
