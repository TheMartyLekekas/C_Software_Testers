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
    //declarations
    int option;
    int option2;
    char input[21];
    char copiedstr[21];


    printf("Enter through 1.keyboard or 2.file: ");
    scanf("%d",&option);

    if (option != 1 && option != 2){
        printf("Error! input 1 or 2");
        return(0);
    }

    if (option == 1) {
        printf("Please enter the string, max 20 characters: ");
        scanf("%20s",&input);
    } else if (option == 2) {
        FILE *fp;
        if ((fp = fopen("myfile.txt", "r")) == NULL) {
            printf("Error! opening file");
            return (0);
        } else {
            fgets(input,21,fp);
        }
    }

    printf("Copy using 1.library or 2.method: ");
    scanf(" %d",&option2);

    if (option2 != 1 && option2 != 2){
        printf("Error! input 1 or 2");
        return(0);
    }

    if (option2 == 1) {
        strcpy(copiedstr,input);
    } else if (option2 == 2) {
        dupeString(copiedstr,input);
    }

    printf("Copied string is: ");
    printf(copiedstr);

    return(0);
}

void dupeString(char* duplicate, char* original){
    int size = strlen(original);
    for(int i = 0; i < size+1; i++){
        duplicate[i] = original[i];
    }
}
