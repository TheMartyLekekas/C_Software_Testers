#include <stdio.h>
#include <string.h>

//Exerc_2_ 1

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
        if ((fp = fopen("../txtfile.txt", "r")) == NULL) {
            printf("Error! opening file");
            return (0);
        } else {
            fscanf(fp, "%20s", input);
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
    int size = sizeof(original);
    for(int i = 0; i < size; i++){
        duplicate[i] = original[i];
    }
}