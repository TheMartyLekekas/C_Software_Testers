/* ====================================
File name: exerc_2_5.c
Date: 2020-01-29
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [23267]Important , No code no exercise points
!====================================== */

#include <stdlib.h>
#include <stdio.h>

#define MAX 100
#define MAXNUMBER 20

void create_random(int *tab) {    // pointer fills the table
  *tab = (rand() % (MAXNUMBER + 1));
}

void count_frequency(int *tab, int *freq) {       // pointer fills in the frequency table
  int temp = *freq + 1;
  *freq = temp;
}

void draw_histogram(int *freq) {    //  histogram is drawn using pointer
        int jj;
        for(jj = 0; jj < *freq; jj++) {
          printf("x");
        }
        printf("\n");
}

int main (void) {
  int table[MAX], n;
  int frequency[MAXNUMBER +1];
  int i;

  for (i = 0; i < MAX; i++) {
    frequency[i] = 0;
  }

  for (i = 0; i < MAX; i++) {                       // creates the table and calculates frequency
    create_random(&table[i]);
    count_frequency(&table[i], &frequency[table[i]]);
  }

  for (i = 0; i < MAX; i++) {                       // prints out the table
    printf("Element[%d] = %d\n", i, table[i]);
  }
  printf("\n\n");

  for (i = 0; i <= MAXNUMBER; i++) {                // prints histogram
    if(frequency[i] > 0) {
      printf("%d ", i);
      draw_histogram(&frequency[i]);
    }
  }

  return 0;
}
