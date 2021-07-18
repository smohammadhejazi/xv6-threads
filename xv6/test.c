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
//       x++;
//       printf(1, "Thread x = %d\n", x);  
//       sleep(100);
//     }
//     exit();
// }

// int main(int argc, char *argv[]) 
// {
//     int tid;
//     int arg = 1;
//     tid = thread_create(&function, &arg);
//     thread_join(tid);
//     printf(1, "Parent x = %d\n", x);
//     printf(1, "Parent terminated.\n");
//     exit();
// }

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

int arr[20];

void function(void *arg)
{
  int num = *((int *)arg);
  for(int i = 0; i < 5; i++)
  {
    arr[num + i] =  num;
  }

  exit();
}

int main(int argc, char *argv[]) 
{
  int tid[4];
  
  int arg0 = 0;
  int arg1 = 5;
  int arg2 = 10;
  int arg3 = 15;

  tid[0] = thread_create(&function, &arg0);
  tid[1] = thread_create(&function, &arg1);
  tid[2] = thread_create(&function, &arg2);
  tid[3] = thread_create(&function, &arg3);

  for(int i = 0; i < 4; i++)
  {
    thread_join(tid[i]);
  }
  
  for (int i = 0; i < 20; i++)
  {
    printf(1, "[%d] = %d\n", i, arr[i]);
  }

  exit();
}

// -4