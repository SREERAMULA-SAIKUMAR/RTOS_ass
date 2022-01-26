#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t sensor_handle;

void SensorTask(void *pv)
{
    while(1)
    {
        printf("Inside Sensor Task\n");
        vTaskDelay(500/ portTICK_PERIOD_MS);
    }
}

void app_main()
{
    BaseType_t result;
    
    result=xTaskCreate(SensorTask,"SensorTask",2048,NULL,8,&sensor_handle);

    if(result==pdPASS)
    {
        printf("Sensor Task Created\n");
    }
}
