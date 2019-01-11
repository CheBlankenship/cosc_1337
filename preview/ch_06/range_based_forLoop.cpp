#include "iostream"
#include "string"
using namespace std;


int main(int argc, char const *argv[]) {
    int nums[] = {1, 2, 3};

    for (int val: nums) {
        cout << "Num >> " << val << '\n';
    }


    string planets[] = { "Mercury", "Venus", "Earth", "Mars",
                         "Jupiter", "Saturn", "Uranus",
                         "Neptune", "Pluto (a dwarf planet)"};

    cout << "Here are the planets:" << '\n';

    // Display the list of planets.
    for (string val: planets) {
        cout << val << '\n';
    }

    //Sum all the elements.
    int sum_result = 0;
    for (int n: nums) {
        // cout << "N > " << n << '\n';
        sum_result += nums[n-1];
    }
    cout << "Total >> " << sum_result << '\n';

    return 0;
}
