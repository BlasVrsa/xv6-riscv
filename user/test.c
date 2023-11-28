#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Usage: chmod mode file\n");
        exit(1);
    }

    const char *filename = argv[1];
    int mode = atoi(argv[2]);

    if(chmod(filename, mode) < 0){
        printf("chmod failes\n");
        exit(1);
    }
    exit(0);
}