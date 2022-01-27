#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

static portMUX_TYPE sema;
TaskHandle_t sensor_handle;
TaskHandle_t display_handle;

uint32_t count_1=0;

void SensorTask(void *pv)
{
    while(1)
    {
        printf("Sensor Task\n");

        taskENTER_CRITICAL(&sema);
        count_1++;
        taskEXIT_CRITICAL(&sema);

        printf("Count_1: %d\n",count_1);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}

void DisplayTask(void *pv)
{
    uint32_t count_2=0;
    while(1)
    {
        count_2++;
        printf("Display Task\n");
        printf("Count_2: %d\n",count_2);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void app_main()
{
    vPortCPUInitializeMutex(&sema);
    BaseType_t result1, result2;
    result1=xTaskCreate(SensorTask,"SensorTask",2048,NULL,10,&sensor_handle);
    if(result1==pdPASS)
    {
        printf("Sensor Task Created\n");
    }

    result2=xTaskCreate(DisplayTask,"DisplayTask",2048,NULL,8,&display_handle);
    if(result2==pdPASS)
    {
        printf("Display Task Created\n");
    }
}
