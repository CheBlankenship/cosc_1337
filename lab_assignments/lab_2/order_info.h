// Class that stores order information.
class OrderInfo
{
    public:
        int numOfSpools;
        int numOfSpoolsInStock;
        double etceteraCharges;

    // Function to output the information.
    void print()
    {
        cout << "Num of spools: " << numOfSpools << '\n';
        cout << "Num of spools in stock: " << numOfSpoolsInStock << '\n';
        cout << "Etcetera charges: " << etceteraCharges << '\n';
    }

};
