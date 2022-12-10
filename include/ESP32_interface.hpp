#ifndef ESP32_INTERFACE_H
#define ESP32_INTERFACE_H

/*ESP_MODE*/
#define STATION_MODE         '1'
#define ACCESS_POINT_MODE    '2'

/*ECHO_STATE*/
#define ECHO_OFF    '0'
#define ECHO_ON     '1'

/*CONNECTION_TYPE*/
#define TCP         "\"TCP\""
#define UDP         "\"UDP\""


void ESP_voidRESET(void);
ERROR_enumSTATE ESP_enumTesting(void);

ERROR_enumSTATE ESP_enumSETMODE(u8 Copy_ptru8MODE );

ERROR_enumSTATE ESP_enumSetEcho_STATE(u8 Copy_u8ECHO_STATE );

ERROR_enumSTATE ESP_enumConnect_To_WIFI( u8 * Copy_ptru8Wifi_frame , u8 * Copy_ptru8Password );
ERROR_enumSTATE ESP_enumRecieveData( u8 * Copy_u8Number_of_letters, u8 *Copy_u8Link,u8 *Copy_u8Data);

ERROR_enumSTATE ESP_enumSet_CONNECTION_TYPE(u8 * Copy_ptru8Connection_State,u8 * Copy_ptru8IP_address,u8 *Copy_ptru8PORT_NUMBER );


#endif
