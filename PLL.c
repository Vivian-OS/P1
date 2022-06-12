/*
 * PLL.c
 *
 *  Created on: 21 oct. 2020
 *      Author: root
 */


#include "../lib/include.h"

extern void Configurar_PLL(uint32_t freq)
//extern void SetSystemClock(uint32_t freq)
{


    // 1. Enable USERCC2 in RCC2
      SYSCTL->RCC2 |= 0x80000000; // RCC2[31]=USERCC2
      // 2. Bypass PLL while initializing
      SYSCTL->RCC2 |= 0x00000800; // RCC2[11]=BYPASS2
      // 3. Set external crystal value and oscillator source for PLL
      SYSCTL->RCC |= (SYSCTL->RCC &= ~0x000007C0) //Clear RCC[10:6]=XTAL
                    + (0x15 << 6);              // 16MHz extern xtal
      SYSCTL->RCC2 &= ~0x00000070;              // RCC2[6:4]=OSCSRC2 000=Main Oscillator
      // 4. Clearning PWRDN to active PLL
      // RCC2[13]=PWRDN 0:The PLL operate normally
      SYSCTL->RCC2 &= ~0x00002000;
      // 5. Set system clock
      // RCC2[30]=DIV400 Select 400MHz(from PLL)
      SYSCTL->RCC2 |= 0x40000000;
      //RCC2[28:21]=SYSDIV2 400MHz/(4+1) = 80MHz

      float x; x=400000000/freq;
      x=x-1;
      freq=lround(x);
      SYSCTL->RCC2 = (SYSCTL->RCC2 & ~0x1FC00000) + ((int)freq << 22);

      // 6. Wait for PLL to lock by polling PLLLRIS
      while( (SYSCTL->RIS & 0x00000040) == 0) {};
      // 7. Set BYPASS to 0, select PLL as the source of system clock
      SYSCTL->RCC2 &= ~0x00000800;


}
