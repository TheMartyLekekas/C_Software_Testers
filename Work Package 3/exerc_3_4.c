/* ====================================
File name: exerc_3_4.c
Date: 2020-02-12
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [-]
!====================================== */

#include <stdlib.h>
#include <stdio.h>

// -----Typedefs -------
typedef struct {
    char firstname[20];
    char lastname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

#define true 1
#define false 0

// Function declaration (to be extend)
PERSON input_record(void); // Reads in a person record.
void write_new_file(PERSON *inrecord);
void printfile(void); // print out all persons in the file
void search_by_firstname(char *name);// print out person if in list
void append_file(PERSON *inrecord);// appends a new person to the file

int main(void) {
    PERSON ppost;
    int input;
    char search[20];
    char choice;

    while(true){
        printf("1 Create a new and delete the old file\n"
               "2 Add a new person to the file\n"
               "3 Search for a person in the file\n"
               "4 Print out all in the file\n"
               "5 Exit the program\n");
        scanf("%d", &input);
        if(input > 0 && input <= 5) {
            switch (input) {
                case 1:
                    write_new_file(&ppost);
                    break;
                case 2:
                    append_file(&ppost);
                    break;
                case 3:
                    printf("Search by (F) first name or (L) last name: ");
                    scanf(" %c",&choice);
                    if(choice == 70) {
                        printf("Please enter the first name of person:\n");
                        scanf(" %21s", &search);
                        search_by_firstname(search);
                    } else if(choice == 76){
                        printf("Please enter the last name of person:\n");
                        scanf(" %21s", &search);
                        search_by_firstname(search);
                    } else {
                        printf("Invalid Input!\n");
                    }
                    break;
                case 4:
                    printfile();
                    break;
                case 5:
                    return (0);
            }
        } else {
            printf("Invalid Input!\n");
        }
    }
}

PERSON input_record(void){

}

void write_new_file(PERSON *inrecord){
    remove("records.bin");
    FILE *fp;
    fp = fopen("records.bin", "w");
    fprintf (fp, "%d\n", &inrecord);
    fclose(fp);
}

void printfile(void){

}

void search_by_firstname(char *name){

}

void append_file(PERSON *inrecord){

}

