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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readPersnr(char *person);
int controlDigit(const char *personNum);


int main(void)  {
  char socialNum[11];
  char *person = socialNum;

    do
    {
        readPersnr(person);

    } while ((*person != 'q'));

    return 0;
}

void readPersnr(char *person)
{
  char year[3];
  char month[3];
  char day[3];
  int convert[10];
  printf("\n\nEnter 10 digits Personal # or q to cancel: \n\n");
  scanf("%s", person);

  if (person[0] == 'q') {
      printf("Program Canceled... Good bye!\n" );

  } else {

    year[0] = *person;
    person++;
    year[1] = *person;
    year[2] = '\0';
    person++;
    convert[0] = atoi(year);

    month[0] = *person;
    person++;
    month[1] = *person;
    month[2] = '\0';
    person++;
    convert[1] = atoi(month);

    day[0] = *person;
    person++;
    day[1] = *person;
    day[2] = '\0';
    person++;
    convert[2] = atoi(day);

    if (convert[0]>00 && convert[0]<=99 && convert[1]>=01 && convert[1]<=12 && convert[2]>=01 && convert[2]<=31) {
      printf("Personal number is correct\n");
    } else {
      printf("Incorrect Personal Number\n");
    }

    const char *pointer = person;
    int scanNum = controlDigit(pointer);

  }

}

int controlDigit(const char *personNum) {
  /* code */
}
