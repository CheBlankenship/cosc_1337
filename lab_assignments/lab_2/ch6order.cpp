// Che Blankenship
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
// Include the class that holds the order data.
#include "order_info.h"


int main() {

    
    OrderInfo order_one;
    order_one.numOfSpools = 1;
    order_one.numOfSpoolsInStock = 23;
    order_one.etceteraCharges = 15;

    order_one.print();

    return 0;
}
