#include "board_lcd_demo.h"

#include "board_config.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "st7305_lcd.h"

static const char *TAG = "lcd_demo";

typedef enum {
    PAT_FULL_BLACK = 0,
    PAT_FULL_WHITE,
    PAT_HSTRIPE_8,
    PAT_VSTRIPE_8,
    PAT_CHECKER_8,
    PAT_CHECKER_16,
    PAT_COUNT,
} demo_pattern_t;

static const char *pattern_name(demo_pattern_t p)
{
    switch (p) {
    case PAT_FULL_BLACK: return "FULL_BLACK";
    case PAT_FULL_WHITE: return "FULL_WHITE";
    case PAT_HSTRIPE_8:  return "HSTRIPE_8";
    case PAT_VSTRIPE_8:  return "VSTRIPE_8";
    case PAT_CHECKER_8:  return "CHECKER_8";
    case PAT_CHECKER_16: return "CHECKER_16";
    default: return "?";
    }
}

static void draw_full_black(void)
{
    st7305_lcd_fill(0xFF);
}

static void draw_full_white(void)
{
    st7305_lcd_fill(0x00);
}

static void draw_hstripes(uint16_t period)
{
    const uint16_t w = BOARD_LCD_H_RES;
    const uint16_t h = BOARD_LCD_V_RES;
    const uint16_t half = period / 2;

    st7305_lcd_fill(0x00);
    if (period == 0 || half == 0) {
        return;
    }

    for (uint16_t y = 0; y < h; y += period) {
        uint16_t hh = half;
        if (y + hh > h) {
            hh = h - y;
        }
        st7305_lcd_fill_rect(0, y, w, hh, ST7305_COLOR_BLACK);
    }
}

static void draw_vstripes(uint16_t period)
{
    const uint16_t w = BOARD_LCD_H_RES;
    const uint16_t h = BOARD_LCD_V_RES;
    const uint16_t half = period / 2;

    st7305_lcd_fill(0x00);
    if (period == 0 || half == 0) {
        return;
    }

    for (uint16_t x = 0; x < w; x += period) {
        uint16_t ww = half;
        if (x + ww > w) {
            ww = w - x;
        }
        st7305_lcd_fill_rect(x, 0, ww, h, ST7305_COLOR_BLACK);
    }
}

static void draw_checker(uint16_t cell)
{
    const uint16_t w = BOARD_LCD_H_RES;
    const uint16_t h = BOARD_LCD_V_RES;

    st7305_lcd_fill(0x00);
    if (cell == 0) {
        return;
    }

    const uint16_t cols = (w + cell - 1U) / cell;
    const uint16_t rows = (h + cell - 1U) / cell;

    for (uint16_t row = 0; row < rows; ++row) {
        for (uint16_t col = 0; col < cols; ++col) {
            if ((row + col) % 2) {
                continue;
            }
            uint16_t x = col * cell;
            uint16_t y = row * cell;
            uint16_t cw = (x + cell > w) ? (w - x) : cell;
            uint16_t ch = (y + cell > h) ? (h - y) : cell;
            st7305_lcd_fill_rect(x, y, cw, ch, ST7305_COLOR_BLACK);
        }
    }
}

static void render_pattern(demo_pattern_t p)
{
    switch (p) {
    case PAT_FULL_BLACK:
        draw_full_black();
        break;
    case PAT_FULL_WHITE:
        draw_full_white();
        break;
    case PAT_HSTRIPE_8:
        draw_hstripes(8);
        break;
    case PAT_VSTRIPE_8:
        draw_vstripes(8);
        break;
    case PAT_CHECKER_8:
        draw_checker(8);
        break;
    case PAT_CHECKER_16:
        draw_checker(16);
        break;
    default:
        draw_full_white();
        break;
    }
}

void board_lcd_demo_run_once(void)
{
    ESP_LOGI(TAG, "LCD pattern sequence once, hold=%dms", BOARD_LCD_PATTERN_HOLD_MS);
    vTaskDelay(pdMS_TO_TICKS(200));

    for (demo_pattern_t idx = PAT_FULL_BLACK; idx < PAT_COUNT;
         idx = (demo_pattern_t)(idx + 1)) {
        render_pattern(idx);
        esp_err_t err = st7305_lcd_flush();
        if (err != ESP_OK) {
            ESP_LOGE(TAG, "flush %s: %s", pattern_name(idx), esp_err_to_name(err));
        } else {
            ESP_LOGI(TAG, "pattern: %s", pattern_name(idx));
        }
        vTaskDelay(pdMS_TO_TICKS(BOARD_LCD_PATTERN_HOLD_MS));
    }

    ESP_LOGI(TAG, "LCD pattern sequence done");
}
