#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.h"

int x = 0;

void function(void *arg)
{
    for(int i = 0; i < 5; i++) 
    {
      printf(1, "wrting to x = %d\n", x);  
      x++;
      sleep(100);
    }
}

int main(int argc, char *argv[]) 
{
    int tid;
    int arg = 1;
    // int tid = fork();
    tid = thread_create(&function, &arg);
    thread_join(tid);
    printf(1, "x = %d\n", x);
    printf(1, "parrent terminated.\n");
    exit();
}