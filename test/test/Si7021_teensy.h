#ifndef __SI7021_H__
#define __SI7021_H__

#include "Arduino.h"
#include <i2c_t3.h>

class SI7021
{
	public:
			SI7021();
			/* Main Functions */
			void begin();
			void begin(uint32_t communicationSpeed);
			float readHumidity();
			float readTemp();
			float readTempPrev();
			float tempCalc(uint16_t sensorValue);
			float rhCalc(uint16_t sensorValue);

			/* Resolution Functions */
			void setHumidityRes(uint8_t res);
			void setTempRes(uint8_t res);
			uint8_t getHumidityRes();
			uint8_t getTempRes();

			/* Heater Functions */
			void setHeater(uint8_t hBit);
			uint8_t getHeater();
			//void setHeaterPower(uint8_t hPow); // broken : register access problem
			//uint8_t getHeaterPower(); // broken : register access problem

			/* Device ID And Reset Functions */
			uint16_t getDeviceID();
			uint8_t getFirmwareVer();
			uint8_t checkVDD();
			void reset(uint8_t delayR = 15);

			/* Conversion Functions */
			uint16_t floatToInt(float FtoI);
			float intToFloat(uint16_t ItoF);
			float CtoF(float tempC);
			float FtoC(float tempF);

		private:
			static const uint16_t GENERATOR_POLYNOM=0x131;
			static const uint8_t NUMBER_OF_ELEMENTS=2;
			static const uint8_t SI7021_ADDR=0x40;
			static const uint32_t DEFAULT_COMMUNICATION_SPEED=400000;
			const float ERROR_CODE=255.0;
			
			bool communicationSuccessFlag=true;
			uint8_t checkSum;
			uint8_t receivedBytes[]={};
			uint8_t crctable[256]={};

			void writeRegister(uint8_t reg, uint8_t value);
			uint8_t readRegister(uint8_t reg);
			uint16_t readSensor(uint8_t reg);
			void calulateTableCRC8(uint8_t *crctable);
			uint8_t computeCRC8(uint8_t *bytes);
};

#endif
