#ifndef _LSM9DS1_H_
#define _LSM9DS1_H_
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "driver/i2c.h"
#define LSM9DS1_ADDRESS_ACCELGYRO          (0x6B)
#define LSM9DS1_ADDRESS_MAG                (0x1E)
#define LSM9DS1_XG_ID                      (0b01101000)
#define LSM9DS1_MAG_ID                     (0b00111101)
// Linear Acceleration: mg per LSB
#define LSM9DS1_ACCEL_MG_LSB_2G (0.061F)
#define LSM9DS1_ACCEL_MG_LSB_4G (0.122F)
#define LSM9DS1_ACCEL_MG_LSB_8G (0.244F)
#define LSM9DS1_ACCEL_MG_LSB_16G (0.732F) 
// Magnetic Field Strength: gauss range
#define LSM9DS1_MAG_MGAUSS_4GAUSS      (0.14F)
#define LSM9DS1_MAG_MGAUSS_8GAUSS      (0.29F)
#define LSM9DS1_MAG_MGAUSS_12GAUSS     (0.43F)
#define LSM9DS1_MAG_MGAUSS_16GAUSS     (0.58F)
// Angular Rate: dps per LSB
#define LSM9DS1_GYRO_DPS_DIGIT_245DPS      (0.00875F)
#define LSM9DS1_GYRO_DPS_DIGIT_500DPS      (0.01750F)
#define LSM9DS1_GYRO_DPS_DIGIT_2000DPS     (0.07000F)
// Temperature: LSB per degree celsius
#define LSM9DS1_TEMP_LSB_DEGREE_CELSIUS    (8)  // 1°C = 8, 25° = 200, etc.
#define MAGTYPE                           (true)
#define XGTYPE                            (false)
#define WRITE_BIT                 (I2C_MASTER_WRITE) /*!< I2C master write */
#define READ_BIT                  (I2C_MASTER_READ)  /*!< I2C master read */
#define ACK_CHECK_EN              (0x1)              /*!< I2C master will check ack from slave*/
#define ACK_CHECK_DIS             (0x0)              /*!< I2C master will not check ack from slave */
#define ACK_VAL                   (0x0)            /*!< I2C ack value */
#define NACK_VAL                   (0x1)
#define I2C_BUS                   (0)
#define SENSORS_GRAVITY_EARTH     9.80665F           /**< Earth's gravity in m/s^2 */
#define SENSORS_GRAVITY_STANDARD  SENSORS_GRAVITY_EARTH
  typedef enum
    {
      LSM9DS1_REGISTER_WHO_AM_I_XG         = 0x0F,
      LSM9DS1_REGISTER_CTRL_REG1_G         = 0x10,
      LSM9DS1_REGISTER_CTRL_REG2_G         = 0x11,
      LSM9DS1_REGISTER_CTRL_REG3_G         = 0x12,
      LSM9DS1_REGISTER_TEMP_OUT_L          = 0x15,
      LSM9DS1_REGISTER_TEMP_OUT_H          = 0x16,
      LSM9DS1_REGISTER_STATUS_REG          = 0x17,
      LSM9DS1_REGISTER_OUT_X_L_G           = 0x18,
      LSM9DS1_REGISTER_OUT_X_H_G           = 0x19,
      LSM9DS1_REGISTER_OUT_Y_L_G           = 0x1A,
      LSM9DS1_REGISTER_OUT_Y_H_G           = 0x1B,
      LSM9DS1_REGISTER_OUT_Z_L_G           = 0x1C,
      LSM9DS1_REGISTER_OUT_Z_H_G           = 0x1D,
      LSM9DS1_REGISTER_CTRL_REG4           = 0x1E,
      LSM9DS1_REGISTER_CTRL_REG5_XL        = 0x1F,
      LSM9DS1_REGISTER_CTRL_REG6_XL        = 0x20,
      LSM9DS1_REGISTER_CTRL_REG7_XL        = 0x21,
      LSM9DS1_REGISTER_CTRL_REG8           = 0x22,
      LSM9DS1_REGISTER_CTRL_REG9           = 0x23,
      LSM9DS1_REGISTER_CTRL_REG10          = 0x24,

      LSM9DS1_REGISTER_OUT_X_L_XL          = 0x28,
      LSM9DS1_REGISTER_OUT_X_H_XL          = 0x29,
      LSM9DS1_REGISTER_OUT_Y_L_XL          = 0x2A,
      LSM9DS1_REGISTER_OUT_Y_H_XL          = 0x2B,
      LSM9DS1_REGISTER_OUT_Z_L_XL          = 0x2C,
      LSM9DS1_REGISTER_OUT_Z_H_XL          = 0x2D,

    } lsm9ds1AccGyroRegisters_t;
  
    typedef enum
    {

      LSM9DS1_REGISTER_WHO_AM_I_M         = 0x0F,
      LSM9DS1_REGISTER_CTRL_REG1_M        = 0x20,
      LSM9DS1_REGISTER_CTRL_REG2_M        = 0x21,
      LSM9DS1_REGISTER_CTRL_REG3_M        = 0x22,
      LSM9DS1_REGISTER_CTRL_REG4_M        = 0x23,
      LSM9DS1_REGISTER_CTRL_REG5_M        = 0x24,
      LSM9DS1_REGISTER_STATUS_REG_M       = 0x27,
      LSM9DS1_REGISTER_OUT_X_L_M          = 0x28,
      LSM9DS1_REGISTER_OUT_X_H_M          = 0x29,
      LSM9DS1_REGISTER_OUT_Y_L_M          = 0x2A,
      LSM9DS1_REGISTER_OUT_Y_H_M          = 0x2B,
      LSM9DS1_REGISTER_OUT_Z_L_M          = 0x2C,
      LSM9DS1_REGISTER_OUT_Z_H_M          = 0x2D,
      LSM9DS1_REGISTER_CFG_M              = 0x30,
      LSM9DS1_REGISTER_INT_SRC_M          = 0x31,
    } lsm9ds1MagRegisters_t;

    typedef enum
    {
      LSM9DS1_ACCELRANGE_2G                = (0b00 << 3),
      LSM9DS1_ACCELRANGE_16G               = (0b01 << 3),
      LSM9DS1_ACCELRANGE_4G                = (0b10 << 3),
      LSM9DS1_ACCELRANGE_8G                = (0b11 << 3),
    } lsm9ds1AccelRange_t;
    
    typedef enum
    {
      LSM9DS1_ACCELDATARATE_POWERDOWN      = (0b0000 << 4),
      LSM9DS1_ACCELDATARATE_3_125HZ        = (0b0001 << 4),
      LSM9DS1_ACCELDATARATE_6_25HZ         = (0b0010 << 4),
      LSM9DS1_ACCELDATARATE_12_5HZ         = (0b0011 << 4),
      LSM9DS1_ACCELDATARATE_25HZ           = (0b0100 << 4),
      LSM9DS1_ACCELDATARATE_50HZ           = (0b0101 << 4),
      LSM9DS1_ACCELDATARATE_100HZ          = (0b0110 << 4),
      LSM9DS1_ACCELDATARATE_200HZ          = (0b0111 << 4),
      LSM9DS1_ACCELDATARATE_400HZ          = (0b1000 << 4),
      LSM9DS1_ACCELDATARATE_800HZ          = (0b1001 << 4),
      LSM9DS1_ACCELDATARATE_1600HZ         = (0b1010 << 4)
    } lm9ds1AccelDataRate_t;
    
    typedef enum
    {
      LSM9DS1_MAGGAIN_4GAUSS               = (0b00 << 5),  // +/- 4 gauss
      LSM9DS1_MAGGAIN_8GAUSS               = (0b01 << 5),  // +/- 8 gauss
      LSM9DS1_MAGGAIN_12GAUSS              = (0b10 << 5),  // +/- 12 gauss
      LSM9DS1_MAGGAIN_16GAUSS              = (0b11 << 5)   // +/- 16 gauss
    } lsm9ds1MagGain_t;
    
    typedef enum
    {
      LSM9DS1_MAGDATARATE_3_125HZ          = (0b000 << 2),
      LSM9DS1_MAGDATARATE_6_25HZ           = (0b001 << 2),
      LSM9DS1_MAGDATARATE_12_5HZ           = (0b010 << 2),
      LSM9DS1_MAGDATARATE_25HZ             = (0b011 << 2),
      LSM9DS1_MAGDATARATE_50HZ             = (0b100 << 2),
      LSM9DS1_MAGDATARATE_100HZ            = (0b101 << 2)
    } lsm9ds1MagDataRate_t;

    typedef enum
    {
      LSM9DS1_GYROSCALE_245DPS             = (0b00 << 3),  // +/- 245 degrees per second rotation
      LSM9DS1_GYROSCALE_500DPS             = (0b01 << 3),  // +/- 500 degrees per second rotation
      LSM9DS1_GYROSCALE_2000DPS            = (0b11 << 3)   // +/- 2000 degrees per second rotation
    } lsm9ds1GyroScale_t;
    
    typedef struct vector_s
    {
      float x;
      float y;
      float z;
    } lsm9ds1Vector_t;
    
    lsm9ds1Vector_t accelData;    // Last read accelerometer data will be available here
    lsm9ds1Vector_t magData;      // Last read magnetometer data will be available here
    lsm9ds1Vector_t gyroData;     // Last read gyroscope data will be available here
    int16_t         temperature;  // Last read temperzture data will be available here
    esp_err_t lsm_accel_read_reg(i2c_port_t i2c_num,  uint8_t reg_addr, uint8_t *data, uint16_t len);
    esp_err_t lsm_magnetometer_read_reg(i2c_port_t i2c_num,  uint8_t reg_addr, uint8_t *data, uint16_t len);
    esp_err_t lsm_accel_write_reg(i2c_port_t i2c_num, uint8_t i2c_reg, uint8_t* data_wr, size_t size);
    esp_err_t lsm_mag_write_reg(i2c_port_t i2c_num, uint8_t i2c_reg, uint8_t* data, size_t size);
    void lsmbegin();
    void readAccel();
    void readMag();
    void readGyro();
    void readTemp();
    int8_t  _csm, _csxg, _mosi, _miso, _clk;
    float   _accel_mg_lsb;
    float   _mag_mgauss_lsb;
    float   _gyro_dps_digit;

#endif