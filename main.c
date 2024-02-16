/*****************************************************************************
  Main Source File
  Company:
    DTU SPACE.
  File Name:
    main.c
  Summary:
    This file contains the "main" function for a project.
  Description:
    This file contains the "main" function for a project.
  Version 1.0
      
*****************************************************************************/

/*****************************************************************************
*  The Idea is to use this device as a portexpander controlled over SPI. The
*  reason for this is, that the ATmega128 comes in a RAD-HARD version, but
*  the popular MCP23S17 does NOT.
*  This first test is not to have the SPI running but to learn about the
*  ATmega128. The used board is a very small very cheap purchased from eBay.
*****************************************************************************/

#include <xc.h>
#include <avr/sfr_defs.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 8000000UL  //  CPU frequency, used for delay


/* My vars */
unsigned int tid1 = 0;
unsigned int tid2 = 0;  // Is this gonna be used ?
unsigned int i = 0;
unsigned int mi = 0;
unsigned short m[48] = {0, 0,   0,  0,   0,  0,
                        0, 0,  24, 60,  62, 31,  31, 62, 60, 24,
                        0, 0,  65, 65, 127, 65,  65,
                        0, 0,  24, 60,  62, 31,  31, 62, 60, 24,
                        0, 0, 127, 32,  16, 32, 127,
                        0, 0,   0,  0,   0,  0,   0,  0};



int main(void)
{
  DDRB = 0xFF;
  DDRE = 0xFF;


  while(1)
  {
    for (tid1 = 0; tid1 < 50; tid1++)
    {
    for (mi = 0; mi < 8; mi++)
    {
      PORTB = 0x00;
      PORTE = 0x00;
      switch (mi)
      {
        case 0 : PORTE = 0x80;
                 break; 
        case 1 : PORTE = 0x40;
                 break; 
        case 2 : PORTE = 0x20;
                 break; 
        case 3 : PORTE = 0x10;
                 break; 
        case 4 : PORTE = 0x08;
                 break; 
        case 5 : PORTE = 0x04;
                 break; 
        case 6 : PORTE = 0x02;
                 break; 
        case 7 : PORTE = 0x01;
                 break; 
      }
      if (i > 40) mi = mi - i;
      if (m[i + mi] & 0x80)
        PORTB |= 0x80;
      else
        PORTB &= 0x7F;
      if (m[i + mi] & 0x40)
        PORTB |= 0x40;
      else
        PORTB &= 0xEB;
      if (m[i + mi] & 0x20)
        PORTB |= 0x20;
      else
        PORTB &= 0xDF;
      if (m[i + mi] & 0x10)
        PORTB |= 0x10;
      else
        PORTB &= 0xEF;
      if (m[i + mi] & 0x08)
        PORTB |= 0x08;
      else
        PORTB &= 0xF7;
      if (m[i + mi] & 0x04)
        PORTB |= 0x04;
      else
        PORTB &= 0xFB;
      if (m[i + mi] & 0x02)
        PORTB |= 0x02;
      else
        PORTB &= 0xFD;
      if (m[i + mi] & 0x01)
        PORTB |= 0x01;
      else
        PORTB &= 0xFE;
      _delay_us(250);
    }
    }
    i++;
    if (i == 40) i = 0;
  }
    
} // main() ends
