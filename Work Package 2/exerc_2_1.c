/* ====================================
File name: exerc_2_1.c
Date: 2020-01-29
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [26900]Important , No code no exercise points
!====================================== */

#include <stdio.h>
#include <string.h>

void dupeString(char[], char[]);

int main() {
    char copiedstr[21];
    char input[21];

    printf("Please enter the string or supply txt file, max 20 characters: \n");
    scanf("%20s", &input);

    if(input == NULL){
        printf("File is empty\n");
    }else{
        printf("Copied using library: \n");
        strcpy(copiedstr,input);
        printf(copiedstr);

        printf("\nCopied using method: \n");
        dupeString(copiedstr,input);
        printf(copiedstr);
    }

    return(0);
}

void dupeString(char* duplicate, char* original){
    int size = strlen(original);
    for(int i = 0; i < size+1; i++){
        duplicate[i] = original[i];
    }
}
