/*
 * mpu6500.c
 *
 *  Created on: 28.10.2019
 *      Author: Konto_U¿ytkowe
 */

#include "stm32f4xx_hal.h"
#include "i2c.h"

#include "mpu6500.h"
#include "math.h"

#define I2C_TIMEOUT 10

I2C_HandleTypeDef *i2c;
float Acc_Scale;
float Gyr_Scale;

//
//	Initialization
//
void MPU6500_Init(I2C_HandleTypeDef *hi2c)
{
	i2c = hi2c;
	MPU6500_DeviceReset(1);
    MPU6500_SetSleepEnabled(0);
    MPU6500_SetClockSource(MPU6500_CLOCK_INTERNAL);
    MPU6500_SetDlpf(MPU6500_DLPF_BW_20);
    MPU6500_SetFullScaleGyroRange(MPU6500_GYRO_FS_250);
    MPU6500_SetFullScaleAccelRange(MPU6500_ACCEL_FS_2);

}

//
// CONFIG - on board digital low pass filter (=DLPF)
//
void MPU6500_SetDlpf(uint8_t Value)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_CONFIG, 1, &tmp, 1, I2C_TIMEOUT);
	tmp &= 0xF8;
	tmp |= (Value & 0x7);
	HAL_I2C_Mem_Write(i2c, MPU6500_ADDRESS, MPU6500_RA_CONFIG, 1, &tmp, 1, I2C_TIMEOUT);
}


//
// PWR_MGMT_1
//
void MPU6500_DeviceReset(uint8_t Reset)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_1, 1, &tmp, 1, I2C_TIMEOUT);
	tmp &= ~(1<<MPU6500_PWR1_DEVICE_RESET_BIT);
	tmp |= ((Reset & 0x1) << MPU6500_PWR1_DEVICE_RESET_BIT);
	HAL_I2C_Mem_Write(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_1, 1, &tmp, 1, I2C_TIMEOUT);
}

void MPU6500_SetSleepEnabled(uint8_t Enable)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_1, 1, &tmp, 1, I2C_TIMEOUT);
	tmp &= ~(1<<MPU6500_PWR1_SLEEP_BIT);
	tmp |= ((Enable & 0x1) << MPU6500_PWR1_SLEEP_BIT);
	HAL_I2C_Mem_Write(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_1, 1, &tmp, 1, I2C_TIMEOUT);
}

void MPU6500_SetCycleEnabled(uint8_t Enable)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_1, 1, &tmp, 1, I2C_TIMEOUT);
	tmp &= ~(1<<MPU6500_PWR1_CYCLE_BIT);
	tmp |= ((Enable & 0x1) << MPU6500_PWR1_CYCLE_BIT);
	HAL_I2C_Mem_Write(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_1, 1, &tmp, 1, I2C_TIMEOUT);
}

void MPU6500_SetTemperatureSensorDisbled(uint8_t Disable)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_1, 1, &tmp, 1, I2C_TIMEOUT);
	tmp &= ~(1<<MPU6500_PWR1_TEMP_DIS_BIT);
	tmp |= ((Disable & 0x1) << MPU6500_PWR1_TEMP_DIS_BIT);
	HAL_I2C_Mem_Write(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_1, 1, &tmp, 1, I2C_TIMEOUT);
}

void MPU6500_SetClockSource(uint8_t Source)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_1, 1, &tmp, 1, I2C_TIMEOUT);
	tmp &= 0xF8;
	tmp |= (Source & 0x7);
	HAL_I2C_Mem_Write(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_1, 1, &tmp, 1, I2C_TIMEOUT);
}

//
//	PWR_MGMT_2
//
void MPU6500_SetLowPowerWakeUpFrequency(uint8_t Frequency)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_2, 1, &tmp, 1, I2C_TIMEOUT);
	tmp &= 0x3F;
	tmp |= (Frequency & 0x3) << MPU6500_PWR2_LP_WAKE_CTRL_BIT;
	HAL_I2C_Mem_Write(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_2, 1, &tmp, 1, I2C_TIMEOUT);
}

void MPU6500_AccelerometerAxisStandby(uint8_t XA_Stby, uint8_t YA_Stby, uint8_t ZA_Stby)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_2, 1, &tmp, 1, I2C_TIMEOUT);
	tmp &= 0xC7;
	tmp |= ((XA_Stby&0x1) << MPU6500_PWR2_STBY_XA_BIT)|((YA_Stby&0x1) << MPU6500_PWR2_STBY_YA_BIT)|((ZA_Stby&0x1) << MPU6500_PWR2_STBY_ZA_BIT) ;
	HAL_I2C_Mem_Write(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_2, 1, &tmp, 1, I2C_TIMEOUT);
}

void MPU6500_GyroscopeAxisStandby(uint8_t XG_Stby, uint8_t YG_Stby, uint8_t ZG_Stby)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_2, 1, &tmp, 1, I2C_TIMEOUT);
	tmp &= 0xF8;
	tmp |= ((XG_Stby&0x1) << MPU6500_PWR2_STBY_XG_BIT)|((YG_Stby&0x1) << MPU6500_PWR2_STBY_YG_BIT)|((ZG_Stby&0x1) << MPU6500_PWR2_STBY_ZG_BIT) ;
	HAL_I2C_Mem_Write(i2c, MPU6500_ADDRESS, MPU6500_RA_PWR_MGMT_2, 1, &tmp, 1, I2C_TIMEOUT);
}

//
//	Measurement scale configuration
//
void MPU6500_SetFullScaleGyroRange(uint8_t Range)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_GYRO_CONFIG, 1, &tmp, 1, I2C_TIMEOUT);
	tmp &= 0xE7;
	tmp |= ((Range & 0x7) << 3);
	HAL_I2C_Mem_Write(i2c, MPU6500_ADDRESS, MPU6500_RA_GYRO_CONFIG, 1, &tmp, 1, I2C_TIMEOUT);

	switch(Range)
	{
		case MPU6500_GYRO_FS_250:
			Gyr_Scale = 0.007633;
			break;
		case MPU6500_GYRO_FS_500:
			Gyr_Scale = 0.015267;
			break;
		case MPU6500_GYRO_FS_1000:
			Gyr_Scale = 0.030487;
			break;
		case MPU6500_GYRO_FS_2000:
			Gyr_Scale = 0.060975;
			break;
		default:
			break;
	}
}

void MPU6500_SetFullScaleAccelRange(uint8_t Range)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_ACCEL_CONFIG, 1, &tmp, 1, I2C_TIMEOUT);
	tmp &= 0xE7;
	tmp |= ((Range & 0x7) << 3);
	HAL_I2C_Mem_Write(i2c, MPU6500_ADDRESS, MPU6500_RA_ACCEL_CONFIG, 1, &tmp, 1, I2C_TIMEOUT);

	switch(Range)
	{
		case MPU6500_ACCEL_FS_2:
			Acc_Scale = 0.000061;
			break;
		case MPU6500_ACCEL_FS_4:
			Acc_Scale = 0.000122;
			break;
		case MPU6500_ACCEL_FS_8:
			Acc_Scale = 0.000244;
			break;
		case MPU6500_ACCEL_FS_16:
			Acc_Scale = 0.0004882;
			break;
		default:
			break;
	}
}

//
// Reading data
//
int16_t MPU6500_GetTemperatureRAW(void)
{
	uint8_t tmp[2];
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_TEMP_OUT_H, 1, tmp, 2, I2C_TIMEOUT);
	return (((int16_t)tmp[0]) << 8) | tmp[1];
}

float MPU6500_GetTemperatureCelsius(void)
{
	int16_t temp;

	temp = MPU6500_GetTemperatureRAW();

	return (float)temp / 340 + 36.53;
}

int16_t MPU6500_GetAccelerationXRAW(void)
{
	uint8_t tmp[2];
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_ACCEL_XOUT_H, 1, tmp, 2, I2C_TIMEOUT);
	return (((int16_t)tmp[0]) << 8) | tmp[1];
}

int16_t MPU6500_GetAccelerationYRAW(void)
{
	uint8_t tmp[2];
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_ACCEL_YOUT_H, 1, tmp, 2, I2C_TIMEOUT);
	return (((int16_t)tmp[0]) << 8) | tmp[1];
}

int16_t MPU6500_GetAccelerationZRAW(void)
{
	uint8_t tmp[2];
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_ACCEL_ZOUT_H, 1, tmp, 2, I2C_TIMEOUT);
	return (((int16_t)tmp[0]) << 8) | tmp[1];
}

void MPU6500_GetAccelerometerRAW(int16_t *x, int16_t *y, int16_t *z)
{
	uint8_t tmp[6];
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_ACCEL_XOUT_H, 1, tmp, 6, I2C_TIMEOUT);

	*x = (((int16_t)tmp[0]) << 8) | tmp[1];
	*y = (((int16_t)tmp[2]) << 8) | tmp[3];
	*z = (((int16_t)tmp[4]) << 8) | tmp[5];
}

void MPU6500_GetAccelerometerScaled(float* x, float* y, float* z)
{
	int16_t tmp_x, tmp_y, tmp_z;
	MPU6500_GetAccelerometerRAW(&tmp_x, &tmp_y, &tmp_z);

	*x = (float)tmp_x * Acc_Scale;
	*y = (float)tmp_y * Acc_Scale;
	*z = (float)tmp_z * Acc_Scale;
}

int16_t MPU6500_GetRotationXRAW(void)
{
	uint8_t tmp[2];
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_GYRO_XOUT_H, 1, tmp, 2, I2C_TIMEOUT);
	return (((int16_t)tmp[0]) << 8) | tmp[1];
}

int16_t MPU6500_GetRotationYRAW(void)
{
	uint8_t tmp[2];
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_GYRO_YOUT_H, 1, tmp, 2, I2C_TIMEOUT);
	return (((int16_t)tmp[0]) << 8) | tmp[1];
}

int16_t MPU6500_GetRotationZRAW(void)
{
	uint8_t tmp[2];
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_GYRO_ZOUT_H, 1, tmp, 2, I2C_TIMEOUT);
	return (((int16_t)tmp[0]) << 8) | tmp[1];
}

void MPU6500_GetGyroscopeRAW(int16_t *x, int16_t *y, int16_t *z)
{
	uint8_t tmp[6];
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_GYRO_XOUT_H, 1, tmp, 6, I2C_TIMEOUT);

	*x = (((int16_t)tmp[0]) << 8) | tmp[1];
	*y = (((int16_t)tmp[2]) << 8) | tmp[3];
	*z = (((int16_t)tmp[4]) << 8) | tmp[5];
}

void MPU6500_GetGyroscopeScaled(float* x, float* y, float* z)
{
	int16_t tmp_x, tmp_y, tmp_z;

	MPU6500_GetGyroscopeRAW(&tmp_x, &tmp_y, &tmp_z);

	*x = (float)tmp_x * Gyr_Scale;
	*y = (float)tmp_y * Gyr_Scale;
	*z = (float)tmp_z * Gyr_Scale;
}

void MPU6500_GetRollPitch(float* Roll, float* Pitch)
{
	float acc_x, acc_y, acc_z;
	MPU6500_GetAccelerometerScaled(&acc_x, &acc_y, &acc_z);

	*Roll = atan2(acc_y, acc_z) * 180.0 / M_PI;
	*Pitch = -(atan2(acc_x, sqrt(acc_y*acc_y + acc_z*acc_z))*180.0)/M_PI;
}

uint8_t MPU6500_GetDeviceID(void)
{
	uint8_t tmp;
	HAL_I2C_Mem_Read(i2c, MPU6500_ADDRESS, MPU6500_RA_WHO_AM_I, 1, &tmp, 1, I2C_TIMEOUT);
	return tmp<<1;
}













