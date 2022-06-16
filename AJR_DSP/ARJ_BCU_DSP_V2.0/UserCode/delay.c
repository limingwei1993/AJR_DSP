#include "user_main.h"
/*************************
 * void delay_ns(uint32_t ns)
 * ��ʱns
 * ns��ʱ��
 * ***********************/
void delay_ns(uint32_t ns)
{
  while(ns--);
}

/*************************
 * void delay_us(uint32_t us)
 * ��ʱus
 * us��ʱ��
 * ***********************/
void delay_us(uint32_t us)
{
  static volatile unsigned int delayval;
  delayval = us * 18;   /* 100000 are about 10ms*/
  while(delayval--);
}

/*************************
 * void delay_ms(uint32_t ms)
 * ��ʱms
 * ms��ʱ��
 * ***********************/
void delay_ms(uint32_t ms)
{
  static volatile unsigned int delayval;
  delayval = ms * 18000;   /* 100000 are about 10ms*/
  while(delayval--);
}

