#include "iostream"
using namespace std;


int main(int argc, char const *argv[]) {

    int x = 25;
    //Address
    cout << "The address of x is " << &x << endl;
    //Size
    cout << "The size of x is " << sizeof(x) << " bytes\n";
    //Value
    cout << "The value in x is " << x << endl;

    return 0;
}
