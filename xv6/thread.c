#include "types.h"
#include "user.h"
#include "mmu.h"
#include "thread.h"

int thread_create(void (*function) (void *), void *arg)
{
    int retval;
    void *stack = malloc(PGSIZE);

    if (stack == 0)
        return -1;
    if ((uint)stack % PGSIZE != 0)
        stack += PGSIZE - ((uint)stack % PGSIZE);
    
    retval = clone(function, arg, stack);
    free(stack);

    return retval;
}

int thread_join(int tid)
{
    return join(tid);
}

