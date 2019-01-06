#include "iostream"
#include "cmath"
using namespace std;


int main(int argc, char const *argv[]) {
    int books, months;
    double perMonth;

    cout << "How many books do you plan to read? ";
    cin >> books;
    cout << "How many months will it take you to read them? "; cin >> months;
    // Casting type int to double.
    // If the result is 4, it will be converted to 4.0
    // since type is double.
    perMonth = static_cast<double>(books) / months;

    cout << "That is " << perMonth << " books per month.\n";

    return 0;
}
