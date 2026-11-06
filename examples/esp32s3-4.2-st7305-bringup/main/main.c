#include "board_config.h"
#include "board_lcd.h"
#include "board_lcd_demo.h"
#include "board_number_demo.h"
#include "board_touch.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "bringup";

void app_main(void)
{
    ESP_LOGI(TAG, "4.2\" ST7305 400x300 bringup, board=%d demo=%d",
             BOARD_PIN_VARIANT, BOARD_DEMO);

#if BOARD_DEMO == BOARD_DEMO_TOUCH
    board_touch_prepare_pins();
#endif

    ESP_ERROR_CHECK(board_lcd_init());

#if BOARD_DEMO == BOARD_DEMO_LCD_LOOP
    ESP_LOGI(TAG, "demo: LCD pattern loop");
#elif BOARD_DEMO == BOARD_DEMO_LCD_ONCE
    board_lcd_demo_run_once();
#elif BOARD_DEMO == BOARD_DEMO_TOUCH
    vTaskDelay(pdMS_TO_TICKS(200));
    ESP_ERROR_CHECK(board_touch_init());
    board_touch_demo_start();
#elif BOARD_DEMO == BOARD_DEMO_NUMBER
    board_number_demo_run();
#else
#error "未知 demo，请在 board_select.h 中选择"
#endif
}
