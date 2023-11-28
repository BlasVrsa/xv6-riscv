#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int n_c = 2;

int main(int argc, char *argv[]){
    int pid;

    for(int i = 0; i < n_c; i++){
        pid = fork();
        if(pid < 0){
            printf("Error in fork\n");
            exit(1);
        }
        if(pid == 0){
            set_priority(i, getpid());
            for(int j = 1; j <= 60; j++){
                printf("PID %d: %d\n", getpid(), j);
                sleep(1);
            }
            exit(0);
        }
    }
    exit(0);
}