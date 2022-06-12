/*
 * UART.c
 *
 *  Created on: 13 may 2022
 *      Author: dell
 */

#include "../lib/include.h"

extern void Configurar_UART4(uint32_t Baudrate)
{
SYSCTL -> RCGCUART = (1<<4);   //pag. 344
SYSCTL-> RCGCGPIO |= (1<<2); //PAG 340                   Habilitar puerto C

       GPIOC->DIR = (1<<5)| (0<<4); // PAG 663                 Entrada(0)/Salida(1)
       GPIOC->AFSEL = (1<<5)| (1<<4); //PAG 672               Funcion alternativa
       GPIOC->PCTL  = (GPIOC->PCTL&0xFF00FFFF)| 0x00110000;
       GPIOC ->DEN = (1<<5)|(1<<4);


       UART4-> CTL |= (0<<9)|(0<<8)|(0<<0);

        //IBRD = 50000000 / (16 * 115,200) = 27.12673    // pag 903                             //50 000 000 pidió el profe
       //FBRD = integer(0.12673 * 64 + 0.5) = 8.6

     UART4->IBRD = 27;
    UART4->FBRD = 9;



       UART4-> LCRH = (0x3<<5)|(0<<4);
       UART4->CC = 0x0;
       UART4->CTL = (1<<9)|(1<<8)|(1<<0);
}

       extern char readChar(void)
       {
           int v;
             char c;
             while ((UART4->FR & (1<<4)) !=0 );      //pag 911
             v = UART4->DR & 0xFF;                   //pag 906
             c = v;
             return c;

          }

       extern void writeChar(char c)
       {

           while((UART4->FR &(1<<5))!=0);
           UART4->DR = c;
         //  writeChar('V');

       }/*
       extern void writeString(char c * S){
           while(*S){
               writeChar(UART, *(S++));
           }
       }
*/
