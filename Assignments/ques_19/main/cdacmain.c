#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

QueueHandle_t queue;
TaskHandle_t sensor_handle;
TaskHandle_t buzzer_handle;

void SensorTask(void *pv)
{
    int sens_data=0;
    while(1)
    {
        sens_data++;
        printf("Sensor Task: %d\n",sens_data);
        xQueueSend(queue,&sens_data,portMAX_DELAY);
        vTaskDelay(100/ portTICK_PERIOD_MS);
    }
}

void BuzzerTask(void *pv)
{
    int recv_data=0; 
    while(1)
    {
        printf("Buzzer Task\n");
        xQueueReceive(queue,&recv_data,portMAX_DELAY);
        printf("Received Data: %d\n",recv_data);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}

void app_main()
{
    queue=xQueueCreate(6,sizeof(int));
    BaseType_t result1, result2;
    result1=xTaskCreate(SensorTask,"SensorTask",2048,NULL,6,&sensor_handle);
    if(result1==pdPASS)
    {
        printf("Sensor Task Created\n");
    }

    result2=xTaskCreate(BuzzerTask,"BuzzerTask",2048,NULL,4,&buzzer_handle);
    if(result2==pdPASS)
    {
        printf("Buzzer Task Created\n");
    }
}
