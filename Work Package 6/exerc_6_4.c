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

#define ONE_SECOND 1000
#define FIVE_SECONDS 5000

void *time_count();
void *read_inport();
double get_time_ms();

int program_time; // The global time, start value 0


int main()
{
  program_time = 0;


  time_t t;

  pthread_t timer;
  pthread_t inport;

  // Start up the thread time_count.
  pthread_create(&timer, NULL, time_count, NULL);
  // Start up the thread read_inport.
  pthread_create(&inport, NULL, read_inport, NULL);

  double system_time;
  double start_time;

  start_time = get_time_ms();

  while ( program_time < 50) {
        system_time = get_time_ms();
        if((system_time - start_time) >= ONE_SECOND){
            printf("Time is %d \n",program_time);
            start_time = get_time_ms();
        }
  }

  pthread_join(timer, NULL);
  printf("Joining timer thread");

  pthread_join(inport, NULL);
  printf("Joining read inport thread");

  return(0);
}


void *time_count()
{

  double system_time;
  double start_time;

  start_time = get_time_ms();

  while ( program_time < 50) {
        system_time = get_time_ms();
        if((system_time - start_time) >= ONE_SECOND){
            program_time++;
            start_time = get_time_ms();
        }
  }
  pthread_exit(0);
}

void *read_inport(){

  double start_time;
  double system_time;


  start_time = get_time_ms();

  while ( program_time < 50) {
        system_time = get_time_ms();
        if((system_time - start_time) >= FIVE_SECONDS){
            puts("Reading value now");
            start_time = system_time;
        }
  }

  pthread_exit(0);
}

double get_time_ms(){
  struct timeval t;
  gettimeofday(&t, NULL);
  return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}
