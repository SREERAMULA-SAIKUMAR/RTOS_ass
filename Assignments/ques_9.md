#### Find the fields that are maintained in the Task Control Block / Process Control Block of the RTOS you are using.

Ans: A process control block (PCB) contains information about the process, i.e. registers, quantum, priority, etc. The process table is an array of PCB's, that means logically contains a PCB for all of the current processes in the system.