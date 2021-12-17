# OS Project 1

The purpose of this program is to solve the Producer Consumer problem using sychronization. 

## Description

This program uses two processes, the producer and the consumer. These are seperate processes that are connected through shared memory. The producer starts by increasing the avail semaphore. After a small pause, the producer increases the mutex semaphore, increments the table, and decreases the mutex. This is done so that both processes may not enter the critical section at the same time. Then, the producer increases the fill semaphore. This will allow the consumer to recognize that the fill semaphore has been increased, and start its loop by decreasing the fill semaphore. After a small pause, the consumer increases the mutex, decrements the table, and decreases the mutex. After that, the consumer increases the avail semaphore. These semaphores allow the processes to communicate with each other and take turns producing and consuming. Finally, the producer gets cleaned up and the program is complete.

The source code and output example are stored in the master branch.

### Dependencies

Linux Ubuntu

### Executing program
First, compile the program files with "gcc producer.c -pthread -lrt -o producer" and "gcc consumer.c -pthread -lrt -o consumer". Then, run the program with "./producer & ./consumer &".

### Author(s)

Ethan Scheuer
