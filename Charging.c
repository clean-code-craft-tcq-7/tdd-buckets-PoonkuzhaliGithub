#include "charging.h"
#include <stdio.h>
#include <stdio.h>

int number_of_readings = 15;
int count_Range1=0;
int count_Range2=0;
int currentReadings_a[] = {3,5,4,10,6,7,8,9,3,5,4,7,10,8,9};
void GetRangeOfReading();
int CalculateRange1();
int CalculateRange2();
int CalculateRange1(int current_a[])
{
  int i=0;
  for(i=0;i<number_of_readings;i++)
  {
    if((current_a[i] >=3) && (current_a[i] <6))
    {
        count_Range1 +=1;
    }
  }
  return count_Range1;
}
int CalculateRange2(int current_a[])
{
  int i=0;
  for(i=0;i<number_of_readings;i++)
  {
    if((current_a[i]<=6) && (current_a[i] <=10))
    {
        count_Range2 +=1;
    }
  }
  return count_Range2;
}
int main()
{
    CalculateRange1(currentReadings_a);
    CalculateRange2(currentReadings_a);
    printf("\ncount_Range1=%d",count_Range1);
    printf("\ncount_Range2=%d",count_Range2);
    return 0;
}
