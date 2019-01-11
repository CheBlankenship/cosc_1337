# include <iostream>
# include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string name, city;

    cout << "Enter your name: " << '\n';
    getline(cin, name);
    cout << "Where you live: " << '\n';
    getline(cin, city);

    cout << "Name: " << name << '\n';
    cout << "City: " << city << '\n';

    return 0;
}
