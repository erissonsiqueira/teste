/**
  *******************************************************************************************************
  * @file    hx711.h
  * @author  Erisson Siqueira
  * @brief   Test Version
  *******************************************************************************************************
 */
 
#ifndef __HX711
#define __HX711

/* Includes --------------------------------------------------------------------------------------------*/											
#include "stm32f1xx_hal.h"
														
/* Defines ---------------------------------------------------------------------------------------------*/
#define	MAX_BUFFER		10

//#define A0(x)			((x)?	(HAL_GPIO_WritePin(ADS1232_A0_GPIO_Port, ADS1232_A0_Pin, GPIO_PIN_SET)):\
//												(HAL_GPIO_WritePin(ADS1232_A0_GPIO_Port, ADS1232_A0_Pin, GPIO_PIN_RESET)));

//#define SCLK(x)		((x)?	(HAL_GPIO_WritePin(ADS1232_SCK_GPIO_Port, ADS1232_SCK_Pin, GPIO_PIN_SET)):\
//												(HAL_GPIO_WritePin(ADS1232_SCK_GPIO_Port, ADS1232_SCK_Pin, GPIO_PIN_RESET)));

//#define SPEED(x)	((x)?	(HAL_GPIO_WritePin(ADS1232_SPEED_GPIO_Port, ADS1232_SPEED_Pin, GPIO_PIN_SET)):\
//												(HAL_GPIO_WritePin(ADS1232_SPEED_GPIO_Port, ADS1232_SPEED_Pin, GPIO_PIN_RESET)));

//#define PDOWN(x)	((x)?	(HAL_GPIO_WritePin(ADS1232_PDOWN_GPIO_Port, ADS1232_PDOWN_Pin, GPIO_PIN_SET)):\
//												(HAL_GPIO_WritePin(ADS1232_PDOWN_GPIO_Port, ADS1232_PDOWN_Pin, GPIO_PIN_RESET)));

//#define GAIN_1(x)	((x)?	(HAL_GPIO_WritePin(ADS1232_GAIN1_GPIO_Port, ADS1232_GAIN1_Pin, GPIO_PIN_SET)):\
//												(HAL_GPIO_WritePin(ADS1232_GAIN1_GPIO_Port, ADS1232_GAIN1_Pin, GPIO_PIN_RESET)));

//#define GAIN_0(x)	((x)?	(HAL_GPIO_WritePin(ADS1232_GAIN0_GPIO_Port, ADS1232_GAIN0_Pin, GPIO_PIN_SET)):\
//												(HAL_GPIO_WritePin(ADS1232_GAIN0_GPIO_Port, ADS1232_GAIN0_Pin, GPIO_PIN_RESET)));

//#define DOUT_READ_BIT			HAL_GPIO_ReadPin(ADS1232_DOUT_GPIO_Port, ADS1232_DOUT_Pin)





#define SCLK(x)		((x)?	(HAL_GPIO_WritePin(HX711_SCK_GPIO_Port, HX711_SCK_Pin, GPIO_PIN_SET)):\
												(HAL_GPIO_WritePin(HX711_SCK_GPIO_Port, HX711_SCK_Pin, GPIO_PIN_RESET)));

#define DOUT_READ_BIT			HAL_GPIO_ReadPin(HX711_DT_GPIO_Port, HX711_DT_Pin)

/* Variables -------------------------------------------------------------------------------------------*/		

/* Structs ---------------------------------------------------------------------------------------------*/

/* Function Prototypes ---------------------------------------------------------------------------------*/
//void 	Start(void);
//void 	Calib(void);
//int Read(void);
//void Full(float num, int len);
//float Average(float num, int len);
//void 	Delay_ms (int delay);
//void 	Delay_us (int delay);

void ReadValor(void);
void Init(void);
void PutBuffer(float num, int len);
float TakeAverage(int len);
//float TakeAverage(int len);
//void PutBuffer(float num, int len);
#endif

