#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t alarm_handle;

void AlarmTask(void *pv)
{
    uint32_t count=0;
    while(1)
    {
        printf("Inside Alarm Task\n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);
        count++;
        if(count==5)
        {
            vTaskDelete(alarm_handle);
        }
    }
}

void app_main()
{
    BaseType_t result;
    result=xTaskCreate(AlarmTask,"AlarmTask",2048,NULL,5,&alarm_handle);
    if(result==pdPASS)
    {
        printf("Alarm Task Created\n");
    }
}
