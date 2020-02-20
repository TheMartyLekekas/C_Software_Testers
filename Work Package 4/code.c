/* ====================================
File name: code.c
Date: 2020-02-17
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [25944]
!====================================== */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned char byte;


  if (argc == 6) {
    int engine_on = atoi(argv[1]); // 1
    int gear_pos = atoi(argv[2]); // 2
    int key_pos = atoi(argv[3]); // 2
    int brake1 = atoi(argv[4]); // 1
    int brake2 = atoi(argv[5]); // 1

    byte |= brake2;             // 00000000 |= 00000001
    byte |= (brake1 << 1);      // 00000001 |= 00000010
    byte |= (key_pos << 2);     // 00000011 |= 00001000
    byte |= (gear_pos << 4);    // 00001011 |= 00000000
    byte |= (engine_on << 7);   // 00101011 |= 10000000

    printf("The hexadecimal value is : %X\n",byte); //print out hexa value in upper case
    // Bits pattern in hexadecimal
    // http://csweb.cs.wfu.edu/~turketwh/CSC101/Spring2011/BinaryHex.pdf

    printf("\n");
    printf("\n");

    printf("Name        Value\n");
    printf("----------------\n");
    printf("engine_on    %d\n", engine_on);
    printf("gear_pos     %d\n", gear_pos);
    printf("key_pos      %d\n", key_pos);
    printf("brake1       %d\n", brake1);
    printf("brake2       %d\n", brake2);

  } else {
    puts("Argument is less or more than five");
  }


  return 0;
}
