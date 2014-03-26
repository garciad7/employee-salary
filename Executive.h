#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Manager.h"

class Executive : public Manager
{
public:
    Executive();
    Executive(string n, double s, string d);
    virtual void print() const;
};

#endif
