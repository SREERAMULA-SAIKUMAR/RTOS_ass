#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t sens_handle;
TaskHandle_t temp_handle;

void SensorTask(void *pv)
{
    int sens_data=0;
    while(1)
    {
        sens_data++;
        printf("Sensor Task: %d\n",sens_data);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void TemperatureTask(void *pv)
{
    int temp_data=0; 
    while(1)
    {
        temp_data++;
        printf("Temperature Task: %d\n",temp_data);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void app_main()
{
    BaseType_t result1, result2;
    result1=xTaskCreate(SensorTask,"SensorTask",2048,NULL,10,&sens_handle);
    if(result1==pdPASS)
    {
        printf("Sensor Task Created\n");
    }

    result2=xTaskCreate(TemperatureTask,"TemperatureTask",2048,NULL,5,&temp_handle);
    if(result2==pdPASS)
    {
        printf("Temperature Task Created\n");
    }
}
