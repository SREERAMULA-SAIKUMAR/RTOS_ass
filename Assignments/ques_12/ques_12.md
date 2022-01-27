#### What are the APIs provided by your RTOS for enabling and disabling the interrupts?

##### taskENTER_CRITICAL() 

##### taskEXIT_CRITICAL() [[RTOS Kernel Control](https://www.freertos.org/a00020.html)]

```
task. h

void taskENTER_CRITICAL( void );
void taskEXIT_CRITICAL( void );
```

Critical sections are entered by calling taskENTER_CRITICAL(), and subsequently exited by calling taskEXIT_CRITICAL().