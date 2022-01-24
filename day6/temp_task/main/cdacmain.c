#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/timers.h>

TaskHandle_t temp_handle;
TaskHandle_t pres_handle;
TaskHandle_t calb_handle;

void TemperatureTask(void *pv)
{
    while (1)
    {
        printf("Temperature Task\n");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
    
}

void PressureTask(void *pv)
{
    while (1)
    {
        printf("Pressure Task\n");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void CalibrationTask(void *pv)
{
    printf("Calibration Task\n");
    vTaskDelete(NULL);
}

void app_main()
{
    xTaskCreate(TemperatureTask, "TemperatureTask", 2048, NULL, 5, &temp_handle);
    xTaskCreate(PressureTask, "PressureTask", 2048, NULL, 5, &pres_handle);
    xTaskCreate(CalibrationTask, "CalibrationTask", 2048, NULL, 5, &calb_handle);

    while (1)
    {
        printf("Main Task\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    
}
