#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define ALARM_PIN 15

void SensorTask(void *pv)
{
    while (1)
    {
        printf("Sensor Task: %d\n", uxTaskGetStackHighWaterMark(NULL));
        printf("Sensor Task: CPU ID %d\n", xTaskGetAffinity(NULL));
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
    
}

void AlarmTask(void *pv)
{
    esp_rom_gpio_pad_select_gpio(ALARM_PIN);
    gpio_set_direction(ALARM_PIN, GPIO_MODE_OUTPUT);

    while(1)
    {
        //Sensing temperature
        printf("Stack Mark: %d\n", uxTaskGetStackHighWaterMark(NULL));
        printf("Alarm Task: CPU ID %d\n", xTaskGetAffinity(NULL));
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void app_main()
{
    xTaskCreate(SensorTask, "SensorTask", 2048, NULL, 5, NULL);
    xTaskCreate(AlarmTask, "AlarmTask", 2048, NULL, 5, NULL);
    printf("Hello World!\n");
}
