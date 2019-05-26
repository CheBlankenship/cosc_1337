// David Garcia
#include <iostream>
#include <cmath>
using namespace std;

// prototype
void orderInfo(int&, int&, double&);
void orderSummary(int, int, double);

int main()
{
  // # of spools ordered
  int numOfOrderedSpools;
  // # of spools in stock
  int numOfSpoolsInStock;
  // any special shipping & handling charges above $10 rate
  double numShippingAndHandling;

  return 0;
}

void orderInfo(int &numOfOrderedSpools, int &numOfSpoolsInStock, double &numShippingAndHandling) {
  numOfOrderedSpools = 0;
  numOfSpoolsInStock = 0;
  numShippingAndHandling = 0;

  // numOfOrderedSpools
  std::cout << "Enter the number of orders ";
  std::cin >> numOfOrderedSpools;
  while (numOfOrderedSpools<1)
  {
      std::cin.ignore(100, '\n');
      std::cin.clear();
      std::cout << "Order needs to be larger than 1." << '\n';
      std::cout << "Enter the number of orders ";
      std::cin >> numOfOrderedSpools;
  }
  // numOfSpoolsInStock
  std::cout << "Enter the number in stock ";
  std::cin >> numOfSpoolsInStock;
  while (numOfSpoolsInStock<0)
  {
      std::cin.ignore(100, '\n');
      std::cin.clear();
      std::cout << "Stock orders need to be larger than 0." << '\n';
      std::cout << "Enter the number in stock ";
      std::cin >> numOfSpoolsInStock;
  }
  // numShippingAndHandling
  std::cout << "Extra Charges (Shipping and Handling Fee) ";
  std::cin >> numShippingAndHandling;
  while (numShippingAndHandling<0)
  {
      std::cin.ignore(100, '\n');
      std::cin.clear();
      std::cout << "Extra Charges Fee need to be larger than 0." << '\n';
      std::cout << "Extra Charges (Shipping and Handling Fee)  ";
      std::cin >> numShippingAndHandling;
  }
}

void orderSummary(int numOfOrderedSpools, int numOfSpoolsInStock, double numShippingAndHandling)
{

  int spoolsReadyToShip = 0;
  int numOfSpoolsOnBackOrder = 0;
  double salesPriceReadyToShip = 0;
  double extraFee = 0;
  double totalOrderReadyToShip = 0;

  if (numOfOrderedSpools <= numOfSpoolsInStock)
  {
    spoolsReadyToShip = numOfOrderedSpools;
    numOfSpoolsOnBackOrder = 0;
    salesPriceReadyToShip = spoolsReadyToShip * 100;
    extraFee = (spoolsReadyToShip * 10) + numShippingAndHandling;
    totalOrderReadyToShip = salesPriceReadyToShip + extraFee;
  }
  else if (numOfOrderedSpools > numOfSpoolsInStock)
  {
    // # of spools ready to ship from current stock.
      spoolsReadyToShip = numOfSpoolsInStock;
      // # of ordered spools on backorder (if ordered > in stock).
      numOfSpoolsOnBackOrder = numOfOrderedSpools - numOfSpoolsInStock;
      // Total sales price of portion ready to ship (# of spools ready to ship X $100).
      salesPriceReadyToShip = (spoolsReadyToShip * 100);
      // shipping fee
      extraFee = (spoolsReadyToShip * 10) + (numShippingAndHandling);
      // sum of slaes fee and shipping fee.
      totalOrderReadyToShip = salesPriceReadyToShip + extraFee;
  }

    else
    {
        cout << "Error found in orderSummary func: Unexpected statement." << '\n';
    }


    // Print out the summary.
    std::cout << '\n';
    std::cout << "+----------------------------- Order Summary -----------------------------+" << '\n';
    cout << "Spools ready to ship from current stock            : " << spoolsReadyToShip << '\n';
    cout << "Spools which are in backorder                      : " << numOfSpoolsOnBackOrder << '\n';
    cout << "Total sales price of portion ready to ship         : $" << salesPriceReadyToShip << '\n';
    cout << "Total extra charges on the portion ready to ship   : $" << extraFee << '\n';
    cout << "Total order price" << '\n';
};
