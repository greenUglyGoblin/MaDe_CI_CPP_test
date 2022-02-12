#include <iostream>
#include "macros.h"

extern void status();

int main()
{
    std::cout << "MaDe CI test" << std::endl;

    std::cout << "naprawilem problem xd:" << VERSION << std::endl;

    status();
    
    return 0;
}
