#include<stdio.h>

#define IN_RANGE 1
#define OUTOFF_RANGE 0

#define NO_OF_CONVERETD_AMP_VALUE	6

extern int convertedAmpereValue;
extern int rangeof_convertedAmpValue[NO_OF_CONVERETD_AMP_VALUE];

typedef struct
{
	int ADC_Resolution;
	int sensor_AmpereRange;
}mcalConfig;

void update_sensorConfigObj(int adc_channelID);
const mcalConfig* get_sensorConfig(int adc_channelID);
int ADC_data_AssertCheck(int adcData);
int convert_ADCCount_into_Amps(int adcData);
void ProcessSensor_ADC_data(int adcData, int adc_channelID);
void accumulate_ConvertedAmpValue(int convertedValue);
void find_convertedAmpere_RangeList(int *convertedData, int no_of_convertedValues);
