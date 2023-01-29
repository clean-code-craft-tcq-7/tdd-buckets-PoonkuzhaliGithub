#include "charging.h"
#include <stdio.h>

int number_of_readings = 15;
int count_Range1=0;
int count_Range2=0;
int currentReadings_a[] = {3,5,4,10,6,7,8,9,3,5,4,7,10,8,9};
void GetRangeOfReading();
void GetRangeOfReading(int current_a[])
{
  int i=0;
  for(i=0;i<number_of_readings;i++)
  {
    if((current_a[i] >=3) && (current_a[i] <6))
    {
        count_Range1 +=1;     
    }
    else
    {
        count_Range2 +=1;
    }
  }
  printf("\ncount_Range1=%d",count_Range1);
  printf("\ncount_Range2=%d",count_Range2);
}

int main()
{
    GetRangeOfReading(currentReadings_a);
    return 0;
}
/*EOL*/
