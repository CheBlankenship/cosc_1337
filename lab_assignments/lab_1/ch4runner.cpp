// Che Blankenship

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <vector>
// using namespace std;

int main()
{

    const int SIZE = 3;
    std::string runner_names[SIZE];
    double runners_finish_time[SIZE];



    for (int i = 0; i < SIZE; i++)
    {
        /*
        Runner name
        Cases to check.
          1) Input type is not integer.
          2) Input is a negative number.
        */
        std::cout << "Enter runner name: ";
        while (!(std::getline(std::cin, runner_names[i])) || runner_names[i].find_first_not_of(' '))
        {
            std::cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
            std::cin.clear(); //clear bad input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
            std::cout << "Enter runner name: ";
        }

        /*
        Runners finish time.
        Cases to check.
          1) Check if input type is integer.
          2) Check if input is a positive number.
        */
        std::cout << "Enter runners finish time(hour): " ;
        while (!(std::cin >> runners_finish_time[i]) || !(runners_finish_time[i] > 0))
        {
            std::cin.clear();//clear bad input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
            // Error message.
            std::cout << "Error: Invalid input.\nPlease re-enter(only positive numbers).\n\n";
            std::cout << "Enter runners finish time(hour): " ;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }

    /*
    Sort
    Followed the sort-bubble-sort approach from the book
    "Problem solving with algorithms and data structures".
    Author: Brad Miller, David Ranum
    */
    bool continue_sort = true;
    int loop_num = SIZE - 1;
    std::string save_temp_name;
    int save_temp_time;
    while (continue_sort && loop_num > 0) {
        continue_sort = false;
        for (int index = 0; index < loop_num; index++)
        {
            if (runners_finish_time[index] > runners_finish_time[index+1])
            {
                continue_sort = true;
                // Swap the order by accessing the index.
                // Runners finish time.
                save_temp_time = runners_finish_time[index];
                runners_finish_time[index] = runners_finish_time[index+1];
                runners_finish_time[index+1] = save_temp_time;

                // Change runner names order.
                save_temp_name = runner_names[index];
                runner_names[index] = runner_names[index+1];
                runner_names[index+1] = save_temp_name;

            }
        }
    }

    std::cout << "--------------- List of runners ---------------" << '\n';
    for (int j = 0; j < SIZE; j++)
    {
        std::cout << j+1 << ": Name: " << runner_names[j] << ", Time: " << runners_finish_time[j] <<'\n';
    }




    return 0;
}
