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

void *time_count(void *param);
void *read_inport(void *param);
double get_time_ms();

int program_time = 0; // The global time, start value 0
double last_time;

int main()
{
  time_t t;

  pthread_t timer;
  pthread_attr_t attr_1;

  pthread_t inport;
	pthread_attr_t attr_2;

  srand((unsigned) time(&t));

  pthread_attr_init(&attr_1);
  pthread_create(&timer, &attr_1, time_count, NULL);


  pthread_attr_init(&attr_2);
  pthread_create(&inport, &attr_2, read_inport, NULL);

  while (program_time < 50) //Print out system time every second.
 {
   if(program_time < last_time){
     printf("Program Time: %d\n", program_time);
     last_time++;
   }

}
    pthread_join(timer, NULL);
    pthread_join(inport, NULL);

  // Start up the thread time_count.
  // Start up the thread read_inport.

return(0);

}


void *time_count(void *param)
{
  while (program_time < 50)
  {
    if(ctime > last_time){
      program_time++;s
    }
    // Increase program_time by one every second.
  }
  pthread_exit(0);
}

void *read_inport(void *param){
  while (program_time<50)
  {
    puts("Reading Inport now");
    // Read Inport every 5 second.
    // Simulate this just by print out a text : Reading Inport now
  }
  // Exit thread
  pthread_exit(0);
}


double get_time_ms()
{
  struct timeval t;
  gettimeofday(&t, NULL);
  return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}
