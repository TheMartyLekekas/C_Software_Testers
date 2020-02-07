#include <stdio.h>
#include <stdlib.h>


int search_number( int number, int tab[], int size);
int test [] = { 1,2,34,5,67,3,23,12,13,10};
void sort (int number, int tab []);




int main(int argc, char const *argv[]) {
  int num;
  printf("Enter an integer:");
  scanf("%d", &num);

  int arraySize = sizeof(test)/sizeof(test[0]);
  int value = search_number(num, test, arraySize);

  if (value == 1) {
    printf("%d\n",value);
    printf("%d is in the array\n",num );
  } else {
    printf("%d\n",value);
    printf("%d is not in the array\n",num );
  }
  return 0;
}

int search_number( int number, int tab[], int size){
  int i;
  for (i = 0; i < size; i++) {
    if (tab[i] == number) {
      return i;
    }
  }
    return -1;
}
