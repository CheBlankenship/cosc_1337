#include <iostream>
#include <iomanip>

using namespace std;



int sum(int num1, int num2) {
    return num1 + num2;
}


int main(int argc, char const *argv[]) {
    int value1 = 20,
    value2 = 40,
    total;

    // Call the sum function, passing the contents of
    // value1 and value2 as arguments. Assign the return
    // value to the total variable.
    total = sum(value1, value2);

    // Display the sum of the values.
    cout << "The sum of " << value1 << " and " << value2 << " is " << total << endl;

    return 0;
}
