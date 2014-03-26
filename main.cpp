#include "List.h"

int main()
{
    List staff;
    staff.push_back("Garcia, David");
    staff.push_back("Smith, John");
    staff.push_back("Kestler, Amber");
    staff.push_back("Wesley, Walter");
    
    // Add a value in fourth place
    
    List::Iterator pos;
    pos = staff.begin();
    pos.next();
    pos.next();
    pos.next();
    
    staff.insert(pos, "Reindeer, Rudolf");
    
    // Remove the value in second place
    
    pos = staff.begin();
    pos.next();
    
    staff.erase(pos);
    
    // Print all values 
    
    for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
        cout << pos.get() << "\n";
    
    return 0;
}
