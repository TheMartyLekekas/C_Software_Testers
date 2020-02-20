/* ====================================
File name: decode.c
Date: 2020-02-018
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [20797]
!====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


char hex[20];

int main(int argc, char const *argv[]) {
  if (argc == 2) {


    /* copy the Argument at index 1 value to the  hexadecimal*/
    strcpy(hex, argv[1]);

    long long decimal;
    int i = 0, value, len;

    decimal = 0;

    /* Find the length of total number of hex digit */
    len = strlen(hex);
    len--;


    // Iterate over each hex digit
     for(i=0; hex[i]!='\0'; i++)
     {

       // Find the decimal representation of hex[i]
        if(hex[i]>='0' && hex[i]<='9')
        {
            value = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            value = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            value = hex[i] - 65 + 10;
        }

        decimal += value * pow(16, len);
        len--;

    }

    printf("Hexadecimal number = %s\n", hex);
    printf("Decimal number = %lld\n", decimal);

    int engine_on = (decimal >> 7) & 0x01;
    int gear_pos  = (decimal >> 4) & 0x07;
    int key_pos   = (decimal >> 2) & 0x03;
    int brake1    = (decimal >> 1) & 0x01;
    int brake2    = (decimal)      & 0x01;


    printf("Name          Value \n");
    printf("------------------- \n");
    printf("engine_on     %d \n", engine_on);
    printf("gear_pos      %d \n", gear_pos);
    printf("key_pos       %d \n", key_pos);
    printf("brake1        %d \n", brake1);
    printf("brake2        %d \n", brake2);

  } else {
    fprintf(stderr, "Invalid number of Argument\n");
    return 0;
  }

}
