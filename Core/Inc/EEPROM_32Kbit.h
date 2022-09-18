/*
 * EEPROM_32Kbit.h
 *
 *  Created on: Sep 18, 2022
 *      Author: xuanl
 */

#ifndef INC_EEPROM_32KBIT_H_
#define INC_EEPROM_32KBIT_H_

#include "stm32f4xx_hal.h"
#define MEM_SIZE 4096 // equivalent 32 k_bit
#define DEFAULT_DEVICE_ADD 0xA0// default device address
#define TIME_OUT 100
void eeprom32_init(I2C_HandleTypeDef *handle);
void eeprom32_clear_all();
void eeprom32_write_mem(uint16_t address_of_mem,uint8_t *data,uint16_t size);
void eeprom32_read_mem(uint16_t address_of_mem,uint8_t *data,uint16_t size);
#endif /* INC_EEPROM_32KBIT_H_ */
