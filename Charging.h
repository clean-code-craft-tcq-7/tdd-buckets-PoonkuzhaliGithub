#include <stdio.h>
  
typedef struct 
{
	int startRange;
	int endRange;
	int rangeCounter;
} current_rangeFinder_s;

extern current_rangeFinder_s current_rangeList[];

void sortGivenIndexPosition(int *Range, int noOfElements, int received_position);
void sort_currentRangeList(int *get_currentRanges, int no_Of_availableReadings);
int get_noofRanges(int *getsortRange, int no_Of_Elements);
void get_currentRangesandCounter(int *getsorted_currentRange, int no_Of_Elements);
int find_currentRangeList(int *received_currentRanges, int no_Of_Elements);
void update_RangefinderStruct_Defaultvalue(int no_of_currentRanges);
