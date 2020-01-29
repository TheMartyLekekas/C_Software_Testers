#include <stdlib.h>
#include <stdio.h>

int main() {

    int i, j;
    int MAX = 10;
    int min = 1;
    int max = 99;
    int array[MAX];
    int* arr[MAX];
    int* address = &array;

    for (i = 0; i < MAX; i++) {
      array[i] = (rand() % (max - min + 1)) + min;
      arr[i] = &array[i];
    }

    printf("The value of the label array(address) is: %p\n", address);
    printf("First integer in the array is (array[0]): %d\n", array[0]);
    printf("The size of an integer (number of bytes) is: %d\n", sizeof(int));
    printf("The sizeof the whole array is: %d\n", MAX);
    for (j = 0; j < MAX; j++) {
        printf("Element[%d] = %d\n", j, *arr[j]);
    }

    return 0;
}
