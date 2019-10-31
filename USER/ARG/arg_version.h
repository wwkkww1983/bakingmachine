#ifndef __ARG_VERSION__
#define __ARG_VERSION__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


#define MAIN_VERSION    0
#define SECOND_VERSION  2
#define IS_RELEASE      0


/*
 * VERSION LOG 
 * 
 * V0.1 基本框架
 * V0.2 完成了注水逻辑 温控方法 还剩余与上位机交互，温控APP逻辑算法
 * 
 * 
 */

void get_version_str(uint8_t * str,uint16_t len);

#endif