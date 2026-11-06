# 示例工程 / Sample Projects

本目录收录本规格屏幕的示例工程，每个子文件夹是一个独立工程，打开对应文件夹按其中的 README 编译即可。
这些工程是参考代码，引脚、背光、触摸等配置请按你的硬件修改；选用前请对照仓库首页各型号的驱动 IC 和接口确认。

This folder holds sample projects for this display spec. Each sub-folder is a standalone project — open it and follow its own README to build.
They are reference code; adjust pins, backlight, touch and other settings to your hardware. Before choosing one, check the driver IC and interface against the models listed on the repository home page.

| 例程 / Project | 平台 / Platform | 驱动 IC / Driver IC | 接口 / Interface | 说明 / Description |
|---|---|---|---|---|
| [`esp32s3-4.2-st7305-bringup`](./esp32s3-4.2-st7305-bringup/) | ESP32-S3 | ST7305 | — | 点屏与板级驱动示例，含 LCD 初始化、FT3269 触摸、数字与 UI 绘制演示 / bring-up and board-level demo with LCD init, FT3269 touch, number and UI drawing demos |
| [`esp32s3-st7306-spi-demo`](./esp32s3-st7306-spi-demo/) | ESP32-S3 | ST7306 | SPI | 显示驱动示例，含编码器与图像数据 / display driver demo with encoder and image data |

如有问题请联系技术支持。 / Contact technical support if you have questions.
