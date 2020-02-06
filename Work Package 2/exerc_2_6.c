/* ====================================
File name: exerc_2_6.c
Date: 2020-02-02
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [22237]Important , No code no exercise points
!====================================== */

#include <stdlib.h>
#include <stdio.h>

#define MAX 5
int marker = 0;

void initQue(int list[], int max) {       // fills the queue with vacant positions
    int i;
    for(i = 0; i < max; i++) {
      list[i] = -1;
    }
}

int input (int list [] , int number, int max) {     // adds number into the queue
    if(marker < max) {
      list[marker] = number;
      marker++;
      return 1;
    }
    return 0;
}

int output( int list[], int max) {    // required user input: "-1"
  int i;                              // removes the first queue number
  for (i = 0; i < marker; i++) {
    if(i == 4) list[i] = -1;
    else list[i] = list[i+1];
  }
  marker--;

  return 0;
}


int main (void) {
    int valid;
    int que[MAX], i, in;
    initQue(que, MAX);


    while(in != -3) {
      for(i = 0; i < MAX; i++) {
        printf("%d ", que[i]);
      }  printf("\n");

      valid = scanf("%d", &in);
      if(valid != 1){
        printf("Invalid input\n");
        break;

      } else if(in == -1) {
          output(que, MAX);

      } else if(in > -1) {
        input(que, in, MAX);

      } else {
        printf("Negative values are not allowed\n");

      }
    }

    return 0;
}
