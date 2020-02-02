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

#include <stdio.h>
#include <string.h>

void withLibrary(int val, char* arr1, char* arr2) {
  if(val==3) {
  	if(strcmp(arr1, arr2)==0)
  	{
  		printf("The strings are identical");
  	}
  	else
  	{
  		printf("The strings are not identical");
  	}
  }
  else{
    printf("Number Of Strings Entered: %d",val-1);
  }
}


void withoutLibrary(int val, char* string1, char* string2)
{
    int i = 0, counter = 0;
    if (val==3) {
      while(string1[i] != '\0' && string2[i] != '\0')
      {
          //Breaks if there is difference in character
          if(string1[i] != string2[i])
          {
              counter = 1;
              break;
          }
          i++;
      }

      // Check if characters are the same and ended
      if(counter == 0 && string1[i] == '\0' && string2[i] == '\0'){
          printf("The strings are identical");
      }else{
          printf("The strings are not identical");
      }
    } else {
      printf("Number Of Strings Entered: %d",val-1); // Prints out number of arguments passed
    }


}

int main(int argc,char* argv[]) {

  char *argv1 = argv[1];
  char *argv2 = argv[2];

  int compare;
  int value = argc;
  int* num = &value;


  withLibrary(*num, argv1, argv2);     // Method call to compare with the standard library
  printf("\n\n");
  withoutLibrary(*num, argv1, argv2);  // Method call to compare without Library

	return 0;
}
