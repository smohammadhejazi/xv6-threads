#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.h"

//1
// int x = 0;

// void function(void *arg)
// {
//     for(int i = 0; i < 5; i++) 
//     {
//       printf(1, "wrting to x = %d\n", x);  
//       x++;
//       sleep(100);
//     }
// }

// int main(int argc, char *argv[]) 
// {
//     int tid;
//     int arg = 1;
//     // int tid = fork();
//     tid = thread_create(&function, &arg);
//     thread_join(tid);
//     printf(1, "x = %d\n", x);
//     printf(1, "parrent terminated.\n");
//     exit();
// }

// -1

// 2

// int x = 0;

// int fib(int n)
// {
//    if (n <= 1)
//       return n;
//    return fib(n-1) + fib(n-2);
// }

// int main(int argc, char *argv[]) 
// {
//     x = fib(35);
//     printf(1, "hex = %x\n", x);
//     printf(1, "int = %d\n", x);
//     printf(1, "parrent terminated.\n");
//     exit();
// }

// -2

// 3

int x = 0;

int fib(int n)
{
if (n <= 1)
	return n;
return fib(n-1) + fib(n-2);
}

void function(void *arg)
{
  x = fib(*((int*)arg));
  exit();
}

int main(int argc, char *argv[]) 
{
    int tid;
    int arg = 35;

    tid = thread_create(&function, &arg);
    thread_join(tid);
    printf(1, "x = %x\n", x);
    printf(1, "x = %d\n", x);
    printf(1, "parrent terminated.\n");
    exit();
}

// -3

// 4

// int main(int argc, char *argv[]) 
// {
//     int mat[20000][20000];
//     mat[1][1] = 10;
//     printf(1, "%d\n", mat[1][1]);
//     exit();
// }

// -4

// 5

// void function(void *arg)
// {
//     int mat[20000][20000];
//     mat[1][1] = 10;
//     printf(1, "%d\n", mat[1][1]);
// }

// int main(int argc, char *argv[]) 
// {
//     int tid;
//     tid = thread_create(&function, 0);
//     thread_join(tid);
//     printf(1, "parrent terminated.\n");
//     exit();
// }

// -5