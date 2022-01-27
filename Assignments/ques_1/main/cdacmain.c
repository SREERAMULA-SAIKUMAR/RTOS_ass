#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void SensorTask(void *pv)
{
    while(1)
    {
        printf("Sensor Task Priority: %d\n", uxTaskPriorityGet(NULL));
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}

void AlarmTask(void *pv)
{
    while(1)
    {
        printf("Alarm Task Priority: %d\n", uxTaskPriorityGet(NULL));
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}

void app_main()
{
    BaseType_t result1,result2;
    
    result1=xTaskCreate(SensorTask,"SensorTask",2048,NULL,10,NULL);
    if(result1==pdPASS)
    {
        printf("Sensor Task Created\n");
    }
    
    result2=xTaskCreate(AlarmTask,"AlarmTask",2048,NULL,5,NULL);
    if(result2==pdPASS)
    {
        printf("Alarm Task Created\n");
    }
}

