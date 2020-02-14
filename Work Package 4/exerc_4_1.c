#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned char byte;


  if (argc == 6) {
    int engine_on = atoi(argv[1]);
    int gear_pos = atoi(argv[2]);
    int key_pos = atoi(argv[3]);
    int brake1 = atoi(argv[4]);
    int brake2 = atoi(argv[5]);


    printf("Name        Value\n");
    printf("----------------\n");
    printf("engine_on    %d\n", engine_on);
    printf("gear_pos     %d\n", gear_pos);
    printf("key_pos      %d\n", key_pos);
    printf("brake1       %d\n", brake1);
    printf("brake2       %d\n", brake2);

  } else {
    puts("Invalid number of arguments");
  }


  return 0;
}
