




#if defined(_AVR_)
#include <util/delay.h>
#endif

#include "BlueDot_BMA400.h"
#include "Wire.h"


BlueDot_BMA400::BlueDot_BMA400()
{
	
	parameter.I2CAddress;
	parameter.powerMode;
	parameter.measurementRange;
	

}



uint8_t BlueDot_BMA400::init(void)
{
	Wire.begin();
	setPowerMode();
	setMeasurementRange();
	setOutputDataRate();
	setOversamplingRate();
	
	
	
	return checkID();

}
//##########################################################################
//SET UP FUNCTIONS
//##########################################################################
uint8_t BlueDot_BMA400::checkID(void)
{
	uint8_t chipID;
	chipID = readByte(BMA400_CHIP_ID);
	return chipID;		
	
}
//##########################################################################
void BlueDot_BMA400::setPowerMode(void)
{
	uint8_t reg;
	reg = readByte(BMA400_ACC_CONFIG0);
	reg = reg & 0b11111100;
	
	reg = reg | parameter.powerMode;
	writeByte(BMA400_ACC_CONFIG0, reg);	
	
}
//##########################################################################
void BlueDot_BMA400::setMeasurementRange(void)
{
	uint8_t reg;
	reg = readByte(BMA400_ACC_CONFIG1);
	reg = reg & 0b00111111;
	
	reg = reg | (parameter.measurementRange << 6);
	writeByte(BMA400_ACC_CONFIG1, reg);	
	
}
//##########################################################################
void BlueDot_BMA400::setOutputDataRate(void)
{
	uint8_t reg;
	reg = readByte(BMA400_ACC_CONFIG1);
	reg = reg & 0b11110000;
	
	reg = reg | parameter.outputDataRate;
	writeByte(BMA400_ACC_CONFIG1, reg);	
	
}
//##########################################################################
void BlueDot_BMA400::setOversamplingRate(void)
{
	uint8_t reg;
	reg = readByte(BMA400_ACC_CONFIG1);
	reg = reg & 0b11001111;
	
	reg = reg | (parameter.oversamplingRate << 4);
	writeByte(BMA400_ACC_CONFIG1, reg);	
	
}
//##########################################################################
uint8_t BlueDot_BMA400::readPowerMode(void)
{
	uint8_t value;
	value = readByte(BMA400_STATUS);
	value = value & 0b00000110;
	value = value >> 1;
	
	return value;		
	
}
//##########################################################################
uint8_t BlueDot_BMA400::readMeasurementRange(void)
{
	uint8_t value;
	value = readByte(BMA400_ACC_CONFIG1);
	value = value & 0b11000000;
	value = value >> 6;
	
	return value;		
	
}
//##########################################################################
uint8_t BlueDot_BMA400::readOutputDataRate(void)
{
	uint8_t value;
	value = readByte(BMA400_ACC_CONFIG1);
	value = value & 0b00001111;	
	
	return value;	
	
}
//##########################################################################
uint8_t BlueDot_BMA400::readOversamplingRate(void)
{
	uint8_t value;
	value = readByte(BMA400_ACC_CONFIG1);
	value = value & 0b00110000;
	value = value >> 4;
	
	return value;	
	
}
//##########################################################################
//DATA READ FUNCTIONS
//##########################################################################
void BlueDot_BMA400::readData(void)
{
	uint8_t rawData[6];
	Wire.beginTransmission(parameter.I2CAddress);
	Wire.write(BMA400_ACC_X_LSB);
	Wire.endTransmission();
	Wire.requestFrom(parameter.I2CAddress, 6);
	
	uint8_t acc_x_lsb = Wire.read();
	uint8_t acc_x_msb = Wire.read();
	uint8_t acc_y_lsb = Wire.read();
	uint8_t acc_y_msb = Wire.read();
	uint8_t acc_z_lsb = Wire.read();
	uint8_t acc_z_msb = Wire.read();
	

	parameter.raw_acc_x = acc_x_lsb + (256)*acc_x_msb;
	if (parameter.raw_acc_x > 2047)
	parameter.raw_acc_x = parameter.raw_acc_x - 4096;
	
	parameter.raw_acc_y = acc_y_lsb + (256)*acc_y_msb;
	if (parameter.raw_acc_y > 2047)
	parameter.raw_acc_y = parameter.raw_acc_y - 4096;
	
	parameter.raw_acc_z = acc_z_lsb | (256)*acc_z_msb;
	if (parameter.raw_acc_z > 2047)
	parameter.raw_acc_z = parameter.raw_acc_z - 4096;
	
	convertData();
	
}
//##########################################################################
//DATA READ FUNCTIONS
//##########################################################################
void BlueDot_BMA400::convertData(void)
{
	float range;
	if (parameter.measurementRange == 0)
	range = 2000;
	
	if (parameter.measurementRange == 1)
	range = 4000;
	
	if (parameter.measurementRange == 2)
	range = 8000;
	
	if (parameter.measurementRange == 3)
	range = 16000;
	
	parameter.acc_x = parameter.raw_acc_x*range/2048;
	parameter.acc_y = parameter.raw_acc_y*range/2048;
	parameter.acc_z = parameter.raw_acc_z*range/2048;
	
	
}
//##########################################################################
//BASIC FUNCTIONS
//##########################################################################
void BlueDot_BMA400::writeByte(byte reg, byte value)
{
	Wire.beginTransmission(parameter.I2CAddress);
	Wire.write(reg);
	Wire.write(value);
	Wire.endTransmission();	
}
//##########################################################################
uint8_t BlueDot_BMA400::readByte(byte reg)
{
	uint8_t value;
	Wire.beginTransmission(parameter.I2CAddress);
	Wire.write(reg);
	Wire.endTransmission();
	Wire.requestFrom(parameter.I2CAddress,1);		
	value = Wire.read();		
	return value;	
}
