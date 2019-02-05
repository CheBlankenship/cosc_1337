// Che Blankenship

#include <iostream>
#include <string>
#include <iomanip>


int main()
{

    const int SIZE = 3;
    std::string runner_names[SIZE];
    double runners_finish_time[SIZE];

    //Runner names.
    for (int i = 0; i < SIZE; i++)
    {
        while (!(std::cout << "Enter name for runner " << i+1 << ": " && getline(std::cin, runner_names[i])) || (runner_names[i].find_first_not_of(' ')))
        {
            std::cout << "Error: Invalid input. Press ENTER to continue." << "\n\n";
            std::cin.clear(); //clear bad input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the whole thing.
        }

    }

    // Runners finish time.
    for (int m = 0; m < SIZE; m++)
    {
        while (!(std::cout << "Enter finish time for runner " << m+1 << " (seconds): " && std::cin >> runners_finish_time[m]) || !(runners_finish_time[m] > 0))
        {
            std::cin.clear();//clear bad input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Invalid input.\nPlease re-enter(only positive numbers).\n\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


    //Sort: bubble-sort
    bool continue_sort = true;
    int loop_num = SIZE - 1;
    std::string save_temp_name;
    double save_temp_time;

    while (continue_sort && loop_num > 0)
    {
        continue_sort = false;
        for (int index = 0; index < loop_num; index++)
        {
            if (runners_finish_time[index] > runners_finish_time[index+1])
            {
                continue_sort = true;
                // Re-order finish time.
                save_temp_time = runners_finish_time[index];
                runners_finish_time[index] = runners_finish_time[index+1];
                runners_finish_time[index+1] = save_temp_time;

                // Re-order runner names.
                save_temp_name = runner_names[index];
                runner_names[index] = runner_names[index+1];
                runner_names[index+1] = save_temp_name;

            }
        }
    }

    /*
    Display on the console.
    [Cases]
    If there are 3 people, 4 cases.
    2^(n-1) cases , (n is the number of people).
    */
    std::cout << "--------------- List of runners ---------------" << '\n';

    // 1) 1st - 1st - 1st
    if (runners_finish_time[0] == runners_finish_time[1] && runners_finish_time[1] == runners_finish_time[2])
    {
        for (int j = 0; j < SIZE; j++)
        {
            //std::cout << j+1 << ": Name: " << runner_names[j] << ", Time: " << runners_finish_time[j] <<'\n';
            std::cout << "1st: " << runner_names[j] << ", " << runners_finish_time[j] << '\n';
        }
    }
    // 2) 1st - 1st - 3rd
    else if(runners_finish_time[0] == runners_finish_time[1] && runners_finish_time[1] < runners_finish_time[2])
    {
        std::cout << "1st: " << runner_names[0] << ", " << runners_finish_time[0] << '\n';
        std::cout << "1st: " << runner_names[1] << ", " << runners_finish_time[1] << '\n';
        std::cout << "3rd: " << runner_names[2] << ", " << runners_finish_time[2] << '\n';
    }
    // 3) 1st - 2nd - 2nd
    else if(runners_finish_time[0] < runners_finish_time[1] && runners_finish_time[1] == runners_finish_time[2])
    {
        std::cout << "1st: " << runner_names[0] << ", " << runners_finish_time[0] << '\n';
        std::cout << "2nd: " << runner_names[1] << ", " << runners_finish_time[1] << '\n';
        std::cout << "3nd: " << runner_names[2] << ", " << runners_finish_time[2] << '\n';
    }
    // 4) 1st - 2nd - 3rd
    else if(runners_finish_time[0] < runners_finish_time[1] && runners_finish_time[1] < runners_finish_time[2])
    {
        std::cout << "1st: " << runner_names[0] << ", " << runners_finish_time[0] << '\n';
        std::cout << "2nd: " << runner_names[1] << ", " << runners_finish_time[1] << '\n';
        std::cout << "3rd: " << runner_names[2] << ", " << runners_finish_time[2] << '\n';
    }
    // Negative case.
    else
    {
        std::cout << "ERROR: Did not match any of the statement order." << '\n';
    }

    return 0;
}
