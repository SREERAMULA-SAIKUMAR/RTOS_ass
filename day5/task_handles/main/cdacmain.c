#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <freertos/semphr.h>

#define ALARM_PIN 15

TaskHandle_t sensorHandle;
TaskHandle_t processHandle;


void SensorTask(void *pv)
{
    int sensor_data = 0;
    while (1)
    {
        sensor_data++;
        printf("Sensor Task: sensor_data %d\n", sensor_data);
        vTaskDelay(500/portTICK_PERIOD_MS);
        if(sensor_data==10)
        {
            vTaskResume(processHandle);
            printf("Sensor Task: sensor_data %d\n", sensor_data);
            vTaskDelay(1000/portTICK_PERIOD_MS);
        }
    }
}

void ProcessingTask(void *pv)
{
    int recv_data=0;
    while(1)
    {
        vTaskSuspend(NULL);
        printf("Processing Task : recv_data %d\n", recv_data);
        vTaskDelay(1000/portTICK_PERIOD_MS);

    }
}

void app_main()
{

    xTaskCreate(SensorTask, "SensorTask", 2048, NULL, 5, &sensorHandle);
    xTaskCreate(ProcessingTask, "ProcessingTask", 2048, NULL, 3, &processHandle);
    printf("Hello World!\n");
}
