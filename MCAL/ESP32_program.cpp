#include "STD_TYPES.hpp"
#include "BIT_MATH.hpp"
#include "STM32F103C8.hpp"

#include "GPIO_interface.hpp"
#include "UART_interface.hpp"
#include "SysTick_interface.hpp"

#include "ESP32_interface.hpp"
#include "ESP32_private.hpp"
#include "ESP32_config.hpp"

u16 LOC_u16Counter ;
void ESP_voidRESET(void)
{
	UART_enumTransimite_String((u8 *)"AT+RST");
	ESP_voidConfirm_Transmition();
}
ERROR_enumSTATE ESP_enumTesting(void)
{
	LOC_u16Counter = 1;
	ERROR_enumSTATE LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_OK;
	UART_enumTransimite_String((u8 *)"AT");
	ESP_voidConfirm_Transmition();
	while( (UART_ptrReceive_String() != (u8 *)"OK") && (LOC_u16Counter <= 10000) )
	{
		LOC_u16Counter++;
	}
	if( LOC_u16Counter > 10000 ){LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_NOK;}
	return LOC_enumError_State;
}
ERROR_enumSTATE ESP_enumSETMODE(u8 Copy_u8MODE )
{
	LOC_u16Counter = 1;
	ERROR_enumSTATE LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_OK;

	if( Copy_u8MODE =='1' || Copy_u8MODE == '2' )
	{
		UART_enumTransimite_String( (u8 *)"AT+CWMODE=" );
		UART_enumTransmite(Copy_u8MODE);
		ESP_voidConfirm_Transmition();
		while( (UART_ptrReceive_String() != (u8 *)"OK") && (LOC_u16Counter <= 10000) )
		{
			LOC_u16Counter++;
		}
		if( LOC_u16Counter > 10000 ){LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_NOK; }
		}else{LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_NOK;}


	return LOC_enumError_State;
}
ERROR_enumSTATE ESP_enumSetEcho_STATE(u8 Copy_u8ECHO_STATE )
{
	ERROR_enumSTATE LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_OK;
	LOC_u16Counter = 1;
	if( Copy_u8ECHO_STATE =='0' || Copy_u8ECHO_STATE == '1' )
	{
		UART_enumTransimite_String( (u8 *)"ATE" );
		UART_enumTransmite( Copy_u8ECHO_STATE );
		ESP_voidConfirm_Transmition();
		while( (UART_ptrReceive_String() != (u8 *)"OK") && (LOC_u16Counter <= 10000) )
		{
			LOC_u16Counter++;
		}
		if( LOC_u16Counter > 10000 ){LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_NOK; }
		}else{LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_NOK;}


	return LOC_enumError_State;
}
ERROR_enumSTATE ESP_enumConnect_To_WIFI( u8 * Copy_ptru8Wifi_frame , u8 * Copy_ptru8Password )
{
	LOC_u16Counter = 1;
	ERROR_enumSTATE LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_OK;
	if( Copy_ptru8Wifi_frame != NULL && Copy_ptru8Password != NULL )
	{
		UART_enumTransimite_String((u8 *)"AT+CWJAP_CUR=");
		UART_enumTransmite('\"');
		UART_enumTransimite_String(Copy_ptru8Wifi_frame);

		UART_enumTransmite('\"');
		UART_enumTransmite(',');
		UART_enumTransmite('\"');

		UART_enumTransimite_String(Copy_ptru8Password);
		UART_enumTransmite('\"');
		ESP_voidConfirm_Transmition();
		while( UART_ptrReceive_String() != (u8 *)"WIFI CONNECTED" && (LOC_u16Counter <= 10000)  )
		{
			LOC_u16Counter++;

		}
		LOC_u16Counter=1;
		while( UART_ptrReceive_String() != (u8 *)"WIFI GOT IP" && (LOC_u16Counter <= 10000)  )
		{
			LOC_u16Counter++;

		}
		LOC_u16Counter=1;
		while( (UART_ptrReceive_String() != (u8 *)"OK") && (LOC_u16Counter <= 10000) )
		{
			LOC_u16Counter++;
		}
		if( LOC_u16Counter > 10000 ){LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_NOK;}

	}else
	{
		LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_NOK;
	}
	return LOC_enumError_State;
}
ERROR_enumSTATE ESP_enumRecieveData( u8 * Copy_u8Number_of_letters, u8 *Copy_u8Link,u8 *Copy_u8Data)
{
	ERROR_enumSTATE LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_OK;
	if( Copy_u8Link != NULL  &&  Copy_u8Number_of_letters != NULL )
	{
		UART_enumTransimite_String((u8 *)"AT+CIPSEND=");
		UART_enumTransimite_String(Copy_u8Number_of_letters);
		ESP_voidConfirm_Transmition();
		UART_enumTransimite_String((u8 *)"GET ");
		UART_enumTransimite_String(Copy_u8Link);
		*Copy_u8Data = UART_ptrReceive_String()[7];

	}else
	{
		LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_NOK;
	}
	return LOC_enumError_State;

}
ERROR_enumSTATE ESP_enumSet_CONNECTION_TYPE(u8 * Copy_ptru8Connection_State,u8 * Copy_ptru8IP_address,u8 *Copy_ptru8PORT_NUMBER )
{
	LOC_u16Counter = 1;
	ERROR_enumSTATE LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_OK;
	if( Copy_ptru8Connection_State != NULL  &&  Copy_ptru8IP_address != NULL && Copy_ptru8PORT_NUMBER != NULL )
	{
		UART_enumTransimite_String((u8 *)"AT+CIPSTART=");

		UART_enumTransmite('\"');
		UART_enumTransimite_String(Copy_ptru8Connection_State);
		UART_enumTransmite('\"');
		UART_enumTransmite(',');
		UART_enumTransmite('\"');

		UART_enumTransimite_String(Copy_ptru8IP_address);
		UART_enumTransmite('\"');
		UART_enumTransmite(',');


		UART_enumTransimite_String(Copy_ptru8PORT_NUMBER);

		ESP_voidConfirm_Transmition();
		while( UART_ptrReceive_String() != (u8 *)"SEND OK" && (LOC_u16Counter <= 10000)  )
		{
			LOC_u16Counter++;

		}


	}else
	{
		LOC_enumError_State = ERROR_enumSTATE::STD_TYPES_NOK;
	}
	return LOC_enumError_State;

}
static void ESP_voidConfirm_Transmition(void)
{
	UART_enumTransmite('\r');
	UART_enumTransmite('\n');

}
