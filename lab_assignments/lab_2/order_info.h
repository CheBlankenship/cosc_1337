// Class that stores order information.
class OrderInfo
{
    public:
        int numOfOrderedSpools;
        int numOfSpoolsInStock;
        double etceteraCharges;

    // Function to output the information.
    void print()
    {
        cout << "Num of spools: " << numOfOrderedSpools << '\n';
        cout << "Num of spools in stock: " << numOfSpoolsInStock << '\n';
        cout << "Etcetera charges: " << etceteraCharges << '\n';
    }

};
