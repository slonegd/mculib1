#pragma once

#include "stm32f4xx.h"

/*
typedef struct
{
  __IO uint32_t SR;     // ADC status register,                         Address Offset: 0x00
  __IO uint32_t CR1;    // ADC control register 1,                      Address Offset: 0x04
  __IO uint32_t CR2;    // ADC control register 2,                      Address Offset: 0x08
  __IO uint32_t SMPR1;  // ADC sample time register 1,                  Address Offset: 0x0C
  __IO uint32_t SMPR2;  // ADC sample time register 2,                  Address Offset: 0x10
  __IO uint32_t JOFR1;  // ADC injected channel data Offset register 1, Address Offset: 0x14
  __IO uint32_t JOFR2;  // ADC injected channel data Offset register 2, Address Offset: 0x18
  __IO uint32_t JOFR3;  // ADC injected channel data Offset register 3, Address Offset: 0x1C
  __IO uint32_t JOFR4;  // ADC injected channel data Offset register 4, Address Offset: 0x20
  __IO uint32_t HTR;    // ADC watchdog higher threshold register,      Address Offset: 0x24
  __IO uint32_t LTR;    // ADC watchdog lower threshold register,       Address Offset: 0x28
  __IO uint32_t SQR1;   // ADC regular sequence register 1,             Address Offset: 0x2C
  __IO uint32_t SQR2;   // ADC regular sequence register 2,             Address Offset: 0x30
  __IO uint32_t SQR3;   // ADC regular sequence register 3,             Address Offset: 0x34
  __IO uint32_t JSQR;   // ADC injected sequence register,              Address offset: 0x38
  __IO uint32_t JDR1;   // ADC injected data register 1,                Address offset: 0x3C
  __IO uint32_t JDR2;   // ADC injected data register 2,                Address offset: 0x40
  __IO uint32_t JDR3;   // ADC injected data register 3,                Address offset: 0x44
  __IO uint32_t JDR4;   // ADC injected data register 4,                Address offset: 0x48
  __IO uint32_t DR;     // ADC regular data register,                   Address offset: 0x4C
} ADC_TypeDef;
*/

namespace ADC_ral {

   struct SR_t {
      enum { Offset = 0x00 };
      struct Bits {
         // Bit 0 AWD: Analog watchdog flag
         volatile bool AWD       :1;
         // Bit 1 EOC: Regular channel end of conversion
         volatile bool EOC       :1;
         // Bit 2 JEOC: Injected channel end of conversion
         volatile bool JEOC      :1;
         // Bit 3 JSTRT: Injected channel start flag
         volatile bool JSTRT     :1;
         // Bit 4 STRT: Regular channel start flag
         volatile bool STRT      :1;
         // Bit 5 OVR: Overrun
         volatile bool OVR       :1;
         // Bits 31:6 Reserved, must be kept at reset value.
         volatile uint32_t res1  :26;
      };
      union {
         volatile Bits bits;
         volatile uint32_t reg;
      };
   };



   struct CR_t {
      static const uint8_t Offset = 0x04;
      enum Resolution {
         _12bit  = 0b00,
         _10bit  = 0b01,
         _8bit   = 0b10,
         _6bit   = 0b11
      };
      struct Bits {
         // Bits 4:0 AWDCH[4:0]: Analog watchdog channel select bits
         volatile uint32_t AWDCH     :5;
         // Bit 5 EOCIE: Interrupt enable for EOC
         volatile bool EOCIE         :1;
         // Bit 6 AWDIE: Analog watchdog interrupt enable
         volatile bool AWDIE         :1;
         // Bit 7 JEOCIE: Interrupt enable for injected channels
         volatile bool JEOCIE        :1;
         // Bit 8 SCAN: Scan mode
         volatile bool SCAN          :1;
         // Bit 9 AWDSGL: Enable the watchdog on a single channel in scan mode
         volatile uint32_t AWDSGL    :1;
         // Bit 10 JAUTO: Automatic injected group conversion
         volatile bool JAUTO         :1;
         // Bit 11 DISCEN: Discontinuous mode on regular channels
         volatile bool DISCEN        :1;
         // Bit 12 JDISCEN: Discontinuous mode on injected channels
         volatile bool JDISCEN       :1;
         // Bits 15:13 DISCNUM[2:0]: Discontinuous mode channel count
         volatile uint32_t DISCNUM   :3;
         // Bits 21:16 Reserved, must be kept at reset value.
         volatile uint32_t res1      :6;
         // Bit 22 JAWDEN: Analog watchdog enable on injected channels
         volatile bool JAWDEN        :1;
         // Bit 23 AWDEN: Analog watchdog enable on regular channels
         volatile bool AWDEN         :1;
         // Bits 25:24 RES[1:0]: Resolution
         volatile Resolution RES     :2;
         // Bit 26 OVRIE: Overrun interrupt enable
         volatile bool OVRIE         :1;
         // Bits 31:27 Reserved, must be kept at reset value.
         volatile uint32_t res2      :5;
      };
      union {
         volatile Bits bits;
         volatile uint32_t reg;
      };
   };



   struct CR2_t {
      static const uint8_t Offset = 0x08;
      enum EventsInjected {
         iTimer1CC4 = 0b0000,
         iTimer1TRGO,
         iTimer2CC1, iTimer2TRGO,
         iTimer3CC2, iTimer3CC4, 
         iTimer4CC1, iTimer4CC2, iTimer4CC3, iTimer4TRGO,
         iTimer5CC4, iTimer5TRGO,
         iTimer8CC2, iTimer8CC3, iTimer8CC4,
         iEXTI15
      };
      enum TriggerEn {
         Disable = 0b00,
         RisingEdge,
         FallingEdge,
         BothEdge
      };
      enum EventsRegular {
         rTimer1CC1 = 0b0000,
         rTimer1CC2, rTimer1CC3,
         rTimer2CC2, rTimer2CC3, rTimer2CC4, rTimer2TRGO,
         rTimer3CC1, rTimer3TRGO,
         rTimer4CC4,
         rTimer5CC1, rTimer5CC2, rTimer5CC3,
         rTimer8CC1, rTimer8TRG0,
         rEXTI11
      };
      struct Bits {
         // Bit 0 ADON: A/D Converter ON / OFF
         volatile bool ADON              :1;
         // Bit 1 CONT: Continuous conversion
         volatile bool CONT              :1;
         // Bit 8 DMA: Direct memory access mode (for single ADC mode)
         volatile bool DMA               :1;
         // Bit 9 DDS: DMA disable selection (for single ADC mode)
         volatile bool DDS               :1;
         // Bit 10 EOCS: End of conversion selection
         volatile bool EOCS              :1;
         // Bit 11 ALIGN: Data alignment
         volatile uint32_t ALIGN         :1;
         // Bits 15:12 Reserved, must be kept at reset value.
         volatile uint32_t res1          :4;
         // Bits 19:16 JEXTSEL[3:0]: External event select for injected group
         volatile EventsInjected JEXTSEL :4;
         // Bits 21:20 JEXTEN: External trigger enable for injected channels
         volatile TriggerEn JEXTEN       :2;
         // Bit 22 JSWSTART: Start conversion of injected channels
         volatile bool JSWSTART          :1;
         // Bit 23 Reserved, must be kept at reset value.
         volatile uint32_t res2          :1;
         // Bits 27:24 EXTSEL[3:0]: External event select for regular group
         volatile EventsRegular EXTSEL   :4;
         // Bits 29:28 EXTEN: External trigger enable for regular channels
         volatile TriggerEn EXTEN        :2;
         // Bit 30 SWSTART: Start conversion of regular channels
         volatile bool SWSTART           :1;
         // Bit 31 Reserved, must be kept at reset value.
         volatile bool res3              :1;
      };
      union {
         volatile Bits bits;
         volatile uint32_t reg;
      };
   };



   struct SMPR1_t {
      static const uint8_t Offset = 0x0C;
      union {
         volatile uint32_t reg;
      };
   };



   struct SMPR2_t {
      static const uint8_t Offset = 0x10;
      union {
         volatile uint32_t reg;
      };
   };



   struct JOFR1_t {
      static const uint8_t Offset = 0x14;
      union {
         volatile uint32_t reg;
      };
   };



   struct JOFR2_t {
      static const uint8_t Offset = 0x18;
      union {
         volatile uint32_t reg;
      };
   };



   struct JOFR3_t {
      static const uint8_t Offset = 0x1C;
      union {
         volatile uint32_t reg;
      };
   };



   struct JOFR4_t {
      static const uint8_t Offset = 0x20;
      union {
         volatile uint32_t reg;
      };
   };



   struct HTR_t {
      static const uint8_t Offset = 0x24;
      union {
         volatile uint32_t reg;
      };
   };



   struct LTR_t {
      static const uint8_t Offset = 0x28;
      union {
         volatile uint32_t reg;
      };
   };



   struct SQR1_t {
      static const uint8_t Offset = 0x2C;
      union {
         volatile uint32_t reg;
      };
   };



   struct SQR2_t {
      static const uint8_t Offset = 0x30;
      union {
         volatile uint32_t reg;
      };
   };



   struct SQR3_t {
      static const uint8_t Offset = 0x34;
      union {
         volatile uint32_t reg;
      };
   };



   struct JSQR_t {
      static const uint8_t Offset = 0x38;
      union {
         volatile uint32_t reg;
      };
   };



   struct JDR1_t {
      static const uint8_t Offset = 0x3C;
      union {
         volatile uint32_t reg;
      };
   };



   struct JDR2_t {
      static const uint8_t Offset = 0x40;
      union {
         volatile uint32_t reg;
      };
   };



   struct JDR3_t {
      static const uint8_t Offset = 0x44;
      union {
         volatile uint32_t reg;
      };
   };



   struct JDR4_t {
      static const uint8_t Offset = 0x48;
      union {
         volatile uint32_t reg;
      };
   };



   struct DR_t {
      static const uint8_t Offset = 0x4C;
      union {
         volatile uint32_t reg;
      };
   };

} // namespace ADC_ral {