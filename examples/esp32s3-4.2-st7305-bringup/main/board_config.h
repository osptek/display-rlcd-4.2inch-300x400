#pragma once

#include "driver/gpio.h"
#include "board_select.h"

#define BOARD_ENABLE_TOUCH        (BOARD_DEMO == BOARD_DEMO_TOUCH)
#define BOARD_LCD_PATTERN_CYCLE   (BOARD_DEMO == BOARD_DEMO_LCD_LOOP)

#if BOARD_PIN_VARIANT == 1
#include "board_pins_1.h"
#elif BOARD_PIN_VARIANT == 2
#include "board_pins_2.h"
#elif BOARD_PIN_VARIANT == 3
#include "board_pins_3.h"
#elif BOARD_PIN_VARIANT == 4
#include "board_pins_4.h"
#else
#error "未知引脚方案，请在 board_select.h 中选择 1、2、3 或 4"
#endif

#define BOARD_LCD_H_RES           (400)
#define BOARD_LCD_V_RES           (300)

#define BOARD_TOUCH_RST_ACTIVE    (0)
#define BOARD_TOUCH_I2C_HZ        (100000)
#define BOARD_TOUCH_I2C_TIMEOUT_MS (200)

#define BOARD_LCD_SPI_HOST        SPI2_HOST
#define BOARD_LCD_SPI_HZ          (40000000)
#define BOARD_LCD_CS_MANUAL       (0)

/* 单次 SPI 写入上限（整屏 15000 字节需分片） */
#define BOARD_LCD_SPI_CHUNK_BYTES (4096)

/* Waveshare 4.2" ST7305 参考窗口: 400x300 landscape */
#define BOARD_ST7305_COL_START    (0x12)
#define BOARD_ST7305_COL_END      (0x2A)
#define BOARD_ST7305_ROW_START    (0x00)
#define BOARD_ST7305_ROW_END      (0xC7)
#define BOARD_ST7305_B0_PARAM     (0x64)

#define BOARD_ST7305_MADCTL       (0x48)

#define BOARD_ST7305_COL_OFFSET   (0)

#define BOARD_LCD_PATTERN_HOLD_MS (1500)

#define BOARD_TOUCH_CROSS_THICK   (3)
