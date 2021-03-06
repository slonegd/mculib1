#pragma once

    #include "RCC_ral.h"
    #include "FLASH_ral.h"
    #include "GPIO_ral.h"
    #include "DMA_ral.h"
    #include "TIM_ral.h"
    #include "ADC_ral.h"
    #include "SysTick_ral.h"
#if defined(STM32F030x6)
    #include "SPI_ral.h"
#elif defined(STM32F405xx)
    #include "USART_ral.h"
#endif


#define MAKE_VAR(name) volatile auto name##_d = (name*) name::Base

volatile auto RCC_d = (RCC_t*) RCC;
volatile auto GPIOA_d = (GPIO_t*) GPIOA;
volatile auto GPIOB_d = (GPIO_t*) GPIOB;
volatile auto GPIOC_d = (GPIO_t*) GPIOC;
volatile auto GPIOD_d = (GPIO_t*) GPIOD;
volatile auto GPIOF_d = (GPIO_t*) GPIOF;
volatile auto FLASH_d = (FLASH_t*) FLASH;
MAKE_VAR(DMA1);
MAKE_VAR(TIM1);
MAKE_VAR(TIM3);
MAKE_VAR(ADC1);
volatile auto SysTick_d = (SysTick_t*) SysTick;
#if defined(STM32F030x6)
    MAKE_VAR(SPI1);
    MAKE_VAR(DMA1channel1);
    MAKE_VAR(DMA1channel2);
    MAKE_VAR(DMA1channel3);
    MAKE_VAR(DMA1channel4);
    MAKE_VAR(DMA1channel5);
#elif defined(STM32F405xx)
    volatile auto GPIOE_d = (GPIO_t*) GPIOE;
    MAKE_VAR(TIM2);
    MAKE_VAR(TIM4);
    MAKE_VAR(TIM5);
    MAKE_VAR(TIM8);
    volatile auto USART1_d = (USART_t*) USART1;
    volatile auto USART2_d = (USART_t*) USART2;
    volatile auto USART3_d = (USART_t*) USART3;
    volatile auto USART6_d = (USART_t*) USART6;
    MAKE_VAR(ADC2);
    MAKE_VAR(ADC3);
    MAKE_VAR(DMA1stream0);
    MAKE_VAR(DMA1stream1);
    MAKE_VAR(DMA1stream2);
    MAKE_VAR(DMA1stream3);
    MAKE_VAR(DMA1stream4);
    MAKE_VAR(DMA1stream5);
    MAKE_VAR(DMA1stream6);
    MAKE_VAR(DMA1stream7);
    MAKE_VAR(DMA2stream0);
    MAKE_VAR(DMA2stream1);
    MAKE_VAR(DMA2stream2);
    MAKE_VAR(DMA2stream3);
    MAKE_VAR(DMA2stream4);
    MAKE_VAR(DMA2stream5);
    MAKE_VAR(DMA2stream6);
    MAKE_VAR(DMA2stream7);
    MAKE_VAR(DMA2);
#endif

#undef MAKE_VAR

inline void makeDebugVar (void)
{
    RCC_d->CR_t::bits.dcb1 = 0;
    FLASH_d->makeDebugVar();
    GPIOA_d->BSRR_t::reg = 0;
    GPIOB_d->BSRR_t::reg = 0;
    GPIOC_d->BSRR_t::reg = 0;
    // почему то с ним не работает ЭО86
    // GPIOD_d->BSRR_t::reg = 0;
    GPIOF_d->BSRR_t::reg = 0;
    DMA1_d->makeDebugVar();
    TIM1_d->makeDebugVar();
    TIM3_d->makeDebugVar();
    ADC1_d->makeDebugVar();
    SysTick_d->VAL_t::reg = 0;
#if defined(STM32F030x6)
    SPI1_d->makeDebugVar();
    DMA1channel1_d->makeDebugVar();
    DMA1channel2_d->makeDebugVar();
    DMA1channel3_d->makeDebugVar();
    DMA1channel4_d->makeDebugVar();
    DMA1channel5_d->makeDebugVar();
#elif defined(STM32F405xx)
    GPIOE_d->BSRR_t::reg = 0;
    TIM2_d->makeDebugVar();
    TIM4_d->makeDebugVar();
    TIM5_d->makeDebugVar();
    TIM8_d->makeDebugVar();
    USART1_d->CR1_t::bits.dcb1 = 0;
    USART2_d->CR1_t::bits.dcb1 = 0;
    USART3_d->CR1_t::bits.dcb1 = 0;
    USART6_d->CR1_t::bits.dcb1 = 0;
    ADC2_d->makeDebugVar();
    ADC3_d->makeDebugVar();
    DMA1stream0_d->makeDebugVar();
    DMA1stream1_d->makeDebugVar();
    DMA1stream2_d->makeDebugVar();
    DMA1stream3_d->makeDebugVar();
    DMA1stream4_d->makeDebugVar();
    DMA1stream5_d->makeDebugVar();
    DMA1stream6_d->makeDebugVar();
    DMA1stream7_d->makeDebugVar();
    DMA2stream0_d->makeDebugVar();
    DMA2stream1_d->makeDebugVar();
    DMA2stream2_d->makeDebugVar();
    DMA2stream3_d->makeDebugVar();
    DMA2stream4_d->makeDebugVar();
    DMA2stream5_d->makeDebugVar();
    DMA2stream6_d->makeDebugVar();
    DMA2stream7_d->makeDebugVar();
    DMA2_d->makeDebugVar();

#endif

}


#undef MAKE_VAR