// Che Blankenship

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#include"DayOfYear.h"


int main()
{

    //
    // Case one
    //
    int inputDay;

    while (!(cout << "Day of the year: " && cin >> inputDay) || !(inputDay > 0))
    {
        cin.clear(); //clear bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid input. Please re-enter(only positive numbers).\n\n";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    DayOfYear first(inputDay);
    // Display
    first.print();

    cout << "Post increment: ";
    (first++).print();

    cout << "Post decrement: ";
    (first--).print();

    cout << "Pre increment: ";
    (++first).print();

    cout << "Pre decrement: ";
    (--first).print();




    //
    // Case two
    //

    int dayOfMonth;
    string month;

    // Set the Month
    while (!(cout << "Enter the month (January-December): " && getline(cin, month)) || (month.find_first_not_of(' ')))
    {
        cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
        cin.clear(); //clear bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clean the whole thing.
    }

    // Set the day of month
    while (!(cout << "Day of the month (1-31): " && cin >> dayOfMonth) || !(dayOfMonth > 0 && dayOfMonth < 32))
    {
        cin.clear(); //clear bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid input. Please re-enter(only positive numbers).\n\n";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    DayOfYear second(month, dayOfMonth);
    second.print();

    cout << "Post increment: ";
    (second++).print();

    cout << "Post decrement: ";
    (second--).print();

    cout << "Pre increment: ";
    (++second).print();

    cout << "Pre decrement: ";
    (--second).print();


    return 0;
}
