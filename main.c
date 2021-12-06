#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

void * threadFunc(void * arg) {
        printf("Thread function :: start\n");
        sleep(10);
        printf("Thread function :: end\n");
        return NULL;
}

int main(int argc, char *argv[]) {

        pthread_t threadId;
        int err = pthread_create(&threadId, NULL, &threadFunc, NULL);

        if (err) {
                printf("Thread creation failure\n");
                return err;
        } else {
                printf("Thread created with ID: %d\n", (int) threadId);
        }

        err = pthread_join(threadId, NULL);
        if (err) {
                printf("Thread join failure\n");
                return err;
        }

        return 0;
}