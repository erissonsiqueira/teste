/**
  *******************************************************************************************************
  * @file    ads1232.c 
  * @author  Erisson Siqueira  
  * @brief   Test Version
  *******************************************************************************************************
 */
	
/* Includes --------------------------------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "hx711.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>	


/* Defines ---------------------------------------------------------------------------------------------*/

/* Variables -------------------------------------------------------------------------------------------*/
double buf[MAX_BUFFER];
//extern int times;
int valor=0;
//int valor2=0;

int ad_value=0;
int adc=0;

int inf=0;
//float fValor=0;

/* Functions -------------------------------------------------------------------------------------------*/
//// START
//void Start(void)
//{	
//		PDOWN(0);
//		SCLK(0);
//		Delay_us(200);
//		PDOWN(1);																		// Turn on module
//	
//		Delay_us(200);																// Wait 20us
//			
//		A0(0);																			// Channel to read
//		
//		/********** GAIN_64 *********/	
//		GAIN_1(1);	
//		GAIN_0(1);		
//		/********** 80_SPS ***********/		
//		//SPEED(1);
//	SPEED(0);
//	
//		Delay_us(200);																// Wait 20us
//	
//		//while(DOUT_READ_BIT);												// Wait for data ready	
//}

//// CALIB
//void Calib(void)
//{		
//		
//		while(DOUT_READ_BIT)
//		{ 
//				SCLK(0);																
//				SCLK(1);
//				Delay_us(1);														// Wait 1us
//				SCLK(0);				
//		}
//		
//		for (char count=1;count<=4;count++) 
//		{
//				Delay_ms(100);													// Wait 100ms
//				Read();
//		}			
//		
//		while(DOUT_READ_BIT);												// Wait for data ready
//		
//		for(char count=0;count<=25;count++)					// 25 Clocks
//		{
//				SCLK(0);
//				SCLK(1);
//				Delay_us(1);														// Wait 1us
//				SCLK(0);	
//		}
//		
//		Delay_ms(100);															// Wait 1s
//}




//// READ
//int Read(void)
//{		
//		int data	=	0;
//	
//		while(DOUT_READ_BIT)
//		//times++;
//		SCLK(0);
//		
//		for (char count=0; count<25; count++)
//		{								
//			SCLK(1);
//			data = data << 1;
//			SCLK(0);
//						
//			if(DOUT_READ_BIT)
//				data++;		
//		}
//		data = data >>1;
//		
//		if (data >= 0x800000)
//				data = data ^ 0xFF000000;	
//		
//		return data;
//}


// READ
void ReadValor(void)
{		
		int data	=	0;
	
		SCLK(0);
	inf++;
		for (char count=0; count<25; count++)
		{				
			SCLK(1);
			data = data << 1;
			SCLK(0);
						
			if(DOUT_READ_BIT)
				data++;		
		}
																	
		data = data >>1;																

		
		if (data >= 0x800000)
				data = data ^ 0xFF000000;	
		
		//return data;
		valor=data;
		//valor2=valor/64;
		//ad_value=valor/16;
		//ad_value=valor/32;
		
		ad_value=valor/16;
		//adc=valor/8;
}


// READ
void Init(void)
{		
		SCLK(0);
		for (char count=0; count<25; count++)
		{				
			SCLK(1);
			SCLK(0);
		}															
}


// PUT BUFFER
void PutBuffer(float num, int len)
{
	for (int i=0; i<len-1; i++)
	{
		buf[i]=buf[i+1];
	}
	buf[len-1]=num;
}

// TAKE AVERAGE
float TakeAverage(int len)
{
	float sum=0;
	
	for (int i=0; i<len; i++)
	{
		sum+=buf[i];
	}
	
	return (float)sum/len;
}

////// READ
////void ReadValor(void)
////{		
////		int data	=	0;
////		
////		SCLK(0);
////		for (char count=0; count<24; count++)
////		{								
////			SCLK(1);
////			data = data << 1;
////			//SCLK(0);
////						
////			if(DOUT_READ_BIT)
////				data++;	
////				
////			SCLK(0);
////		}
////		//data = data >>1;
////		
////		SCLK(1);
////		SCLK(0);
////		
////		if (data >= 0x800000)
////				data = data ^ 0xFF000000;	
////		
////		valor=data;
////		//valor=round(valor/167)*1670;
////		//fValor=Average((float)valor/128, 8);
////		PutBuffer((float)valor/167, 80);
////}


//// FULL
//void Full(float num, int len)
//{
//	for (int i=0; i<len; i++)
//	{
//		buf[i]=num;
//	}
//}

//// AVERAGE
//float Average(float num, int len)
//{
//	float sum=0;
//	
//	for (int i=0; i<len-1; i++)
//	{
//		buf[i]=buf[i+1];
//	}
//	buf[len-1]=num;
//	
//	for (int i=0; i<len; i++)
//	{
//		sum+=buf[i];
//	}
//	
//	return (float)sum/len;
//}


//// PUT BUFFER
//void PutBuffer(float num, int len)
//{
//	for (int i=0; i<len-1; i++)
//	{
//		buf[i]=buf[i+1];
//	}
//	buf[len-1]=num;
//}

//// TAKE AVERAGE
//float TakeAverage(int len)
//{
//	float sum=0;
//	
//	for (int i=0; i<len; i++)
//	{
//		sum+=buf[i];
//	}
//	
//	return (float)sum/len;
//}


//// DELAY US
//void Delay_us (int delay)
//{
//	float Fclk_Hz = 72000000;
//	
//	float temp;
//	long temp1;

//		temp = (1/Fclk_Hz) ;
//		temp1 = ((delay / temp)/6000000);
//		for (;temp1>0;temp1--);
//}

//// DELAY MS
//void 	Delay_ms (int delay)
//{
//	float Fclk_Hz = 72000000;
//	
//	float temp;
//	long temp1;

//		temp = (1/Fclk_Hz) ;
//		temp1 = ((delay / temp)/8000);
//		for (temp1=temp1 ;temp1>0;temp1--);
//}


