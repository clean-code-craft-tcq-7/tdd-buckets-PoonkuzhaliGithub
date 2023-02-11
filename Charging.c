#include <stdio.h>
#include "Charging.h"

int i =0;

int CalculateRange1(int* currentRed_a[],int number_of_readings)
{
  for(i=0;i<number_of_readings;i++)
  {
      if((currentRed_a[i] >=3) && (currentRed_a[i] <6))
      {
         count_Range1 +=1;
      }
  }
  return count_Range1;
}
/*
int CalculateRange2(int* currentRed_a[], int number_of_readings)
{
  for(i=0;i<number_of_readings;i++)
  {
    CountRange_Two(currentRed_a);
  }
  return count_Range2;
}

int CountRange_Two(int* current_a[])
{
  if((current_a[i]<=6) && (current_a[i] <=10))
  {
    count_Range2 +=1;
  }
  return count_Range1;
}
*/
int main()
{
    CalculateRange1(currentReadings_a,num_of_readings);
    //CalculateRange2(currentReadings_a,num_of_readings);
    printf("Range,\treadings");
    printf("\n3-5,\t%d",count_Range1);
    //printf("\n6-10,\t%d",count_Range2);
    return 0;
}
