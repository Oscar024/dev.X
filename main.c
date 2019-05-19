#include <xc.h>
#include <stdio.h>   // for sprintf()
#include "lcd.h"
#include "plib/i2c.h"
#include "KeyPad Library.h"
#include "funciones.h"
 
#define _XTAL_FREQ                              8000000
#define TEXT_BUFFER                             80

char text[TEXT_BUFFER];   
char LCD_01_ADDRESS = 0x40;     // default address
//char LCD_02_ADDRESS = 0b1001100;     // jumper on A0


void longDelay(int time){
   for (int i = 0 ; i < time; i++) __delay_ms(50);
}

// Program entry point
void main() {

    //Reloj si tiene oscilador
    
    OpenI2C(MASTER, SLEW_OFF);
    LCD_init(LCD_01_ADDRESS); 
    KP_init();
//    LCD_init(LCD_02_ADDRESS);

    unsigned int counter = 0;

    while(1) {
      LCD_putcmd(LCD_01_ADDRESS, LCD_CLEAR,1);
      
      sprintf(text, "num: %lu", keyNumber());
//      LCD_goto(LCD_01_ADDRESS,1,1);
//      LCD_putch(LCD_01_ADDRESS, KP_Readbutton()); 
      LCD_goto(LCD_01_ADDRESS,2,1);
      LCD_puts(LCD_01_ADDRESS,text ); 
      LCD_goto(LCD_01_ADDRESS,3,1);
      LCD_puts(LCD_01_ADDRESS, "--------------\0"); 
      LCD_goto(LCD_01_ADDRESS,4,1);
      LCD_puts(LCD_01_ADDRESS, "Carvajal\0"); 
      longDelay(10);  

      

    } // while(1)
} // main()