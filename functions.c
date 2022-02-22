#include "functions.h"
#include "lm4f120h5qr.h"
#include "io.h"


//Interrupt GPIO PORT F
void GPIOF_IRQ30( void )
{
  //Interrupt Service Routine
  GPIO_PORTF_DATA_R = 0;
  for(int l = 0; l < 3; l++)
  {
  GPIO_PORTF_DATA_BITS_R[LED_RED] |= LED_RED;
  delay(500);
  GPIO_PORTF_DATA_BITS_R[LED_RED] &= ~LED_RED;
  delay(500);
  }
  GPIO_PORTF_DATA_R = 0;
}

void init_PORTF(void)
  {
  SYSCTL_RCGCGPIO_R |= PORTF; // CLOCK TO PORTF
  GPIO_PORTF_DATA_R = 0; //initialisiere (alles aus) bei mir initialisiert er nicht mit NULL ... warum auch immer
  }   

void config_PORTF(void)
  {
  
  GPIO_PORTF_DEN_R |= SW1 | LED_GREEN | LED_RED; //DIGITAL MODUS FREISCHALTEN FÜR
  GPIO_PORTF_DIR_R |= LED_GREEN | LED_RED;       //DIRECTION SETZEN FÜR DIE JEWEILIGEN PINS AN PORTF
  GPIO_PORTF_DIR_R &= ~SW1;                      //SW1 als EINGANG
  GPIO_PORTF_PUR_R |= SW1;                       //aktiviere Pullup widerstand für SW1
  
  }

void config_IQ30(void)
  {
    GPIO_PORTF_IM_R = 0;     //CLEAR IM FIELD
    GPIO_PORTF_IS_R |= SW1;  // 1 The level on the corresponding pin is detected (level-sensitive).
    GPIO_PORTF_RIS_R = 0;    // c. Clear the GPIORIS register.
    GPIO_PORTF_IM_R |= SW1;  //d. Unmask the port by setting the IME field in the GPIOIM register.
  }

void init_NVIC(void)
  {
 NVIC_EN0_R |= (1<<30); //Interrupt für PORTF aktiviert
  }

void delay(int time) 
  {
    for(int i = 0; i < time; i++)
    {
      for(int k = 0; k < 3580; k++)
      {} //NOPS 1ms
    }
  }

void config_SysTick(void)
  {
  //TIMER MIT SYSTICK 
  
/*
NVIC_ST_RELOAD_R = 16000000-1;
NVIC_ST_CURRENT_R = 0;
NVIC_ST_CTRL_R = 0;
NVIC_ST_CTRL_R |= (1<<0) | (1<<1) | (1<<2); //ENABLE  SYSTICK // USE SYSTEMCLOCK (16MHz) // 1 The SysTick timer has counted to 0 since the last time this bit was read
NVIC_ST
*/
  }
void init_TIMER5(void)
{
SYSCTL_RCGCTIMER_R |= (1<<5);

}