#ifndef LED_H //kontrollerar om LED_H inte har definierats tidigare
#define LED_H //definierar LED_H

#include <stdint.h> //inkluderar standardbiblioteksfil stdint.h
#include "uart.h" //inkluderar UART-drivrutinen
#include "stm32f4xx.h"   //inkluderar header-filen för vårt utvecklingskort               

#define	LED_PORT 		GPIOB //definerar port B som den port som skall användas för LED arbetet

#define	LED_PORT_CLOCK  (1U<<1) //definerar klocksignalen för den port där LED skall vara ansluten

#define LED_RED_PIN	(1U<<14) //definerar siftet på porten som skall nyttjas till respektive LED färg
#define LED_GREEN_PIN	(1U<<12)
#define	LED_BLUE_PIN	(1U<<15)
#define LED_YELLOW_PIN	(1U<<13)

#define LED_RED_MODE_BIT  (1U<<28) //definerar lägesbiten spm skall nyttjas till respektive LED_färg
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)

//define enumerationskonstanter för de olika färgerna av LED

typedef  enum {   
  
	RED		= 0,  
	GREEN,
	YELLOW,
	BLUE

}LedColor_Type;

//define enumerationskonstanten för av och på
typedef enum{
 OFF =0, 
 ON = 1
}LedState_Type;




typedef struct{
	
 LedColor_Type color;  //färgen på LED lampan
 LedState_Type state;  //tillståndet för LED lampan
	
}Led_Type;


void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state); //constructor som formar LED-en
void Led_setState(Led_Type * const me,LedState_Type _state); //constructor som sättar statusen på LED-en
LedState_Type Led_getState(Led_Type * const me); // constructor som hämtar statusen på LED-en
#endif
