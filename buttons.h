/******************************************************************************
 * 
 * Класс работы с кнопками
 * 
 */////////////////////////////////////////////////////////////////////////////

#pragma once

#include "timers.h"
#include "literals.h"


// Types - это список пинов всех кнопок
// inverted = true, если нажатая кнопка даёт 1 на входе
template<bool inverted, class ... Types>
class Buttons
{
public:
   static const uint16_t MinPressed = 10_ms;
   static const uint16_t LongPressed = 1_s;


   Buttons (Timer& timer)
      : pushHandeledFlag(false),
        longPushHandeledFlag(false),
        timer(timer)
   {
      List<Types...>::ClockEnable();
      timer.setTime (100_s); // 100 s просто большое время
   }


   // запускает/останавливает таймер отслеживания времени нажатия
   // должна периодически вызываться
   void operator () ()
   {
      // (Types::IsSet() or ... ); - аналог в 17 стандарте
      bool tmp = inverted ? List<Types...>::IsAnyClear() : List<Types...>::IsAnySet();
      if ( tmp ) {
         timer.start();
      } else {
         timer.stop();
         pushHandeledFlag = false;
         longPushHandeledFlag = false;
      }
   }


   // определяет событие нажатия кнопки (или кнопок если их несколько)
   template<class ... Buttons_> bool push()
   {
      bool tmp;
      if (pushHandeledFlag) {
         tmp = false;
      } else {
         // (Buttons_::IsSet() and ... ); - аналог в 17 стандарте
         tmp = inverted ? List<Buttons_...>::IsAllClear() : List<Buttons_...>::IsAllSet();
         tmp = tmp and (timer.timePassed > MinPressed);
         if (tmp)
            pushHandeledFlag = true;
      }
      return tmp;
   }


   // определяет событие долгого нажатия кнопки (или кнопок если их несколько)
   template<class ... Buttons_> bool longPush()
   {
      bool tmp;
      if (longPushHandeledFlag) {
         tmp = false;
      } else {
         tmp = inverted ? List<Buttons_...>::IsAllClear() : List<Buttons_...>::IsAllSet();
         tmp = tmp and (timer.timePassed > LongPressed);
         if (tmp)
            longPushHandeledFlag = true;
      }
      return tmp;
   }


   // определяет событие нажатия хоть какой-нибудь кнопки
   bool anyPush()
   {
      return (timer.timePassed > MinPressed) and !pushHandeledFlag;
   }


   // блокирует события нажатия кнопок до отпускания
   void blockAllEvents()
   {
      pushHandeledFlag = true;
      longPushHandeledFlag = true;
   }


   // блокирует событиt простого нажатия кнопок до отпускания
   void blockPushEvents()
   {
      pushHandeledFlag = true;
   }



private:
   bool pushHandeledFlag;
   bool longPushHandeledFlag;
   Timer& timer;


   // всю эту рекурсивную бяку можно/нужно заменить на fold expression 17 стандарта
   template<class T, class ... Ts> struct List { 
      static bool IsAnySet()   { return T::IsSet()   or  List<Ts...>::IsAnySet();   }
      static bool IsAnyClear() { return T::IsClear() or  List<Ts...>::IsAnyClear(); }
      static bool IsAllSet()   { return T::IsSet()   and List<Ts...>::IsAllSet();   }
      static bool IsAllClear() { return T::IsClear() and List<Ts...>::IsAllClear(); }
      static void ClockEnable() { T::Port::ClockEnable(); List<Ts...>::ClockEnable(); }
   };
   template<class T> struct List<T> {
      static bool IsAnySet()   { return T::IsSet();   }
      static bool IsAnyClear() { return T::IsClear(); }
      static bool IsAllSet()   { return T::IsSet();   }
      static bool IsAllClear() { return T::IsClear(); }
      static void ClockEnable() { T::Port::ClockEnable(); }
   };


};


