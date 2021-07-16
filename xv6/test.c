#include "types.h"
#include "stat.h"
#include "user.h"

int stack[4096] __attribute__ ((aligned (4096)));
int x = 0;

void child(void *arg)
{
    printf(1, "child argument is = %d\n", *(int *)arg);
    for(int i = 0; i < 10; i++) 
    {
      x++;
      sleep(100);
    }
}

int main(int argc, char *argv[]) 
{
    int arg = 10;
    printf(1, "Stack is at %p\n", stack);
    // int tid = fork();
    int tid = clone(&child, &arg, stack);
    if (tid < 0) 
    {
        printf(2, "error!\n");
    } 
    else 
    {
        // for(;;)
        // {
        //     printf(1, "x = %d\n", x);
        //     sleep(100);
        // }
        join(tid);
    }
    printf(1, "x = %d\n", x);
    printf(1, "parrent terminated.\n");
    exit();
}