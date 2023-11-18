#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    if(argc > 1){
        int g = atoi(argv[1]);
        int pid = getancestors(g);

        if (pid != -1){
            printf("Ancestor %d has PID: %d\n", g, pid);
        } else {
            printf("There is not that many ancestors\n");
        }
    } else {
        printf("You must input the number of ancestors\n");
        exit(-1);
    }

    return 0;
}