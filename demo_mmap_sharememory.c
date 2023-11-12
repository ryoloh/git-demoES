  GNU nano 6.2                     shared_memory.c                              
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main() {
    const int SIZE = 4096;
    const char* name = "/myshm";

    int shm_fd;
    char* shm_p;

    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SIZE);

    shm_p = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_p == MAP_FAILED) {
        printf("mmap failed\n");
        return -1;
    }

    sprintf(shm_p, "\nHello from shared memory!");

    printf("Data written to shared memory: %s\n", shm_p);

    if (munmap(shm_p, SIZE) == -1) {
        printf("munmap failed\n");
        return -1;
    }

    if (shm_unlink(name) == -1) {
        printf("shm_unlink failed\n");
        return -1;
    }

    return 0;
}
