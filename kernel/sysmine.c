#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

int getppid(void){
    struct proc *p = myproc();

    if (p == 0 || p->parent == 0){
        return -1;
    }
    
    uint64 id = p->parent->pid;
    return id;
}

int getancestor(int g) {
    struct proc *p = myproc();
    int pid = p->pid;
    for (int i = 0; i < g; i++){
        pid = getppid();
        if(pid == -1){
            return -1;
        }
    }

    return pid;
} 
    
uint64 sys_getppid(void){
    return getppid();
}

uint64 sys_getancestors(void){
    int g;
    argint(0, &g);
    return getancestor(g);
}