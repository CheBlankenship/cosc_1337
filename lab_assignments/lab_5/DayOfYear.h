//Che Blankenship

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class DayOfYear
{

    private:
        string month;
        int dayOfMonth;
        int dayOfYear; // Necessary for pre/post inc/ decrement

    public:

        // Prototype
        DayOfYear(int);
        DayOfYear(string, int);
        void print();
        DayOfYear getValue();
        void converter(int);


        // Overload

        DayOfYear operator++()
        {
            this->dayOfYear++;			// increment +1
            // Dec -> Jan
            if (this->dayOfYear > 365)
            {
                this->dayOfYear = 1;
                month = "January";
                dayOfMonth = 1;
            }
            else
            {
                converter(this->dayOfYear);
            }

            return *this;					// return old obj
        }

        DayOfYear operator++(int)
        {
            DayOfYear objOld = *this;
            objOld.dayOfYear = this->dayOfYear;	// save the old value
            this->dayOfYear++;			// increment +1

            // December -> January
            if (this->dayOfYear > 365)
            {
                this->dayOfYear -= 365;
                this->month = "January";
                this->dayOfMonth = 1;
            }
            else
            {
                converter(this->dayOfYear);
            }

            return objOld;					// return old obj
        }

        DayOfYear operator--()
        {
            this->dayOfYear -= 1;			// decrement -1

            // Jan -> Dec
            if (dayOfYear < 1)
            {
                dayOfYear = 365;
                month = "December";
                dayOfMonth = 31;
            }
            else
            {
                converter(dayOfYear);
            }

            return *this;					// return old obj
        }

        DayOfYear operator--(int)
        {
            DayOfYear objOld = *this;
            objOld.dayOfYear = this->dayOfYear;	// save the old value
            this->dayOfYear--;			// decrement -1

            // Jan -> Dec
            if (dayOfYear < 1)
            {
                dayOfYear += 365;
                month = "December";
                dayOfMonth = 31;
            }
            else
            {
                converter(dayOfYear);
            }

            return objOld;					// return old obj
        }
};
