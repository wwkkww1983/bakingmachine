#ifndef __POWER__
#define __POWER__


#include <stdbool.h>
#include <stdint.h>


/*
 * 在此驱动中完全抽象系统的电源特性，其大搞特性如下
 * 
 * 1 MCU是始终工作的，不间断工作，如果出现故障看门狗复位，只要供电MCU一直工作
 * 2 TFT屏的电源是由MCU控制的，电源按键通知MCU，MCU做显示屏的上电操作
 * 
 * 此驱动封装
 * 
 * 1 电源按键事件的捕获
 * 2 电源事件处理
 * 3 LED 亮/灭逻辑
 * 
 * 19.12.19 增补standby休眠模式，按下按键后，屏幕断电，STM32进入待机状态，再次按下按键唤醒MCU
 * 打开屏幕，这样可以对整个系统进行软关机。
 * 
 * 不能进入休眠模式的原因
 * 
 * 1 当单片机处于高阻态的时候
 */

typedef enum{
    lcd_power_off=0,
    lcd_power_on,
}lcd_power_status_t;


void periph_power_init(void);
void periph_power_handle(void);

/*
 * brief : 获得LCD的电源状态
 * return off/on
 */
lcd_power_status_t get_lcd_power_status(void);

/*
 * brief : 提供给外部访问LCD电源的接口
 * pra sw 0:off 1:on
 */
void lcd_power_control_func(bool sw);

/*
 * brief : 关机执行代码，执行此函数相当于点击了一次电源按键
 */
void power_key_press_event_handle(void);
#endif
