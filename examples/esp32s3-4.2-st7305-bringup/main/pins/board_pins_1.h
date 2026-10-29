#pragma once

/* LCD 4 线 SPI：CS=9 RST=10 TE=11 CLK=12 MOSI=13 RS(DC)=14 */
#define BOARD_PIN_LCD_CS          (GPIO_NUM_9)
#define BOARD_PIN_LCD_RST         (GPIO_NUM_10)
#define BOARD_PIN_LCD_TE          (GPIO_NUM_11)
#define BOARD_PIN_LCD_CLK         (GPIO_NUM_12)
#define BOARD_PIN_LCD_MOSI        (GPIO_NUM_13)
#define BOARD_PIN_LCD_RS          (GPIO_NUM_14)

/* 触摸 I2C FT3269 @ 0x38 */
#define BOARD_PIN_TOUCH_SDA       (GPIO_NUM_39)
#define BOARD_PIN_TOUCH_SCL       (GPIO_NUM_40)
#define BOARD_PIN_TOUCH_RST       (GPIO_NUM_41)
#define BOARD_PIN_TOUCH_INT       (GPIO_NUM_42)
