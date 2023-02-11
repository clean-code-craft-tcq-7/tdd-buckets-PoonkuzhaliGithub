#include <stdio.h>
#include "assert.h"
#include "Charging.h"

void TestCase1();

void TestCase1(int len)
{
    int currentRange[6] = {1,2,3,4,5,5};
    
    int length = sizeof(currentRange[6])/sizeof(currentRange[0]);
    
    assert(length == len);
}

int main()
{
   TestCase1(3);

    return 0;
}
