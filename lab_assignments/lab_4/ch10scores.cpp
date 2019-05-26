//Che Blankenship
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#include "user_score.h"

void setArrSize(int &); // prototype

int main() {

    int SIZE;
    // Set the SIZE to
    setArrSize(SIZE);

    // Create Userscore object.
    UserScore obj1(SIZE);
    obj1.inputUserScore();
    obj1.sort_arr();
    obj1.calculateAvg();
    obj1.printInfo();

    return 0;
}


// Set arr size.
void setArrSize(int &arrLength)
{
    while (!(cout << "Enter the number of grades you want to store: " && cin >> arrLength) || !(arrLength > 0))
    {
        cin.clear(); //clear bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid input. Please re-enter(only positive numbers).\n\n";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
