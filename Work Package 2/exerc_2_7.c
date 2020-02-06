/* ====================================
File name: exerc_2_7.c
Date: 2020-02-04
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
int controlDigit(const char *persnr);


int main()  {
  char socialNum[11];
  char *person = socialNum;

    do {
      readPersnr(person);
    } while (*person != 'q');

    return 0;
}

void readPersnr(char *person)
{
  char year[3];
  char month[3];
  char day[3];
  int convert[10];
  printf("Enter 10 digits Personal # or q to cancel: \n\n");
  scanf("%s", person);
  const char *pointer = person;

  if (person[0] == 'q') {
    printf("Program Cancelled... Good bye!\n" );

  } else if (strlen(person) != 10 || !isdigit(*person)) {
    printf("Invalid input\n");

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

    if (convert[0]>=00 && convert[0]<=99 && convert[1]>=01 && convert[1]<=12 && convert[2]>=01 && convert[2]<=31) {
      int scanNum = controlDigit(pointer);
    } else {
      printf("Invalid birth date\n\n\n");
    }
  }
}

int controlDigit(const char *persnr) {
  int digits[11], i;
  char nr[11];
  for (i = 0; i < 10; i++) {      // convert characters into integers
    nr[i] = *persnr;
    persnr++;
    digits[i] = nr[i] - '0';
  }

  int sum = 0;
  for (i = 0; i <= 8; i+=2) {
    digits[i] *= 2;
  }


  for (i = 0; i <= 8; i++) {
    if(digits[i] < 10) {
      sum += digits[i];

    } else{
      sum += 1 + digits[i] % 10;      // split >=10 integers into digits
    }
  }

  sum = 10 - sum % 10;
  if(sum == 10) sum = 0;
  printf("Calculated control digit is: %d\n", sum);
  if(sum == digits[9])
    printf("Person number is CORRECT\n\n\n");
  else
    printf("Given control digit is INCORRECT\n\n\n");
}
