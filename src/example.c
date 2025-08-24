#include "main.h"
#include "e22_lib.h"
#include "usart.h"
#include "gpio.h"

#define TELEM_UART_HNDLR huartx  // Write here your lora uart handler. (i.e. huart1)

int main(void)
{
  
	lora_init();
	while (1)
	{

	}

}


void lora_init(void)
{
	lora_1.baud_rate 		= 	E22_BAUD_RATE_115200;
	lora_1.parity_bit		=	E22_PARITY_8N1;
	lora_1.air_rate			=	E22_AIR_DATA_RATE_38400;
	lora_1.packet_size		=	E22_PACKET_SIZE_64;
	lora_1.rssi_noise		=	E22_RSSI_NOISE_DISABLE;
	lora_1.power			=	E22_TRANSMITTING_POWER_22;
	lora_1.rssi_enable		=	E22_ENABLE_RSSI_DISABLE;
	lora_1.mode				= 	E22_TRANSMISSION_MODE_TRANSPARENT;
	lora_1.repeater_func	=	E22_REPEATER_FUNC_DISABLE;
	lora_1.lbt				=	E22_LBT_DISABLE;
	lora_1.wor				=	E22_WOR_RECEIVER;
	lora_1.wor_cycle		=	E22_WOR_CYCLE_1000;
	lora_1.channel			=	25;

	lora_1.pins.m0_pin = RF_M0_Pin;			// M0 pin.
	lora_1.pins.m0_pin_port = RF_M0_GPIO_Port;	// M0 gpio port.
	lora_1.pins.m1_pin = RF_M1_Pin;			// M1 pin.
	lora_1.pins.m1_pin_port = RF_M1_GPIO_Port;	// M1 gpio port.

	e22_init(&lora_1, &TELEM_UART_HNDLR);

	HAL_UART_DeInit(&TELEM_UART_HNDLR);
	TELEM_UART_HNDLR.Init.BaudRate = 115200;	// Write here your lora's new baud rate. 
	HAL_UART_Init(&TELEM_UART_HNDLR);
}


