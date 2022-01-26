#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void SensorTask(void *pv)
{
    while(1)
    {
        printf("Inside Sensor Task\n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}

void BuzzerTask(void *pv)
{
    while(1)
    {
        printf("Inside Buzzer Task\n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}

void app_main()
{
    BaseType_t result1, result2;
    result1=xTaskCreate(SensorTask,"SensorTask",1024,NULL,20,NULL);
    if(result1==pdPASS)
    {
        printf("Sensor Task Created\n");
    }
    result2=xTaskCreate(BuzzerTask,"BuzzerTask",1024,NULL,10,NULL);
    if(result2==pdPASS)
    {
        printf("Buzzer Task Created\n");
    }
}
