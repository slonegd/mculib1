/**
 * RAL над портами ввода вывода
 * в конце файла определяються статические классы,
 * которые необходимы для конкретизации шаблонных классов
 * в pin_hal
 */

#pragma once

#include <stdint.h>
#if defined(STM32F030x6)
#include "stm32f0xx.h"
#elif defined(STM32F405xx)
#include "stm32f4xx.h"
#endif

struct MODER_t
{
   enum Mode_t {
      Input     = 0b00,
      Output    = 0b01,
      Alternate = 0b10,
      Analog    = 0b11
   };
   struct Bits {
      volatile Mode_t MODER0	:2;
      volatile Mode_t MODER1	:2;
      volatile Mode_t MODER2	:2;
      volatile Mode_t MODER3	:2;
      volatile Mode_t MODER4	:2;
      volatile Mode_t MODER5	:2;
      volatile Mode_t MODER6	:2;
      volatile Mode_t MODER7	:2;
      volatile Mode_t MODER8	:2;
      volatile Mode_t MODER9	:2;
      volatile Mode_t MODER10	:2;
      volatile Mode_t MODER11	:2;
      volatile Mode_t MODER12	:2;
      volatile Mode_t MODER13	:2;
      volatile Mode_t MODER14	:2;
      volatile Mode_t MODER15	:2;        
   };
   union {
      volatile Bits bits;
      volatile uint32_t reg;
   };
};

struct OTYPER_t
{
   enum  OutType_t {
      PushPull	= 0b0,
      OpenDrain	= 0b1
   };
   struct Bits {
      volatile OutType_t OT0	:1;
      volatile OutType_t OT1	:1;
      volatile OutType_t OT2	:1;
      volatile OutType_t OT3	:1;
      volatile OutType_t OT4	:1;
      volatile OutType_t OT5	:1;
      volatile OutType_t OT6	:1;
      volatile OutType_t OT7	:1;
      volatile OutType_t OT8	:1;
      volatile OutType_t OT9	:1;
      volatile OutType_t OT10	:1;
      volatile OutType_t OT11	:1;
      volatile OutType_t OT12	:1;
      volatile OutType_t OT13	:1;
      volatile OutType_t OT14	:1;
      volatile OutType_t OT15	:1;
      // Bits 31:16 Reserved, must be kept at reset value.
      uint32_t dcb1	:16;
   };
   union {
      volatile Bits bits;
      volatile uint32_t reg;
   };
};

struct OSPEEDR_t
{
   enum OutSpeed_t {
      Low	    = 0b00,
      Medium	 = 0b01,
      High	    = 0b10,
#if defined(STM32F405xx)
      VeryHigh	 = 0b11
#endif
   };
   struct Bits {
      volatile OutSpeed_t OSPEEDR0	:2;
      volatile OutSpeed_t OSPEEDR1	:2;
      volatile OutSpeed_t OSPEEDR2	:2;
      volatile OutSpeed_t OSPEEDR3	:2;
      volatile OutSpeed_t OSPEEDR4	:2;
      volatile OutSpeed_t OSPEEDR5	:2;
      volatile OutSpeed_t OSPEEDR6	:2;
      volatile OutSpeed_t OSPEEDR7	:2;
      volatile OutSpeed_t OSPEEDR8	:2;
      volatile OutSpeed_t OSPEEDR9	:2;
      volatile OutSpeed_t OSPEEDR10	:2;
      volatile OutSpeed_t OSPEEDR11	:2;
      volatile OutSpeed_t OSPEEDR12	:2;
      volatile OutSpeed_t OSPEEDR13	:2;
      volatile OutSpeed_t OSPEEDR14	:2;
      volatile OutSpeed_t OSPEEDR15	:2;
   };
   union {
      volatile Bits bits;
      volatile uint32_t reg;
   };
};

struct PUPDR_t
{
   enum PullResistor_t {
      No	  = 0b00,
      Up   = 0b01,
      Down = 0b10
   };
   struct Bits {
      volatile PullResistor_t PUPDR0	:2;
      volatile PullResistor_t PUPDR1	:2;
      volatile PullResistor_t PUPDR2	:2;
      volatile PullResistor_t PUPDR3	:2;
      volatile PullResistor_t PUPDR4	:2;
      volatile PullResistor_t PUPDR5	:2;
      volatile PullResistor_t PUPDR6	:2;
      volatile PullResistor_t PUPDR7	:2;
      volatile PullResistor_t PUPDR8	:2;
      volatile PullResistor_t PUPDR9	:2;
      volatile PullResistor_t PUPDR10	:2;
      volatile PullResistor_t PUPDR11	:2;
      volatile PullResistor_t PUPDR12	:2;
      volatile PullResistor_t PUPDR13	:2;
      volatile PullResistor_t PUPDR14	:2;
      volatile PullResistor_t PUPDR15	:2;
   };
   union {
      volatile Bits bits;
      volatile uint32_t reg;
   };
};

struct IDR_t
{
   uint32_t reg;
};

struct ODR_t
{
   uint32_t reg;
};

struct BSRR_t
{
   uint32_t reg;
};

struct LCKR_t
{
   uint32_t reg;
};

struct AFR_t
{
   enum AF {
      _0 = 0b0000, _1, _2, _3, _4, _5, _6, _7,
#if defined(STM32F405xx)
      _8, _9, _10, _11, _12, _13, _14, _15
#endif
   };
   struct Bits {
      volatile AF AFR0    : 4;
      volatile AF AFR1    : 4;
      volatile AF AFR2    : 4;
      volatile AF AFR3    : 4;
      volatile AF AFR4    : 4;
      volatile AF AFR5    : 4;
      volatile AF AFR6    : 4;
      volatile AF AFR7    : 4;
      volatile AF AFR8    : 4;
      volatile AF AFR9    : 4;
      volatile AF AFR10   : 4;
      volatile AF AFR11   : 4;
      volatile AF AFR12   : 4;
      volatile AF AFR13   : 4;
      volatile AF AFR14   : 4;
      volatile AF AFR15   : 4;
   };
   union {
      struct {
         volatile Bits bits;
      };
      volatile uint32_t reg[2];
   };
};

/*
typedef struct
{
__IO uint32_t MODER;    // GPIO port mode register,               Address offset: 0x00
__IO uint32_t OTYPER;   // GPIO port output type register,        Address offset: 0x04
__IO uint32_t OSPEEDR;  // GPIO port output speed register,       Address offset: 0x08
__IO uint32_t PUPDR;    // GPIO port pull-up/pull-down register,  Address offset: 0x0C
__IO uint32_t IDR;      // GPIO port input data register,         Address offset: 0x10
__IO uint32_t ODR;      // GPIO port output data register,        Address offset: 0x14
__IO uint32_t BSRR;     // GPIO port bit set/reset register,      Address offset: 0x18
__IO uint32_t LCKR;     // GPIO port configuration lock register, Address offset: 0x1C
__IO uint32_t AFR[2];   // GPIO alternate function registers,     Address offset: 0x20-0x24
} GPIO_TypeDef;
*/

static constexpr uint32_t MakeMask (MODER_t::Mode_t m, 
                                    OTYPER_t::OutType_t t,
                                    OSPEEDR_t::OutSpeed_t s,
                                    PUPDR_t::PullResistor_t r,
                                    AFR_t::AF af)
{
   return (uint32_t)m | (uint32_t)t << 2 
                      | (uint32_t)s << 3
                      | (uint32_t)r << 5
                      | (uint32_t)af << 7;
}

class GPIO_t : public MODER_t,
            public OTYPER_t,
            public OSPEEDR_t,
            public PUPDR_t,
            public IDR_t,
            public ODR_t,
            public BSRR_t,
            public LCKR_t,
            public AFR_t
//LCKR AFR пока не нужны
{
public:
   using Mode_t = MODER_t::Mode_t;
   using OutType_t = OTYPER_t::OutType_t;
   using OutSpeed_t = OSPEEDR_t::OutSpeed_t;
   using PullResistor_t = PUPDR_t::PullResistor_t;
   using AF = AFR_t::AF;


   enum PinConf_t {
      OutputPushPullLowSpeedNoResistor =
         MakeMask(Mode_t::Output, OutType_t::PushPull, OutSpeed_t::Low, PullResistor_t::No, AF::_0)
   };



protected:
   static constexpr Mode_t     getMode (PinConf_t val)  { return (Mode_t)val; }
   static constexpr OutType_t  getType (PinConf_t val)  { return (OutType_t)(val >> 2); }
   static constexpr OutSpeed_t getSpeed(PinConf_t val)  { return (OutSpeed_t)(val >> 3); }
   static constexpr PullResistor_t getResistor(PinConf_t val) { return (PullResistor_t)(val >> 5); }
   static constexpr AF         getAltFunc(PinConf_t val) { return (AF)(val >> 7); }
};


