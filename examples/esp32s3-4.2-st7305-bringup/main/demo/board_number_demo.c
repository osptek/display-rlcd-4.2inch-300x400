#include "board_number_demo.h"

#include "board_config.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "number_glyphs.h"
#include "st7305_lcd.h"

static const char *TAG = "number_demo";

static void blit_digit(int digit, int pen_x, int baseline)
{
    const number_glyph_t *g = &k_digits[digit];
    const int stride = (g->w + 7) / 8;
    const int ox = pen_x + g->left;
    const int oy = baseline - g->top;

    for (int y = 0; y < g->h; ++y) {
        const uint8_t *row = g->bits + y * stride;
        for (int x = 0; x < g->w; ++x) {
            if (row[x >> 3] & (uint8_t)(0x80 >> (x & 7))) {
                st7305_lcd_write_point((uint16_t)(ox + x),
                                       (uint16_t)(oy + y),
                                       ST7305_COLOR_BLACK);
            }
        }
    }
}

static void show_number(int number)
{
    const int glyphs[2] = {number == 10 ? 1 : number, 0};
    const int count = number == 10 ? 2 : 1;

    int pen = 0;
    int min_x = 0;
    int max_x = 0;
    int min_y = 0;
    int max_y = 0;

    for (int i = 0; i < count; ++i) {
        const number_glyph_t *g = &k_digits[glyphs[i]];
        const int x0 = pen + g->left;
        const int x1 = x0 + g->w;
        const int y0 = -g->top;
        const int y1 = y0 + g->h;

        if (i == 0 || x0 < min_x) {
            min_x = x0;
        }
        if (i == 0 || x1 > max_x) {
            max_x = x1;
        }
        if (i == 0 || y0 < min_y) {
            min_y = y0;
        }
        if (i == 0 || y1 > max_y) {
            max_y = y1;
        }
        pen += g->advance;
    }

    const int origin_x = ((int)BOARD_LCD_H_RES - (max_x - min_x)) / 2 - min_x;
    const int baseline = ((int)BOARD_LCD_V_RES - (max_y - min_y)) / 2 - min_y;

    st7305_lcd_clear();
    pen = origin_x;
    for (int i = 0; i < count; ++i) {
        blit_digit(glyphs[i], pen, baseline);
        pen += k_digits[glyphs[i]].advance;
    }

    esp_err_t err = st7305_lcd_flush();
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "flush %d: %s", number, esp_err_to_name(err));
    } else {
        ESP_LOGI(TAG, "number: %d", number);
    }
}

void board_number_demo_run(void)
{
    ESP_LOGI(TAG, "number 1..10 loop, hold=%dms", BOARD_LCD_PATTERN_HOLD_MS);

    while (true) {
        for (int number = 1; number <= 10; ++number) {
            show_number(number);
            vTaskDelay(pdMS_TO_TICKS(BOARD_LCD_PATTERN_HOLD_MS));
        }
    }
}
