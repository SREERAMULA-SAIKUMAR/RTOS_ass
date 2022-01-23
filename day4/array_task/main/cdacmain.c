#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

TaskHandle_t xHandleTaskLog;

void TaskLog(void *pvParameters)
{
    int array[100];
    int i;
    for(i=0;i<100;i++)
    {
        array[i]=i;
        printf("Array: %d\n", array[i]);
    }
    printf("TaskLog\n");
    vTaskDelete(xHandleTaskLog);
}

void app_main()
{
    BaseType_t result;
    result = xTaskCreate(TaskLog, "TaskLog", 2048, NULL, 5, &xHandleTaskLog);

    if(result==pdPASS)
    {
        printf("TaskLog Created\n");
    }
}
