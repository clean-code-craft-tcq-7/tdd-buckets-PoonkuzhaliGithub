#include <stdio.h>
#include "currentRangeFinder.h"

current_rangeFinder_s current_rangeList[100];

void sortGivenIndexPosition(int *Range, int noOfElements, int received_position) {
	int temp;
	
	for(int index = received_position+1 ; index < noOfElements; index++) {
	if(Range[received_position] > Range[index]) {
	temp = Range[received_position];
     	Range[received_position] = Range[index];
     	Range[index] = temp;
   	}
 	}
}

void sort_currentRangeList(int *get_currentRanges, int no_Of_availableReadings) {
  	for(int index = 0; index < no_Of_availableReadings; index++) {
    	sortGivenIndexPosition(get_currentRanges, no_Of_availableReadings, index); 
  	}
}

int get_noofRanges(int *getsortRange, int no_Of_Elements)
{
	int no_ofRanges = 1;
	
	for(int index = 0; index < no_Of_Elements-1; index++)
	{
		if((getsortRange[index] != getsortRange[index+1]) && (getsortRange[index]+1 != getsortRange[index+1]))
		{
			++no_ofRanges;	
		}
	}
	return no_ofRanges;
}

void get_currentRangesandCounter(int *getsorted_currentRange, int no_Of_Elements)
{
	int no_of_currentRanges = 0;
	
	current_rangeList[no_of_currentRanges].startRange = getsorted_currentRange[0]; 
	
	for(int index = 0; index < no_Of_Elements-1; index++) {
		if((getsorted_currentRange[index] == getsorted_currentRange[index+1]) || (getsorted_currentRange[index]+1 == getsorted_currentRange[index+1]))
		{
			current_rangeList[no_of_currentRanges].endRange = getsorted_currentRange[index+1];
			++current_rangeList[no_of_currentRanges].rangeCounter; 
		}
		else
		{	
			++no_of_currentRanges;
			current_rangeList[no_of_currentRanges].startRange = getsorted_currentRange[index+1];
		}
	}
	
}

void update_RangefinderStruct_Defaultvalue(int no_of_currentRanges)
{
    for(int index = 0; index < no_of_currentRanges; index++)
    {
        current_rangeList[index].startRange = 0;
        current_rangeList[index].endRange = 0;
        current_rangeList[index].rangeCounter = 1;
    }
}

int find_currentRangeList(int *received_currentRanges, int no_Of_Elements)
{
	sort_currentRangeList(received_currentRanges, no_Of_Elements);
	
	int noOf_currentRanges = get_noofRanges(received_currentRanges, no_Of_Elements);
	update_RangefinderStruct_Defaultvalue(noOf_currentRanges);
	
	get_currentRangesandCounter(received_currentRanges, no_Of_Elements);
	return noOf_currentRanges;
}
