class UserScore
{
    private:
        int arrLen;
        double total;
        double *ptrArr; // Dynamically allocated arr.

    public:

        // Default
        UserScore(){cout << "Require SIZE to declare the array size." << '\n';}

        UserScore(int arrSize)
        {
            arrLen = arrSize;
            ptrArr = new double[arrSize];
        }

        // Input data
        void inputUserScore()
        {

            // Store grades into the array.
            for(int i = 0; i < arrLen; i++)
            {
                while (!(cout << "Enter the grades for student #" << i+1 << ": " && cin >> *(ptrArr+i)) || !(*(ptrArr+i) >= 0))
                {
                    cin.clear();//clear bad input
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: Invalid input.\nPlease re-enter(only positive numbers).\n\n";
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // Calculate the total.
            for (int k = 0; k < arrLen; k++)
            {
            		total += *(ptrArr + k);
            }


        }

        //Sort
        void sort_arr()
        {
            // Use STL sort function.
            sort(ptrArr, ptrArr + arrLen);
        }

        double calculateAvg() {return total / arrLen;}

        void printInfo()
        {
            cout << fixed << showpoint << setprecision(2);
            cout << "Sorted array: " << '\t';
            double *current = ptrArr;
            for (size_t m = 0; m < arrLen; m++)
            {
                cout << *(current++) << '\t';
            }
            cout << "\nAverage score: " << calculateAvg() << '\n';
        }

        ~UserScore()
        {
            // Check if the ptr is null.
            if(ptrArr != nullptr)
            {
                delete [ ] ptrArr;
                ptrArr = nullptr;
            }
        }

};
