/*

7. Program the GPIOIS, GPIOIBE, GPIOEV, and GPIOIM registers to configure the type, event,
and mask of the interrupts for each port.



Note: To prevent false interrupts, the following steps should be taken when re-configuring
GPIO edge and interrupt sense registers:


a. Mask the corresponding port by clearing the IME field in the GPIOIM register.
b. Configure the IS field in the GPIOIS register and the IBE field in the GPIOIBE
register.
c. Clear the GPIORIS register.
d. Unmask the port by setting the IME field in the GPIOIM register.




Interrupt Tasterabfrage (TM4C123GH6PM)

*/

#include "io.h"
#include "lm4f120h5qr.h"
#include "functions.h"


int main()
{
  init_PORTF();
  config_PORTF();
  init_NVIC();
  config_IQ30();
  
  while(1)
  {
    GPIO_PORTF_DATA_BITS_R[LED_GREEN] = LED_GREEN; //STATUS LED GRÜN WENN INTERRUPT KOMMT ROT (hier mit array zugriff)
    
  }
  return 0;
}
