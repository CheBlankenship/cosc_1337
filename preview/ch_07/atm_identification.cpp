#include <iostream>
#include <string>
#include <cctype>
using namespace std;


// It will return TRUE if the enterd PIN maches the saved PIN.
bool passwd_identification(char passWd[], char input_passWd[7]) {
    int num = 0;
    bool match = true;
    while (passWd[num] != '\0' || input_passWd[num] != '\0' || match == false) {
        if (passWd[num] != input_passWd[num]) {
            cout << "Found unmatch char during the process." << '\n';
            match = false;
            break;
        }
        num++;
    }

    return match;
}


int main(int argc, char const *argv[]) {

    const int size = 7;
    char passWd[] = "1234567"; // password store in database.
    char input_passWd[size];

    // Customer input: ENter PIN number.
    cout << "Please enter you seven digit PIN number " << '\n' << ">>> ";
    cin.getline(input_passWd, 8);

    // If
    if(passwd_identification(passWd, input_passWd)){
        cout << "Welcome to the ATM bank of America !" << '\n';
    } else {
        cout << "Please enter a valid 7 digit PIN number for your account." << '\n';
    };

    return 0;
}
