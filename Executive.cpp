#include <iostream>
#include "Executive.h"
using namespace std;

Executive::Executive()
{
}

Executive::Executive(string n, double s, string d) :
Manager(n, s, d)
{
}

void Executive::print() const
{
    cout << "Executive ";
    Manager::print();
}
