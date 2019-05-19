#include "funciones.h"
#include <stdlib.h>
#include "lcd.h"
char LCD_01_ADDRESS = 0x40;     // default address
unsigned long int keyNumber(){
    unsigned char arreglo[20];
    unsigned int contador =0,i=0;
    unsigned long int number;
    for(i;i<10;i++){
        arreglo[i]=0;
    }
    unsigned char tecla;
    while(1){
        tecla = KP_Readbutton();
        
        if (tecla  != '+'){
            arreglo[contador]= tecla;            
            LCD_goto(LCD_01_ADDRESS,1,1);
            LCD_puts(LCD_01_ADDRESS, arreglo);
            contador++;
            
        }
        else
        {           
            LCD_goto(LCD_01_ADDRESS,1,1);
            LCD_puts(LCD_01_ADDRESS, arreglo);
            break;
        }
        
        
        
    }
    
    number = (unsigned long int)atoi(arreglo);  
    return number;
}
