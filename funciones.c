#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>   // for sprintf()
#include "lcd.h"
char LCD_01_ADDRESS = 0x27;     // default address
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
            LCD_goto(LCD_01_ADDRESS,2,1);
            LCD_puts(LCD_01_ADDRESS, arreglo);
            contador++;
            
        }
        else
        {           
            LCD_goto(LCD_01_ADDRESS,2,1);
            LCD_puts(LCD_01_ADDRESS, arreglo);
            break;
        }
        
        
        
    }
    
    number = (unsigned long int)atoi(arreglo);  
    return number;
}

void riksFactors(){
    unsigned char text[80];  
    unsigned long int edad=0,estatura=0,peso=0,gender=0,smoke=0,parents=0,systolic=0,diastolic=0;
//    LCD_putcmd(LCD_01_ADDRESS, LCD_CLEAR,1);
    lcdClear();
    //edad
    LCD_goto(LCD_01_ADDRESS,1,1);
    LCD_puts(LCD_01_ADDRESS,"Teclee edad" ); 
    edad = keyNumber();
    lcdClear();
    //peso
    LCD_goto(LCD_01_ADDRESS,1,1);
    LCD_puts(LCD_01_ADDRESS,"Teclee peso en kg" ); 
    peso = keyNumber();
    lcdClear();
    //estatura
    LCD_goto(LCD_01_ADDRESS,1,1);
    LCD_puts(LCD_01_ADDRESS,"Teclee estatura(cm)" ); 
    estatura = keyNumber();
    lcdClear();
    //genero
    LCD_goto(LCD_01_ADDRESS,1,1);
    LCD_puts(LCD_01_ADDRESS,"genero 0 H 1 M" ); 
    gender = keyNumber();
    lcdClear();
    //fuma
    LCD_goto(LCD_01_ADDRESS,1,1);
    LCD_puts(LCD_01_ADDRESS,"Fuma? no 0 si 1" ); 
    smoke = keyNumber();
    lcdClear();
    //padres hipertensos
    LCD_goto(LCD_01_ADDRESS,1,1);
    LCD_puts(LCD_01_ADDRESS,"padres hiper? no 0  si  1 " ); 
    parents = keyNumber();
    lcdClear();
    //imprimir 
    sprintf(text, "%lu,%lu,%lu,%lu,%lu,%lu", edad,peso,estatura,gender,smoke,parents);
    LCD_goto(LCD_01_ADDRESS,2,1);
    LCD_puts(LCD_01_ADDRESS,text ); 
}

void lcdClear(){
//    LCD_goto(LCD_01_ADDRESS,1,1);
//    LCD_puts(LCD_01_ADDRESS,"                                    " ); 
//    LCD_goto(LCD_01_ADDRESS,2,1);
//    LCD_puts(LCD_01_ADDRESS,"                                    " );
//    LCD_goto(LCD_01_ADDRESS,3,1);
//    LCD_puts(LCD_01_ADDRESS,"                                    " );
//    LCD_goto(LCD_01_ADDRESS,4,1);
//    LCD_puts(LCD_01_ADDRESS,"                                    " );
    LCD_putcmd(LCD_01_ADDRESS, LCD_CLEAR,1);
}