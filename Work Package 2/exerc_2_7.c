/* ====================================
File name: exerc_x_y.c (or cpp)
Date: 2020-mm-dd
Group nr xxx
Members that contributeto the solutions
xxxxxxx
xxxyyyyyyy
yyyzzzzz zzzzzz
Member not present at demonstration time:
Yyyyyy yyyy
Demonstration code: [<Ass code 1-4> <abc>]Important , No code no exercise points
!====================================== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void readPersnr(char *user);

int main(int argc, char const *argv[]) {
  /* code */
  char personNum[11];
  char *person = personNum;



  //printf("Number is %s\n", personNum);
  readPersnr(personNum);

  return 0;
}

void readPersnr(char *user) {

  const char *person = user;

  printf("Please enter your personal number(yymmddxxxx):\n");
  scanf("%s", user);

  char yy[5];
  char mm[5];
  char dd[5];

  yy[0] = user[0];
  user++;

  printf("You were born in the year 19%s\n",yy[0]);
}
