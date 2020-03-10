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

int program_time = 0; // The global time, start value 0
int last_time = -1;
int system_time;

int main()
{
  system_time = get_time_ms();

  time_t t;

  pthread_t timer;
  pthread_t inport;

  srand((unsigned) time(&t));

  // Start up the thread time_count.
  pthread_create(&timer, NULL, time_count, NULL);

  // Start up the thread read_inport.
  pthread_create(&inport, NULL, read_inport, NULL);

  while (program_time < 50) //Print out system time every second.
  {
    if(program_time > last_time){
      printf("Time is %d\n", program_time);
      last_time = program_time;
      }
  }

  pthread_join(timer, NULL);
  pthread_join(inport, NULL);

  return(0);
}


void *time_count()
{
  while (program_time < 50)
  {
    if(get_time_ms() > system_time + 1000){
      // printf("Program Time222: %d\n", program_time);
      program_time++;
      system_time = get_time_ms();
    }
    // Increase program_time by one every second.
  }
  pthread_exit(0);
}

void *read_inport(){
  while (program_time < 50)
  {
      // Read Inport every 5 second.

    // if(program_time % 5 == 0)
    // {
      printf("Reading Inport now\n");
    // }
  }
  pthread_exit(0);
}


double get_time_ms()
{
  struct timeval t;
  gettimeofday(&t, NULL);
  return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}
