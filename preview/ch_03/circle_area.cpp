#include "iostream"
#include "cmath"
using namespace std;

int main() {

    const double pi = 3.14;
    double area, radius;

    // Input - get radius.
    cout << "Enter the radius length: ";
    cin >> radius;

    // Calculation
    // Common formula : a = π * r^2
    area = ((radius*radius) * pi);

    cout << "Area is " << area << '\n';


    return 0;
}
