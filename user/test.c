#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"

int
main(int argc, char *argv[])
{
  
  char *start = sbrk(0);
  sbrk(PGSIZE);
  *start=100;
  mprotect(start, 1) ;
  int child=fork();
  
  if(child==0){
        printf("protected value = %d\n", *start);   
        munprotect(start, 1) ;  
        *start=5;
        printf("After unprotecting the value became = %d\n", *start); 
        exit(0);
  }
  else if(child>0){
        wait(0);
        printf("\nWatch this, I'll trap now\n"); 
        *start=5; 
        printf("\nThis statement will not be printed\n");
        exit(0); 
  } 

 return 0;
}