/* ====================================
File name: exerc_6_4.c
Date: 2020-03-09
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: []
!====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

void *time_count();
void *read_inport();
double get_time_ms();

int program_time; // The global time, start value 0

int main()
{
  pthread_t timer;
  pthread_t inport;
  pthread_create(&timer, NULL, time_count, NULL);
  pthread_create(&inport, NULL, read_inport, NULL);
  // Start up the thread time_count.
  // Start up the thread read_inport.
  while (program_time < 50) //Print out system time every second.
  {
    printf("Program Time: %d\n", program_time);
  }
  pthread_join(timer, NULL);
  pthread_join(inport, NULL);
  return 0;
}


void *time_count()
{
  while (program_time < 50)
  {
    program_time++;
    // Increase program_time by one every second.
  }
  return NULL;
}

void *read_inport()
{
  while (program_time<50)
  {
    printf("Reading Inport now\n");
    // Read Inport every 5 second.
    // Simulate this just by print out a text : Reading Inport now
  }
  // Exit thread
  return NULL;
}


double get_time_ms()
{
  struct timeval t;
  gettimeofday(&t, NULL);
  return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}
