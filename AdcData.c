#include <math.h>
#include "Sensor.h"
#include "RangeFinder.h"

int convertedAmpereValue = 0xFFFF;
int rangeof_convertedAmpValue[NO_OF_CONVERETD_AMP_VALUE] = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF};
static int noOfconverted_AmpereValue = 0;

const mcalConfig* received_ADC_SensorConfig;

void update_sensorConfigObj(int adc_channelID)
{
	received_ADC_SensorConfig = get_sensorConfig(adc_channelID);
}

int ADC_data_AssertCheck(int adcData)
{
	if(adcData > 0 && adcData <= received_ADC_SensorConfig->ADC_Resolution)
	{
		return IN_RANGE;
	}
	else
	{
		return OUTOFF_RANGE;
	}
}

int convert_ADCCount_into_Amps(int adcData)
{
 	return round((received_ADC_SensorConfig->sensor_AmpereRange * adcData) / (received_ADC_SensorConfig->ADC_Resolution));
}

void ProcessSensor_ADC_data(int adcData, int adc_channelID)
{
	int adcData_ErrorStatus;
	
	update_sensorConfigObj(adc_channelID);
	adcData_ErrorStatus = ADC_data_AssertCheck(adcData);
	if(adcData_ErrorStatus == IN_RANGE)
	{
		convertedAmpereValue = convert_ADCCount_into_Amps(adcData);
		accumulate_ConvertedAmpValue(convertedAmpereValue);
	}
	else
	{
		convertedAmpereValue = 0xFFFF;
	}
}

void accumulate_ConvertedAmpValue(int convertedValue)
{
	if(convertedValue != 0xFFFF && noOfconverted_AmpereValue < NO_OF_CONVERETD_AMP_VALUE)
	{
		rangeof_convertedAmpValue[noOfconverted_AmpereValue] = convertedValue;
		++noOfconverted_AmpereValue;
		
		if(noOfconverted_AmpereValue == 6)
		{
			find_convertedAmpere_RangeList(rangeof_convertedAmpValue, noOfconverted_AmpereValue);
			noOfconverted_AmpereValue = 0;
		}
	}
}

void find_convertedAmpere_RangeList(int *convertedData, int no_of_convertedValues)
{
	find_currentRangeList(convertedData, no_of_convertedValues);	
}
