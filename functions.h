#ifndef __functions
#define __functions

//prototypes
void init_PORTF(void);
void config_PORTF(void);
//interrupt SW1
void init_IQ30(void);
void config_IQ30(void);
//NVIC Timer versuch
void init_NVIC(void);
void config_SysTick(void);

//TIMER VERSUCH
void init_TIMER5(void);

void delay();

#endif