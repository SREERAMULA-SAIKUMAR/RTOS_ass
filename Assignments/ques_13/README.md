#### Does your RTOS provide APIs to collect task statistics. If yes, list the statistics parameters that are collected.

### eTaskGetState

task.h

##### `eTaskState eTaskGetState( TaskHandle_t xTask );`

Returns as an enumerated type the state in which a task existed at the time eTaskGetState() was executed.

INCLUDE_eTaskGetState must be set to 1 in FreeRTOSConfig.h for eTaskGetState() to be available.

See also [vTaskGetInfo()](https://www.freertos.org/vTaskGetInfo.html).

- **Parameters:**

  *xTask* The handle of the subject task (the task being queried).

- **Returns:**

  The table below lists the value that eTaskGetState() will return for each possible state that the task referenced by the xTask parameter can exist in.

![image-20220127194239849](/home/a/snap/typora/46/.config/Typora/typora-user-images/image-20220127194239849.png)

### 