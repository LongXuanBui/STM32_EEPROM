/*
 * EEPROM_32Kbit.c
 *
 *  Created on: Sep 18, 2022
 *      Author: LongXuanBui
 */
#include "EEPROM_32Kbit.h"
#include <string.h>
I2C_HandleTypeDef *hi2c;
uint8_t device_address=0;
void eeprom32_init(I2C_HandleTypeDef *handle)
{
	hi2c=handle;
	  for(uint8_t i=1; i<256; i++)
	     {
	        if( HAL_I2C_IsDeviceReady(hi2c, (uint16_t)i, 3, 5)==HAL_OK)
	        {

	        	device_address=i;
	        break;
	        }
	     }
	  if(device_address==0)
	  {
		  device_address=DEFAULT_DEVICE_ADD;
	  }
}

void eeprom32_clear_all()

{	uint8_t data[MEM_SIZE];
	memset(data,0xff,MEM_SIZE);
	  HAL_I2C_Mem_Write(hi2c, device_address, 0x0000, 2, data, MEM_SIZE, 1000);
	  HAL_Delay(1000);
}

void eeprom32_write_mem(uint16_t address_of_mem,uint8_t *data,uint16_t size)
{
	  HAL_I2C_Mem_Write(hi2c, device_address, address_of_mem, 2, data, size, TIME_OUT);
	  HAL_Delay(5);
}
void eeprom32_read_mem(uint16_t address_of_mem,uint8_t *data,uint16_t size)
{
	HAL_I2C_Mem_Read (hi2c, device_address, address_of_mem, 2, data, size, TIME_OUT);
}
