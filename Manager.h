#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee
{
public:
    Manager();
    Manager(string n, double s, string d);
    string get_department() const;
    virtual void print() const;
private:
    string department;
};

#endif
