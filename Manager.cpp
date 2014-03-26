#include <iostream>
#include "Executive.h"
using namespace std;

int main()
{
    Executive m = Executive("Bigwig, Bill", 136000.0, "Sales");
    m.print();
    return 0;
}
