#include <stdio.h>
#include <stdlib.h>

int search_number( int number, int tab[], int size);
int test [] = { 1,2,56,5,67,3,23,12,13,10};

void printArray(int value, int arr[]) {
	int i;
	for (i=0; i < value; i++){
    printf("%d ", arr[i]);
  }
	printf("\n");
}

void sort(int arrSize, int arr[])
{
    int minValue, counter, temp = 0;

    printf("UNSORTED ARRAY: ");
    printArray(arrSize, arr);
    
    for (int i = 0; i < arrSize; i++){
        minValue = arr[i];
        counter = i;
        for (int j = i; j < arrSize; j++){
            if (arr[j] < minValue){
                minValue = arr[j];
                counter = j;
            }
        }
        //swop values
        temp = arr[i];
        arr[i] = minValue;
        arr[counter] = temp;
    }
    printf("SORTED ARRAY: ");
    printArray(arrSize, arr);
}


int main(int argc, char const *argv[]) {
  int num;
  printf("Enter an integer:");
  scanf("%d", &num);

  int arraySize = sizeof(test)/sizeof(test[0]);
  int value = search_number(num, test, arraySize);
  int count = sizeof(test);


  if (value >= 0 && value <= count ) {
    printf("%d\n",value);
    printf("%d is in the array at index %d\n",num, value);
    sort(arraySize, test);

  } else {
    printf("%d\n",value);
    printf("%d is not in the array\n",num);
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
