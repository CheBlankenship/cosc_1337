// Example of how to use cin.get()
#include<iostream>
using namespace std;


int main(int argc, char const *argv[]) {

    char ch;

    int num;

    cout << "entr num .";
    //cin.get(ch);
    cin >> num;

    // cin.ignore();
    cout << "entr char .";
    //cin.get(ch);
    cin.get(ch);

    cout << num << " " << ch<< '\n';


    // cout << "It has paused a second time. Please press Enter again.";
    // ch = cin.get();
    //
    // cout << "It has paused a third time. Please press Enter again.";
    // cin.get();
    //
    // cout << "Thank you!";

    return 0;
}
