#include "types.h"
#include "user.h"
#include "mmu.h"
#include "thread.h"

int thread_create(void (*function) (void *), void *arg)
{
    void *stack = malloc(PGSIZE);

    if (stack == 0)
        return -1;
    if ((uint)stack % PGSIZE != 0)
        stack += PGSIZE - ((uint)stack % PGSIZE);
    
    return clone(function, arg, stack);
}

int thread_join(int tid)
{
    int retval;
    void *stack;
    retval = join(tid, &stack);
    free(stack);
    return retval;
}

