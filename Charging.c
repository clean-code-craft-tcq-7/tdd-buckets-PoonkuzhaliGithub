#include "charging.h"
#include <stdio.h>

int CalculateRange1(int currentRed_a[])
{
  for(i=0;i<number_of_readings;i++)
  {
    CountRange_One(currentRed_a);
  }
  return count_Range1;
}
int CalculateRange2(int currentRed_a[])
{
  for(i=0;i<number_of_readings;i++)
  {
    CountRange_Two(currentRed_a);
  }
  return count_Range2;
}
int CountRange_One(int current_a[])
{
  
  if((current_a[i] >=3) && (current_a[i] <6))
  {
    count_Range1 +=1;
  }
  return count_Range1;
}
int CountRange_Two(int current_a[])
{
  if((current_a[i]<=6) && (current_a[i] <=10))
  {
    count_Range2 +=1;
  }
  return count_Range1;
}
int main()
{
    CalculateRange1(currentReadings_a);
    CalculateRange2(currentReadings_a);
    printf("\ncount_Range1=%d",count_Range1);
    printf("\ncount_Range2=%d",count_Range2);
    return 0;
}
