#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    int pid = getppid();
    printf("Father %l\n", pid);
    return 0;
}