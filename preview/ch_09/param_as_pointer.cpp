
// This program demonstrates that a pointer may be used as a
// parameter to accept the address of an array.
// Example of how to use pointers as a parameter value.

#include<iostream>
#include<iomanip>
using namespace std;


void getSales(double *arr, int size) {
    for (int count=0; count < size; count++) {
        cout << "Enter the sales figure for quarter ";
        cout << (count + 1) << ": ";
        cin >> arr[count];
    }
};


double totalSales(double *arr, int size) {
    double total_sum;
    for (int count = 0; count < size; count++) {
        total_sum += *arr;
        arr++;
    }
    return total_sum;
}



int main(int argc, char const *argv[]) {

    const int QTRS = 4;
    double sales[QTRS];

    // Get the sales data for all quarters.
    getSales(sales, QTRS);

    /// Set the numeric output formatting.
    cout << fixed << showpoint << setprecision(2);

    // Display the total sales for the year.
    cout << "The total sales for the year are $";
    cout << totalSales(sales, QTRS) << endl;

    return 0;
}
