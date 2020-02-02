/* ====================================
File name: exerc_2_7.c
Date: 2020-02-02
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [<Ass code 1-4> <abc>]Important , No code no exercise points
!====================================== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void readPersnr(char *user);

int main(int argc, char const *argv[]) {
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
