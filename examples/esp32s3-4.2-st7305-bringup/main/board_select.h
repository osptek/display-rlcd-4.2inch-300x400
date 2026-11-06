#pragma once

/*
 * 只在这个文件里选择板子和要播放的 demo。
 * 引脚表在 pins/board_pins_1.h 到 pins/board_pins_4.h。
 */

/* 板子：1、2、3、4 */
#define BOARD_PIN_VARIANT         (1)

/* 全部 demo，把 BOARD_DEMO 改成下面其中一项 */
#define BOARD_DEMO_LCD_LOOP       (1)  /* 循环：全黑、全白、4/8/16/32/64 棋盘、边框 */
#define BOARD_DEMO_LCD_ONCE       (2)  /* 一轮：全黑、全白、横条、竖条、8/16 棋盘 */
#define BOARD_DEMO_TOUCH          (3)  /* 触摸十字光标 */
#define BOARD_DEMO_NUMBER         (4)  /* 循环显示 1 到 10 */

#define BOARD_DEMO                BOARD_DEMO_TOUCH
