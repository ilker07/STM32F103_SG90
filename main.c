#include "stm32f10x.h"                  // Device header
#include "delay.h"



unsigned int a=0;
void pin_init(void);

void timer1pwm_init(void);



int main()
   
{
   delay_init();
   pin_init(); 
   
   timer1pwm_init();
   
  
   
   while(1)
   {
      
		 /*
		 a++;
		 
		 if(a==1)
			 TIM1->CCR1 = 1800;
		  else if(a==2)
				 TIM1->CCR1 = 2880;
      else if(a==3)
			{
			 TIM1->CCR1 = 3600;
				
			}
			else if(a==4)
			{
			TIM1->CCR1 = 7200;
				a=0;
			
			}
		 */
    
		
		
		a+=1800;
		TIM1->CCR1 =a;
		if(a >=3780)
		a=0;
  
	
	   
      
    delay_ms(500);
			
      
      
   }
   
   
}
void pin_init()
{
   RCC->APB2ENR |=1<<11; //TIMER1 AKTIF.
   RCC->APB2ENR |=1<<3;//B portu aktif.
    RCC->APB2ENR |=1<<0;//Alternatif fonksiyon enable.
   
   
   
    GPIOB->CRH=0;
    GPIOB->CRH =0x00B00000;//Alternatif function push pull.    
       
}


 
   

void timer1pwm_init()
{
   
   
   TIM1->CCMR1  |=1<<3; //Output Compare 1 preload enable
   TIM1->CCER   |=1<<2;//Capture/Compare 1 output enable
   
   
   
   TIM1->CCMR1  |=1<<5;    //PWM1
   TIM1->CCMR1  |=1<<6;   //PWM1
   
      
   TIM1->RCR =0;
   TIM1->BDTR |= 0x8000;
   TIM1->CNT = 0;
   
   
   
   
   TIM1->PSC =39;   // 72 000 000 / 36 000 *40  = 1000 HZ  50 HZ ICIN.
   TIM1->ARR =35999;
 //TIM1->CCR1=1800;   // yuzde 5 i 1 ms       3600 /2   2880 ve 3600
   TIM1->CCR1=1;  //900
   
   TIM1->CR1 |=1<<0; //Counter Bit.
  

}
