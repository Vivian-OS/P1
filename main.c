

/**
 * main.c
 */
#include "lib/include.h"/*

#define SYSCTL_RCC2_USERCC2     0x80000000  // Use RCC2
#define SYSCTL_RCC2_DIV400      0x40000000  // Divide PLL as 400 MHz vs. 200
#define SYSCTL_RCC2_SYSDIV2_M   0x0FC00000  // System Clock Divisor 2
*/
int main(void)
{
    Configurar_PLL(_50MHz);

char Dato;
Configurar_UART4(115200);
readChar();

writeChar('V');

	while(1){
	}

}
