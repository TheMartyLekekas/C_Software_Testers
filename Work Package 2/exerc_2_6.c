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
    int que[MAX], i, in;
    initQue(que, MAX);

    while(in != "q") {
      for(i = 0; i < MAX; i++) {
        printf("%d ", que[i]);
      }  printf("\n");

      scanf("%d", &in);
      if(in == -1) {
        output(que, MAX);
      } else{
        input(que, in, MAX);
      }
    }

    return 0;
}
