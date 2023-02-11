#include <stdio.h>
#include "assert.h"
#include "Charging.h"

void TestCase1();

void TestCase1()
{
    int currentRange[6] = {1,2,3,4,5,5};
    
    int length = sizeof(currentRange[6])/sizeof(currentRange[0]);
    
    assert(CalculateRange1(currentRange, length) == 2);
}

int main()
{
   TestCase1();

    return 0;
}
