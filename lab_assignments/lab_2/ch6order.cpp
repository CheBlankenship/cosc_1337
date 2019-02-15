// Che Blankenship
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
// Include the class that holds the order data.
#include "order_info.h"

// Delcarations
void orderInfo();

int main() {

    orderInfo();
    return 0;

}


void orderInfo() {

    OrderInfo orderInformation;
    // # of spools ordered,
    while (!(std::cout << "Enter the number of spools that got order: " && cin >> orderInformation.numOfOrderedSpools) || !(orderInformation.numOfOrderedSpools > 0))
    {
        std::cin.clear();//clear bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input.\nPlease re-enter(only positive numbers).\n\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    // # of spools in stock,
    while (!(std::cout << "Enter the number of spools in stock: " && cin >> orderInformation.numOfSpoolsInStock) || !(orderInformation.numOfSpoolsInStock > 0))
    {
        std::cin.clear();//clear bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input.\nPlease re-enter(only positive numbers).\n\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // any special shipping & handling charges above $10 rate.
    while (!(std::cout << "Enter the number of etcetera charges: " && cin >> orderInformation.etceteraCharges) || !(orderInformation.etceteraCharges > 0))
    {
        std::cin.clear();//clear bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid input.\nPlease re-enter(only positive numbers).\n\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Define a variable that has OrderInfo class.
    //OrderInfo orderInformation;
    // Store the user input data.
    //orderInformation.numOfOrderedSpools = numOfOrderedSpools;
    //orderInformation.numOfSpoolsInStock = numOfSpoolsInStock;
    //orderInformation.etceteraCharges = etceteraCharges;

    // Print function helps you see the values.
    orderInformation.print();

}


// void orderSummary() {
//
//     // # of spools ready to ship from current stock.
//     int spoolsReadyToShip;
//     // # of ordered spools on backorder (if ordered > in stock).
//     int numOfSpoolsInBackorder;
//     // Total sales price of portion ready to ship (# of spools ready to ship X $100).
//     double salesPriceReadyToShip;
//     // Total of the order ready to ship.
//     double totalOrderPrice;
//
//
//
//
// }
