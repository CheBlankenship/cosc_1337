#include <iostream>
#include <iomanip>

using namespace std;


void helloWorld() {
    cout << "Hello world!" << '\n';
}


void sum_num(int a, int b) {
    cout << "Sum is " << a + b << '\n';
}

int main(int argc, char const *argv[]) {
    helloWorld();

    // Sum
    int a, b;
    cout << "First number >> ";
    cin >> a;
    cout << "Second number >> ";
    cin >> b;

    sum_num(a, b);

    return 0;
}
