/* ====================================
File name: exerc_2_4.c
Date: 2020-01-29
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [25723]Important , No code no exercise points
!====================================== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char string[100];
  int length, left, right, i;

  printf("Enter a string:\n");
  scanf("%s", &string);
  length = strlen(string);

  right = length -1;
  for(i = 0; i <= right; i++){
  		if(string[i] != string[right]){
  			break;
  		}
  		right--;
  	}
  	if(i >= right)	{
  		printf("The string you entered is a palindrome");
  	}else{
  		printf("The string you entered is not a palindrome");
  	}

  return 0;
}
