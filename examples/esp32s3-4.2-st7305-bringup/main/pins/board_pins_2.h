#pragma once

/* ---- ST7306 SPI 显示引脚 ----
 * DC=16 RESET=12 CS=15 SCK=14 SDI(MOSI)=13 TE=42 RS=41 */
#define BOARD_PIN_LCD_CS          (GPIO_NUM_15)   // CS
#define BOARD_PIN_LCD_RST         (GPIO_NUM_12)   // RESET
#define BOARD_PIN_LCD_TE          (GPIO_NUM_42)   // TE
#define BOARD_PIN_LCD_CLK         (GPIO_NUM_14)   // SCK
#define BOARD_PIN_LCD_MOSI        (GPIO_NUM_13)   // SDI
#define BOARD_PIN_LCD_RS          (GPIO_NUM_41)   // DC
#define BOARD_PIN_LCD_RS_EXTRA    (GPIO_NUM_16)   // RS（预留）

/* ---- 触摸引脚（暂未实现，先预留） ---- */
#define BOARD_PIN_TOUCH_SDA       (GPIO_NUM_39)   // tp_sda
#define BOARD_PIN_TOUCH_SCL       (GPIO_NUM_38)   // tp_scl
#define BOARD_PIN_TOUCH_RST       (GPIO_NUM_40)   // tp_rst
#define BOARD_PIN_TOUCH_INT       (GPIO_NUM_47)   // tp_int
