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
    int count = 0;

    while (p != 0 && count < g){
        p = p->parent;
        count = count + 1;
    }

    if(p != 0) {
        pid = p->pid;
    } else {
        pid = -1;
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