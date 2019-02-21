// Che Blankenship
#include <iostream>
using namespace std;

void orderInfo(int&, int&, double&);
void orderSummary(int, int, double);

int main()
{
    // Declare the variables to save order info.
    int numOfOrderedSpools;
    int numOfSpoolsInStock;
    double etceteraCharges;

    // Get order information.
    orderInfo(numOfOrderedSpools, numOfSpoolsInStock, etceteraCharges);
    // Summeries the order info and print it out.
    orderSummary(numOfOrderedSpools, numOfSpoolsInStock, etceteraCharges);

    return 0;
}


/// Asks for three information about the order and saves them in reference param.
void orderInfo(int &numOfOrderedSpools, int &numOfSpoolsInStock, double &etceteraCharges)
{

    numOfOrderedSpools  = 0;
    numOfSpoolsInStock  = 0;
    etceteraCharges     = 0;

    // # of spools ordered,
    while (!(std::cout << "Enter the number of spools that got order: " && cin >> numOfOrderedSpools) || !(numOfOrderedSpools > 1))
    {
        std::cin.clear();//clear bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input.\nPlease re-enter(only positive numbers > 1).\n\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    // # of spools in stock,
    while (!(std::cout << "Enter the number of spools in stock: " && cin >> numOfSpoolsInStock) || !(numOfSpoolsInStock >= 0))
    {
        std::cin.clear();//clear bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input.\nPlease re-enter(only positive numbers).\n\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // any special shipping & handling charges above $10 rate.
    while (!(std::cout << "Enter the number of etcetera charges: $" && cin >> etceteraCharges) || !(etceteraCharges >= 0))
    {
        std::cin.clear();//clear bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input.\nPlease re-enter(only positive numbers).\n\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/// Takes the OrderInfo object as a reference variable and summeries the order info.
void orderSummary(int numOfOrderedSpools, int numOfSpoolsInStock, double etceteraCharges=10)
{

    int spoolsReadyToShip       = 0;
    int numOfSpoolsInBackorder  = 0;
    double salesPriceReadyToShip= 0;
    double extraFee             = 0; // shipping and handling fee.
    //if (etceteraCharges == 0) {etceteraCharges = 10; }
    double totalOrderPrice      = 0;

    if (numOfOrderedSpools <= numOfSpoolsInStock)
    {
        // # of spools ready to ship from current stock.
        spoolsReadyToShip = numOfOrderedSpools;
        // # of ordered spools in backorder.
        numOfSpoolsInBackorder = 0;
        // Total sales price of portion ready to ship (# of spools ready to ship X $100).
        salesPriceReadyToShip = spoolsReadyToShip * 100;
        // shipping fee + handleing fee etc..
        extraFee = (spoolsReadyToShip * 10) + (etceteraCharges);
        // sum of sales price and extra fee
        totalOrderPrice = salesPriceReadyToShip + extraFee;
    }
    // if ordered num > in stock num.
    else if (numOfOrderedSpools > numOfSpoolsInStock)
    {
        // # of spools ready to ship from current stock.
        spoolsReadyToShip = numOfSpoolsInStock;
        // # of ordered spools on backorder (if ordered > in stock).
        numOfSpoolsInBackorder = numOfOrderedSpools - numOfSpoolsInStock;
        // Total sales price of portion ready to ship (# of spools ready to ship X $100).
        salesPriceReadyToShip = (spoolsReadyToShip * 100);
        // shipping fee
        extraFee = (spoolsReadyToShip * 10) + (etceteraCharges);
        // sum of slaes fee and shipping fee.
        totalOrderPrice = salesPriceReadyToShip + extraFee;
    }
    else
    {
        cout << "Error found in orderSummary func: Unexpected statement." << '\n';
    }


    // Print out the summary.
    std::cout << '\n';
    std::cout << "+----------------------------- Order Summary -----------------------------+" << '\n';
    cout << "Spools ready to ship from current stock            : " << spoolsReadyToShip << '\n';
    cout << "Spools which are in backorder                      : " << numOfSpoolsInBackorder << '\n';
    cout << "Total sales price of portion ready to ship         : $" << salesPriceReadyToShip << '\n';
    cout << "Total extra charges on the portion ready to ship   : $" << extraFee << '\n';
    cout << "Total order price                                  : $" << totalOrderPrice << "\n\n";

}
