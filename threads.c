#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
  long tid;
  tid = (long)threadid;
  for (int i = 0; i < 100000; i++)
  {
    printf("Thread ID, %ld\t%d\n", tid, i);
    sleep(5);
  }
  pthread_exit(NULL);
}

int main()
{
  pthread_t threads[NUM_THREADS];
  int rc;
  int i;
  for (i = 0; i < NUM_THREADS; i++)
  {
    printf("main() : creating thread %d", i);
    rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
    if (rc)
    {
      printf("Error:unable to create thread, %d\n", rc);
      exit(-1);
    }
  }
  pthread_exit(NULL);
}