#include "iostream"
using namespace std;

int main() {

    // Convert seconds into x min y sec.
    int total_seconds;

    // Input
    cout << "Enter the seconds? ";
    cin >> total_seconds;

    // Define min and sec
    int min, sec;

    // Get number of min.
    min = total_seconds / 60;
    // Get number of sec.
    sec = total_seconds % 60;

    cout << min << " Minutes " << sec << " Seconds" << '\n';

    return 0;
}
