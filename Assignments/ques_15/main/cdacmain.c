#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t sensor_handle;
TaskHandle_t buzzer_handle;

void SensorTask(void *pv)
{
    int count_1=0;
    while(1)
    {
        printf("Sensor Task\n");
        count_1++;
        if(count_1==12)
        {
              vTaskResume(buzzer_handle); 
              count_1=0;  
        }
        vTaskDelay(100/ portTICK_PERIOD_MS);
    }
}

void BuzzerTask(void *pv)
{
    int count_2=0; 
    while(1)
    {   
        printf("Buzzer Task\n");
        count_2++;
        if(count_2==12)
        {
            vTaskSuspend(NULL);
            printf("Buzzer Task Suspended for 1200ms\n");
            count_2=0;
        }
        vTaskDelay(100/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    BaseType_t result1, result2;
    
    result1=xTaskCreate(SensorTask,"SensorTask",2048,NULL,8,&sensor_handle);
    if(result1==pdPASS)
    {
        printf("Sensor Task Created\n");
    }

    result2=xTaskCreate(BuzzerTask,"BuzzerTask",2048,NULL,8,&buzzer_handle);
    if(result2==pdPASS)
    {
        printf("Buzzer Task Created\n");
    }
}
