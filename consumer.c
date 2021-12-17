//Ethan Scheuer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>

int main() {
    
    int shm_fd = shm_open("table", O_RDWR, 0666);
    int* table = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    
    sem_t* fill = sem_open("fill", O_CREAT, 0666, 0);
    sem_t* avail = sem_open("available", O_CREAT, 0666, 2);
    sem_t* mutex = sem_open("mutex", O_CREAT, 0666, 1);
    
    int loop = 20;
    printf("\nConsumer ready to receive %d items.\n", loop);
    
    for (int i = 1; i < loop; ++i) {
        
        sem_wait(fill);
        

        int ms = rand() % 2 + 1;
        sleep(ms);

        sem_wait(mutex);
        --(*table);
        sem_post(mutex);

        printf("Item consumed, %d remaining.\n", *table);

        sem_post(avail);
    }

    sem_close(fill);
    sem_close(avail);
    sem_close(mutex);

    sem_unlink("fill");
    sem_unlink("available");

    munmap(table, sizeof(int));
    close(shm_fd);
    shm_unlink("table");

    printf("Producer cleaned up!\n");
    return 0;



}