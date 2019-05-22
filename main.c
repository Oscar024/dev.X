#include <xc.h>
#include <stdio.h>   // for sprintf()
#include "lcd.h"
#include "plib/i2c.h"
#include "KeyPad Library.h"
#include "funciones.h"
#include "config.h"
 
#define _XTAL_FREQ                              4000000
#define TEXT_BUFFER                             80

char text[TEXT_BUFFER];   
char LCD_01_ADDRESS = 0x27;     // default address of chip



void longDelay(int time){
   for (int i = 0 ; i < time; i++) __delay_ms(50);
}

// Program entry point
void main() {

    //Reloj si tiene oscilador
   OSCCON = 0b01101000; //Oscilador interno configurado a 4Mhz  
    
    OpenI2C(MASTER, SLEW_OFF);
    LCD_init(LCD_01_ADDRESS); 
    KP_init();
    


    unsigned int counter = 0;
    LCD_putcmd(LCD_01_ADDRESS, LCD_CLEAR,1);
      
    while(1) {

      riksFactors();

      longDelay(10);  

      

    } // while(1)
} // main()
