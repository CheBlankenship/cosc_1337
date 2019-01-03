#include "iostream"
using namespace std;


// Calculate cirle comferense
// Common formula : comf = π * 3.14

int main() {

    const double pi = 3.14;
    double diameter;
    double circomference;

    // Input
    cout << "Enter the diameter length ";
    cin >> diameter;

    //Calcualtion
    circomference = pi * diameter;

    // print
    cout << "circomference is " << circomference << endl;

    return 0;
}
