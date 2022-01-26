#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TickType_t TimeStamp;

void SensorTask1(void *pv)
{
    while(1)
    {
        printf("Sensor Task 1\n");
        TimeStamp = xTaskGetTickCount() * portTICK_PERIOD_MS;
        printf("Time Stamp for Task 1: %d\n",TimeStamp);
        vTaskDelay(100/ portTICK_PERIOD_MS);  
    }
}

void SensorTask2(void *pv)
{
    while(1)
    {
        printf("Sensor Task 2\n");
        TimeStamp = xTaskGetTickCount() * portTICK_PERIOD_MS;
        printf("Time Stamp for Task 2: %d\n",TimeStamp);
        vTaskDelay(200/ portTICK_PERIOD_MS);  
    }
}

void SensorTask3(void *pv)
{
    while(1)
    {
        printf("Sensor Task 3\n");
        TimeStamp = xTaskGetTickCount() * portTICK_PERIOD_MS;
        printf("Time Stamp for Task 3: %d\n",TimeStamp);
        vTaskDelay(300/ portTICK_PERIOD_MS);  
    }
}

void SensorTask4(void *pv)
{
    while(1)
    {
        printf("Sensor Task 4\n");
        TimeStamp = xTaskGetTickCount() * portTICK_PERIOD_MS;
        printf("Time Stamp for Task 4: %d\n",TimeStamp);
        vTaskDelay(400/ portTICK_PERIOD_MS);  
    }
}

void SensorTask5(void *pv)
{
    while(1)
    {
        printf("Sensor Task5\n");
        TimeStamp = xTaskGetTickCount() * portTICK_PERIOD_MS;
        printf("Time Stamp for Task 5: %d\n",TimeStamp);
        vTaskDelay(500/ portTICK_PERIOD_MS);  
    }
}

void SensorTask6(void *pv)
{
    while(1)
    {
        printf("Sensor Task6\n");
        TimeStamp = xTaskGetTickCount() * portTICK_PERIOD_MS;
        printf("Time Stamp for Task 6: %d\n",TimeStamp);
        vTaskDelay(600/ portTICK_PERIOD_MS);  
    }
}

void SensorTask7(void *pv)
{
    while(1)
    {
        printf("Sensor Task7\n");
        TimeStamp = xTaskGetTickCount() * portTICK_PERIOD_MS;
        printf("Time Stamp for Task 7: %d\n",TimeStamp);
        vTaskDelay(700/ portTICK_PERIOD_MS);  
    }
}

void SensorTask8(void *pv)
{
    while(1)
    {
        printf("Sensor Task8\n");
        TimeStamp = xTaskGetTickCount() * portTICK_PERIOD_MS;
        printf("Time Stamp for Task 8: %d\n",TimeStamp);
        vTaskDelay(800/ portTICK_PERIOD_MS);  
    }
}

void SensorTask9(void *pv)
{
    while(1)
    {
        printf("Sensor Task9\n");
        TimeStamp = xTaskGetTickCount() * portTICK_PERIOD_MS;
        printf("Time Stamp for Task 9: %d\n",TimeStamp);
        vTaskDelay(900/ portTICK_PERIOD_MS);  
    }
}

void SensorTask10(void *pv)
{
    while(1)
    {
        printf("Sensor Task10\n");
        TimeStamp = xTaskGetTickCount() * portTICK_PERIOD_MS;
        printf("Time Stamp for Task 10: %d\n",TimeStamp);
        vTaskDelay(1000/ portTICK_PERIOD_MS);  
    }
}

void app_main()
{
    xTaskCreate(SensorTask1,"SensorTask1",2048,NULL,8,NULL);
    xTaskCreate(SensorTask2,"SensorTask2",2048,NULL,8,NULL);
    xTaskCreate(SensorTask3,"SensorTask3",2048,NULL,8,NULL);
    xTaskCreate(SensorTask4,"SensorTask4",2048,NULL,8,NULL);
    xTaskCreate(SensorTask5,"SensorTask5",2048,NULL,8,NULL);
    xTaskCreate(SensorTask6,"SensorTask6",2048,NULL,8,NULL);
    xTaskCreate(SensorTask7,"SensorTask7",2048,NULL,8,NULL);
    xTaskCreate(SensorTask8,"SensorTask8",2048,NULL,8,NULL);
    xTaskCreate(SensorTask9,"SensorTask9",2048,NULL,8,NULL);
    xTaskCreate(SensorTask10,"SensorTask10",2048,NULL,8,NULL);
}
