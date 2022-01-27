#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t sensor_handle;
TaskHandle_t buzzer_handle;

eTaskState a;

void SensorTask(void *pv)
{
    while(1)
    {
        printf("Sensor Task\n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}

void BuzzerTask(void *pv)
{
    uint32_t count=0;
    while(1)
    {
        count++;
        printf("Buzzer Task\n");
        printf("Count Value: %d\n", count);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
        if(count==8)
        {
            printf("Count Value: %d\n", count);
            vTaskDelete(NULL);
        }
    }
}

void app_main()
{
    BaseType_t result1, result2;
    result1=xTaskCreate(SensorTask,"SensorTask",2048,NULL,10,&sensor_handle);
    if(result1==pdPASS)
    {
        printf("Sensor Task Created\n");
    }

    result2=xTaskCreate(BuzzerTask,"BuzzerTask",2048,NULL,10,&buzzer_handle);
    if(result2==pdPASS)
    {
        printf("Buzzer Task Created\n");
    }

    while(1)
    {
        a=eTaskGetState(buzzer_handle);
        switch(a)
        {
            case eRunning:
                printf("Buzzer Task is Running\n");
                break;
            case eReady:
                printf("Buzzer Task is Ready\n");
                break;
            case eDeleted:
                printf("Buzzer Task is Deleted\n");
                break;
            case eBlocked:
                printf("Buzzer Task is Blocked\n");
                break;
            case eSuspended:
                printf("Buzzer Task is Suspended\n");
                break;
            default:
                printf("Unknown State\n");
                break; 
        }  
    printf("Buzzer Task State: %d\n",a);  
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
