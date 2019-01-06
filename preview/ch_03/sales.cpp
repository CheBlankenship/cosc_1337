#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main(int argc, char const *argv[]) {

    double day1, day2, day3, total;

    cout << "Enter the sales for day 1: ";
    cin >> day1;
    cout << "Enter the sales for day 2: ";
    cin >> day2;
    cout << "Enter the sales for day 3: ";
    cin >> day3;

    // Calculate total sales.
    total = day1 + day2 + day3;

    //Display the sales figures.
    cout << "\n--- Sales figures ---\n";
    cout << setprecision(5);
    cout << "Day 1: " << day1 << '\n';
    cout << "Day 2: " << day2 << '\n';
    cout << "Day 3: " << day3 << '\n';
    cout << "Total: " << total << '\n';


    return 0;
}
