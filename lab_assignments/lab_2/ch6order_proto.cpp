// Che Blankenship
#include <iostream>
#include <cmath>
using namespace std;
// Include the OrderInfo class.
#include "order_info.h"


// Prototype

int main() {

    // Declare a variable that has a class OrderInfo().
    OrderInfo orderInformation;
    // Call orderInfo() to input the order information.
    orderInformation.orderInfo();
    // summeries
    orderInformation.orderSummary(orderInformation);

    return 0;
}
