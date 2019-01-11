#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {

    const int a_score = 90,
              b_score = 80,
              c_score = 70,
              d_score = 60;

    int testScore;

    // Get score
    cout << "Enter the test score: ";
    cin >> testScore;

    // Check the grade.
    if (testScore >= a_score) {
        cout << "Your grade is A." << '\n';
    }
    else {
        if (testScore >= b_score) {
            cout << "Your grade is B." << '\n';
        }
        else {
            if (testScore >= c_score) {
                cout << "Your grade is C." << '\n';
            }
            else {
                if (testScore >= d_score) {
                    cout << "Your grade is D." << '\n';
                }
                else {
                    if (d_score > testScore && testScore >= 0) {
                        cout << "No grade" << '\n';
                    }
                    else {
                        cout << "Enter the score larger than 0" << '\n';
                    }
                }
            }
        }
    }

    return 0;
}
