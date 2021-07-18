#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.h"

//1

int x = 0;

void function(void *arg)
{
    for(int i = 0; i < 5; i++) 
    {
      x++;
      printf(1, "Thread x = %d\n", x);  
      sleep(100);
    }
    exit();
}

int main(int argc, char *argv[]) 
{
    int tid;
    int arg = 1;
    tid = thread_create(&function, &arg);
    thread_join(tid);
    printf(1, "Parent x = %d\n", x);
    printf(1, "Parent terminated.\n");
    exit();
}

// -1

// 2

// int x = 0;

// int main(int argc, char *argv[]) 
// {
//   int tid;

//   tid = fork();
//   if (tid < 0)
//   {
//     printf(2, "error!\n");
//   }
//   else if (tid > 0)
//   {
//     for(int i = 0; i < 5; i++)
//     {
//       x++;
//       printf(1, "P = %d\n", x);
//     }
//     wait();
//   }
//   else
//   {
//     sleep(100);
//     for(int i = 0; i < 5; i++)
//     {
//       printf(1, "C = %d\n", x);
//     }
//   }
  
//   printf(1, "Terminated.\n");
//   exit();
// }

// -2

// 3

// int x = 0;

// int fib(int n)
// {
// if (n <= 1)
// 	return n;
// return fib(n-1) + fib(n-2);
// }

// void function(void *arg)
// {
//   printf(1, "Thread created.\n");
//   x = fib(*((int*)arg));
//   printf(1, "Thread x = %d\n", x);
//   printf(1, "Thread terminated.\n");
//   exit();
// }

// int main(int argc, char *argv[]) 
// {
//     int tid;
//     int arg = 35;

//     tid = thread_create(&function, &arg);
//     thread_join(tid);
//     printf(1, "Parent hex x = %x\n", x);
//     printf(1, "Parent int x = %d\n", x);
//     printf(1, "Parent terminated.\n");
//     exit();
// }

// -3

// 4

// int main(int argc, char *argv[]) 
// {
//     int mat[40][40];
//     for (int i = 0; i < 40; i++)
//     {
//       for (int j = 0; j < 40; j++)
//       {
//         mat[i][j] = i;
//       }
//     }
//     printf(1, "%d\n", mat[39][39]);
//     exit();
// }

// -4

// 5

// void function(void *arg)
// {
//     int mat[20000][20000];
//     for (int i = 0; i < 20000; i++)
//     {
//       for (int j = 0; j < 20000; j++)
//       {
//         mat[i][j] = i;
//       }
//     }
//     printf(1, "Thread: %d\n", mat[10000][10000]);
//     exit();
// }

// int main(int argc, char *argv[]) 
// {
//     int tid;
//     tid = thread_create(&function, 0);
//     thread_join(tid);
//     printf(1, "Parent terminated.\n");
//     exit();
// }

// -5