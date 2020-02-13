#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// -----Typedefs -------
typedef struct {
    char firstname[20];
    char lastname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

#define file "records.bin"
#define true 1
#define false 0

// Function declaration (to be extend)
void write_new_file(PERSON *inrecord);
void printfile(void); // print out all persons in the file
void search_by_firstname(char *name);// print out person if in list
void append_file(PERSON *inrecord);// appends a new person to the file

int main(void) {
    PERSON ppost;
    int input;
    char search[20], A[20], B[20], C[13], choice;

    while(true){
        printf("-------------------------------------\n"
               "1 Create a new and delete the old file\n"
               "2 Add a new person to the file\n"
               "3 Search for a person in the file\n"
               "4 Print out all in the file\n"
               "5 Exit the program\n"
               "-------------------------------------\n");
        scanf("%d", &input);
        if(input > 0 && input <= 5) {
            switch (input) {
                case 1:
                    write_new_file(&ppost);
                    break;
                case 2:
                    fflush(stdin);
                    PERSON *newPerson = &ppost;

                    printf("Enter your firstname:\n");
                    scanf(" %21s", A);
                    printf("Enter your lastname:\n");
                    scanf(" %21s", B);
                    printf("Enter your personal number:\n");
                    scanf(" %13s", C);

                    strncpy(newPerson->firstname, A, sizeof(newPerson->firstname));
                    strncpy(newPerson->lastname, B, sizeof(newPerson->lastname));
                    strncpy(newPerson->pers_number, C, sizeof(newPerson->pers_number));
					
                    append_file(newPerson);
                    break;
                case 3:
                    /*printf("Search by (F) first name or (L) last name: ");
                    scanf(" %c",&choice);
                    if(choice == 70) {
                     */
                        printf("Please enter the first name of person:\n");
                        scanf(" %21s", search);
                        search_by_firstname(search);
                    /*} else if(choice == 76){
                        printf("Please enter the last name of person:\n");
                        scanf(" %21s", search);
                        search_by_firstname(search);
                    } else {
                        printf("Invalid Input!\n");
                    }*/
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

void write_new_file(PERSON *inrecord){
    char* A = "Robert";
    strncpy(inrecord->firstname, A, sizeof(inrecord->firstname));
    char* B = "Lewandowski";
    strncpy(inrecord->lastname, B, sizeof(inrecord->lastname));
    char* C = "199905118890";
    strncpy(inrecord->pers_number, C, sizeof(inrecord->pers_number));

    remove(file);
    FILE *fp;
    fp = fopen(file, "wb");
    fwrite(inrecord->firstname, 20,1,fp);
    fwrite("\n",sizeof(char),1,fp);
    fwrite(inrecord->lastname, 20,1,fp);
    fwrite("\n",sizeof(char),1,fp);
    fwrite(inrecord->pers_number, 13,1,fp);
    fclose(fp);
}

void printfile(void){
    char filename[] = {"records.bin"};
    FILE *fp;
    fp=fopen(filename,"rb");
    char s;
    fp=fopen(file,"rb");
    while((s=fgetc(fp))!=EOF) {
        printf("%c",s);
    }
    printf("\n");
    fclose(fp);
}

void search_by_firstname(char *name){
    FILE *fp;
    fp = fopen(file, "r");
    char *line = NULL;
    int i = 0;
    int found = false;
    size_t len = 0;
    ssize_t readline;

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
    } else {
        while ((readline = getline(&line,&len, fp)) != -1) {
            if (strcmp(line, name) == 0) {
                found = true;
                i = 0;
            }
            if (found == true) {
                if (i == 0) {
                    i++;
                    printf("%20s", line);
                    printf("\n");
                } else if (i == 1) {
                    printf("%20s", line);
                    printf("\n");
                } else if (i == 2) {
                    printf("%13s", line);
                    printf("\n");
                }
            }
        }
    }
}

void append_file(PERSON *inrecord){
    FILE *fp;
    fp = fopen(file, "ab");

    if (fp == NULL) {
        printf("Error opening %s\n",file);
    } else {
        fwrite("\n",sizeof(char),1,fp);
        fwrite(inrecord->firstname, 20,1,fp);
        fwrite("\n",sizeof(char),1,fp);
        fwrite(inrecord->lastname, 20,1,fp);
        fwrite("\n",sizeof(char),1,fp);
        fwrite(inrecord->pers_number, 13,1,fp);
        puts("File has been updated successfully!\n");
        fclose(fp);
    }
}
