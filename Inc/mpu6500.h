/*
 * mpu6500.h
 *
 *  Created on: 28.10.2019
 *      Author: Konto_U¿ytkowe
 */

#ifndef MPU6500_H_
#define MPU6500_H_

#define MPU6500_ADDRESS 0xD0	// AD0 low
//#define MPU6500_ADDRESS 0xD1	// AD0 high

//
//	Registers addresses
//
#define MPU6500_RA_SELF_TEST_X      0x0D
#define MPU6500_RA_SELF_TEST_Y      0x0E
#define MPU6500_RA_SELF_TEST_Z      0x0F
#define MPU6500_RA_SELF_TEST_A      0x10
#define MPU6500_RA_SMPLRT_DIV       0x19
#define MPU6500_RA_CONFIG           0x1A
#define MPU6500_RA_GYRO_CONFIG      0x1B
#define MPU6500_RA_ACCEL_CONFIG     0x1C
// Not in documentation
#define MPU6500_RA_FF_THR           0x1D
#define MPU6500_RA_FF_DUR           0x1E
#define MPU6500_RA_MOT_THR          0x1F
#define MPU6500_RA_MOT_DUR          0x20
#define MPU6500_RA_ZRMOT_THR        0x21
#define MPU6500_RA_ZRMOT_DUR        0x22
// Not in documentation end
#define MPU6500_RA_FIFO_EN          0x23
#define MPU6500_RA_I2C_MST_CTRL     0x24
#define MPU6500_RA_I2C_SLV0_ADDR    0x25
#define MPU6500_RA_I2C_SLV0_REG     0x26
#define MPU6500_RA_I2C_SLV0_CTRL    0x27
#define MPU6500_RA_I2C_SLV1_ADDR    0x28
#define MPU6500_RA_I2C_SLV1_REG     0x29
#define MPU6500_RA_I2C_SLV1_CTRL    0x2A
#define MPU6500_RA_I2C_SLV2_ADDR    0x2B
#define MPU6500_RA_I2C_SLV2_REG     0x2C
#define MPU6500_RA_I2C_SLV2_CTRL    0x2D
#define MPU6500_RA_I2C_SLV3_ADDR    0x2E
#define MPU6500_RA_I2C_SLV3_REG     0x2F
#define MPU6500_RA_I2C_SLV3_CTRL    0x30
#define MPU6500_RA_I2C_SLV4_ADDR    0x31
#define MPU6500_RA_I2C_SLV4_REG     0x32
#define MPU6500_RA_I2C_SLV4_DO      0x33
#define MPU6500_RA_I2C_SLV4_CTRL    0x34
#define MPU6500_RA_I2C_SLV4_DI      0x35
#define MPU6500_RA_I2C_MST_STATUS   0x36
#define MPU6500_RA_INT_PIN_CFG      0x37
#define MPU6500_RA_INT_ENABLE       0x38
// Not in documentation
#define MPU6500_RA_DMP_INT_STATUS   0x39
// Not in documentation end
#define MPU6500_RA_INT_STATUS       0x3A
#define MPU6500_RA_ACCEL_XOUT_H     0x3B
#define MPU6500_RA_ACCEL_XOUT_L     0x3C
#define MPU6500_RA_ACCEL_YOUT_H     0x3D
#define MPU6500_RA_ACCEL_YOUT_L     0x3E
#define MPU6500_RA_ACCEL_ZOUT_H     0x3F
#define MPU6500_RA_ACCEL_ZOUT_L     0x40
#define MPU6500_RA_TEMP_OUT_H       0x41
#define MPU6500_RA_TEMP_OUT_L       0x42
#define MPU6500_RA_GYRO_XOUT_H      0x43
#define MPU6500_RA_GYRO_XOUT_L      0x44
#define MPU6500_RA_GYRO_YOUT_H      0x45
#define MPU6500_RA_GYRO_YOUT_L      0x46
#define MPU6500_RA_GYRO_ZOUT_H      0x47
#define MPU6500_RA_GYRO_ZOUT_L      0x48
#define MPU6500_RA_EXT_SENS_DATA_00 0x49
#define MPU6500_RA_EXT_SENS_DATA_01 0x4A
#define MPU6500_RA_EXT_SENS_DATA_02 0x4B
#define MPU6500_RA_EXT_SENS_DATA_03 0x4C
#define MPU6500_RA_EXT_SENS_DATA_04 0x4D
#define MPU6500_RA_EXT_SENS_DATA_05 0x4E
#define MPU6500_RA_EXT_SENS_DATA_06 0x4F
#define MPU6500_RA_EXT_SENS_DATA_07 0x50
#define MPU6500_RA_EXT_SENS_DATA_08 0x51
#define MPU6500_RA_EXT_SENS_DATA_09 0x52
#define MPU6500_RA_EXT_SENS_DATA_10 0x53
#define MPU6500_RA_EXT_SENS_DATA_11 0x54
#define MPU6500_RA_EXT_SENS_DATA_12 0x55
#define MPU6500_RA_EXT_SENS_DATA_13 0x56
#define MPU6500_RA_EXT_SENS_DATA_14 0x57
#define MPU6500_RA_EXT_SENS_DATA_15 0x58
#define MPU6500_RA_EXT_SENS_DATA_16 0x59
#define MPU6500_RA_EXT_SENS_DATA_17 0x5A
#define MPU6500_RA_EXT_SENS_DATA_18 0x5B
#define MPU6500_RA_EXT_SENS_DATA_19 0x5C
#define MPU6500_RA_EXT_SENS_DATA_20 0x5D
#define MPU6500_RA_EXT_SENS_DATA_21 0x5E
#define MPU6500_RA_EXT_SENS_DATA_22 0x5F
#define MPU6500_RA_EXT_SENS_DATA_23 0x60
// Not in documentation
#define MPU6500_RA_MOT_DETECT_STATUS    0x61
// Not in documentation end
#define MPU6500_RA_I2C_SLV0_DO      0x63
#define MPU6500_RA_I2C_SLV1_DO      0x64
#define MPU6500_RA_I2C_SLV2_DO      0x65
#define MPU6500_RA_I2C_SLV3_DO      0x66
#define MPU6500_RA_I2C_MST_DELAY_CTRL   0x67
#define MPU6500_RA_SIGNAL_PATH_RESET    0x68
// Not in documentation
#define MPU6500_RA_MOT_DETECT_CTRL      0x69
// Not in documentation end
#define MPU6500_RA_USER_CTRL        0x6A
#define MPU6500_RA_PWR_MGMT_1       0x6B
#define MPU6500_RA_PWR_MGMT_2       0x6C
#define MPU6500_RA_FIFO_COUNTH      0x72
#define MPU6500_RA_FIFO_COUNTL      0x73
#define MPU6500_RA_FIFO_R_W         0x74
#define MPU6500_RA_WHO_AM_I         0x75

//
//	Registers 13 to 16 – Self Test Registers
//	SELF_TEST_X, SELF_TEST_Y, SELF_TEST_Z, and SELF_TEST_A
//
#define MPU6500_SELF_TEST_XA_1_BIT     0x07
#define MPU6500_SELF_TEST_XA_1_LENGTH  0x03
#define MPU6500_SELF_TEST_XA_2_BIT     0x05
#define MPU6500_SELF_TEST_XA_2_LENGTH  0x02
#define MPU6500_SELF_TEST_YA_1_BIT     0x07
#define MPU6500_SELF_TEST_YA_1_LENGTH  0x03
#define MPU6500_SELF_TEST_YA_2_BIT     0x03
#define MPU6500_SELF_TEST_YA_2_LENGTH  0x02
#define MPU6500_SELF_TEST_ZA_1_BIT     0x07
#define MPU6500_SELF_TEST_ZA_1_LENGTH  0x03
#define MPU6500_SELF_TEST_ZA_2_BIT     0x01
#define MPU6500_SELF_TEST_ZA_2_LENGTH  0x02

#define MPU6500_SELF_TEST_XG_1_BIT     0x04
#define MPU6500_SELF_TEST_XG_1_LENGTH  0x05
#define MPU6500_SELF_TEST_YG_1_BIT     0x04
#define MPU6500_SELF_TEST_YG_1_LENGTH  0x05
#define MPU6500_SELF_TEST_ZG_1_BIT     0x04
#define MPU6500_SELF_TEST_ZG_1_LENGTH  0x05

//
//	Register 26 – Configuration
//	CONFIG
//
#define MPU6500_CFG_EXT_SYNC_SET_BIT    5
#define MPU6500_CFG_EXT_SYNC_SET_LENGTH 3
#define MPU6500_CFG_DLPF_CFG_BIT    2
#define MPU6500_CFG_DLPF_CFG_LENGTH 3

#define MPU6500_EXT_SYNC_DISABLED       0x0
#define MPU6500_EXT_SYNC_TEMP_OUT_L     0x1
#define MPU6500_EXT_SYNC_GYRO_XOUT_L    0x2
#define MPU6500_EXT_SYNC_GYRO_YOUT_L    0x3
#define MPU6500_EXT_SYNC_GYRO_ZOUT_L    0x4
#define MPU6500_EXT_SYNC_ACCEL_XOUT_L   0x5
#define MPU6500_EXT_SYNC_ACCEL_YOUT_L   0x6
#define MPU6500_EXT_SYNC_ACCEL_ZOUT_L   0x7

#define MPU6500_DLPF_BW_256         0x00
#define MPU6500_DLPF_BW_188         0x01
#define MPU6500_DLPF_BW_98          0x02
#define MPU6500_DLPF_BW_42          0x03
#define MPU6500_DLPF_BW_20          0x04
#define MPU6500_DLPF_BW_10          0x05
#define MPU6500_DLPF_BW_5           0x06

//
//	Register 27 – Gyroscope Configuration
//	GYRO_CONFIG
//
#define MPU6500_GCONFIG_FS_SEL_BIT      4
#define MPU6500_GCONFIG_FS_SEL_LENGTH   2

#define MPU6500_GYRO_FS_250         0x00
#define MPU6500_GYRO_FS_500         0x01
#define MPU6500_GYRO_FS_1000        0x02
#define MPU6500_GYRO_FS_2000        0x03

//
//	Register 28 – Accelerometer Configuration
//	ACCEL_CONFIG
//
#define MPU6500_ACONFIG_XA_ST_BIT           7
#define MPU6500_ACONFIG_YA_ST_BIT           6
#define MPU6500_ACONFIG_ZA_ST_BIT           5
#define MPU6500_ACONFIG_AFS_SEL_BIT         4
#define MPU6500_ACONFIG_AFS_SEL_LENGTH      2
#define MPU6500_ACONFIG_ACCEL_HPF_BIT       2
#define MPU6500_ACONFIG_ACCEL_HPF_LENGTH    3

#define MPU6500_ACCEL_FS_2          0x00
#define MPU6500_ACCEL_FS_4          0x01
#define MPU6500_ACCEL_FS_8          0x02
#define MPU6500_ACCEL_FS_16         0x03

//
//
//
#define MPU6500_DHPF_RESET          0x00
#define MPU6500_DHPF_5              0x01
#define MPU6500_DHPF_2P5            0x02
#define MPU6500_DHPF_1P25           0x03
#define MPU6500_DHPF_0P63           0x04
#define MPU6500_DHPF_HOLD           0x07

//
//	Register 35 – FIFO Enable
//	FIFO_EN
//
#define MPU6500_TEMP_FIFO_EN_BIT    7
#define MPU6500_XG_FIFO_EN_BIT      6
#define MPU6500_YG_FIFO_EN_BIT      5
#define MPU6500_ZG_FIFO_EN_BIT      4
#define MPU6500_ACCEL_FIFO_EN_BIT   3
#define MPU6500_SLV2_FIFO_EN_BIT    2
#define MPU6500_SLV1_FIFO_EN_BIT    1
#define MPU6500_SLV0_FIFO_EN_BIT    0



//
//	Register 104 – Signal Path Reset
//	SIGNAL_PATH_RESE
//
#define MPU6500_PATHRESET_GYRO_RESET_BIT    2
#define MPU6500_PATHRESET_ACCEL_RESET_BIT   1
#define MPU6500_PATHRESET_TEMP_RESET_BIT    0

//
//	Register 106 – User Control
//	USER_CTRL
//
#define MPU6500_USERCTRL_FIFO_EN_BIT            6
#define MPU6500_USERCTRL_I2C_MST_EN_BIT         5
#define MPU6500_USERCTRL_I2C_IF_DIS_BIT         4
#define MPU6500_USERCTRL_FIFO_RESET_BIT         2
#define MPU6500_USERCTRL_I2C_MST_RESET_BIT      1
#define MPU6500_USERCTRL_SIG_COND_RESET_BIT     0

//
//	Register 107 – Power Management 1
//	PWR_MGMT_1
//
#define MPU6500_PWR1_DEVICE_RESET_BIT   7
#define MPU6500_PWR1_SLEEP_BIT          6
#define MPU6500_PWR1_CYCLE_BIT          5
#define MPU6500_PWR1_TEMP_DIS_BIT       3
#define MPU6500_PWR1_CLKSEL_BIT         2
#define MPU6500_PWR1_CLKSEL_LENGTH      3

#define MPU6500_CLOCK_INTERNAL          0x00
#define MPU6500_CLOCK_PLL_XGYRO         0x01
#define MPU6500_CLOCK_PLL_YGYRO         0x02
#define MPU6500_CLOCK_PLL_ZGYRO         0x03
#define MPU6500_CLOCK_PLL_EXT32K        0x04
#define MPU6500_CLOCK_PLL_EXT19M        0x05
#define MPU6500_CLOCK_KEEP_RESET        0x07

//
//	Register 108 – Power Management 2
//	PWR_MGMT_2
//
#define MPU6500_PWR2_LP_WAKE_CTRL_BIT       7
#define MPU6500_PWR2_LP_WAKE_CTRL_LENGTH    2
#define MPU6500_PWR2_STBY_XA_BIT            5
#define MPU6500_PWR2_STBY_YA_BIT            4
#define MPU6500_PWR2_STBY_ZA_BIT            3
#define MPU6500_PWR2_STBY_XG_BIT            2
#define MPU6500_PWR2_STBY_YG_BIT            1
#define MPU6500_PWR2_STBY_ZG_BIT            0

#define MPU6500_WAKE_FREQ_1P25      0x0
#define MPU6500_WAKE_FREQ_5       	0x1
#define MPU6500_WAKE_FREQ_20        0x2
#define MPU6500_WAKE_FREQ_40        0x3

//
//	Register 117 – Who Am I
//	WHO_AM_I
//
#define MPU6500_WHO_AM_I_BIT        6
#define MPU6500_WHO_AM_I_LENGTH     6

//***********************************//
//			FUNCTIONS				 //
//***********************************//
void MPU6500_Init(I2C_HandleTypeDef *hi2c);
uint8_t MPU6500_GetDeviceID();

//
//	CONFIG
//
void MPU6500_SetDlpf(uint8_t Value);

//
//	PWR_MGMT_1
//
void MPU6500_DeviceReset(uint8_t Reset);
void MPU6500_SetClockSource(uint8_t Source);
void MPU6500_SetSleepEnabled(uint8_t Enable);
void MPU6500_SetCycleEnabled(uint8_t Enable);
void MPU6500_SetTemperatureSensorDisbled(uint8_t Disable);

//
//	PWR_MGMT_2
//
void MPU6500_SetLowPowerWakeUpFrequency(uint8_t Frequency);
void MPU6500_AccelerometerAxisStandby(uint8_t XA_Stby, uint8_t YA_Stby, uint8_t ZA_Stby);
void MPU6500_GyroscopeAxisStandby(uint8_t XG_Stby, uint8_t YG_Stby, uint8_t ZG_Stby);

//
//	Measurement scale configuration
//
void MPU6500_SetFullScaleGyroRange(uint8_t Range);
void MPU6500_SetFullScaleAccelRange(uint8_t Range);

//
// Reading data
//
int16_t MPU6500_GetTemperatureRAW(void);
float MPU6500_GetTemperatureCelsius(void);

int16_t MPU6500_GetAccelerationXRAW(void);
int16_t MPU6500_GetAccelerationYRAW(void);
int16_t MPU6500_GetAccelerationZRAW(void);
void MPU6500_GetAccelerometerRAW(int16_t* x, int16_t* y, int16_t* z);
void MPU6500_GetAccelerometerScaled(float* x, float* y, float* z);

int16_t MPU6500_GetRotationXRAW(void);
int16_t MPU6500_GetRotationYRAW(void);
int16_t MPU6500_GetRotationZRAW(void);
void MPU6500_GetGyroscopeRAW(int16_t* x, int16_t* y, int16_t* z);
void MPU6500_GetGyroscopeScaled(float* x, float* y, float* z);

void MPU6500_GetRollPitch(float* Roll, float* Pitch);


#endif /* MPU6500_H_ */
