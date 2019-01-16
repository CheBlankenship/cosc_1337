#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char const *argv[]) {

    const int num_coins = 5;
    double coins[num_coins] = {0.05, 0.1, 0.25, 0.5, 1.0};
    double *doublePtr; // Pointer to a double
    int count; // Array index

    // Assign the address of the coins array to doublePtr.
    doublePtr = coins;
    cout << "Here are the values in the coins array:\n";
    // Print the element using pointer
    for (count = 0; count < num_coins; count++) {
        cout << "print >> " << doublePtr[count] << '\n';
    }

    // Reverse
    for (count = count-1; count >= 0; count--) {
        cout << "print(reverse) >> " << doublePtr[count] << '\n';
    }


    return 0;
}
