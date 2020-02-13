#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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

                    PERSON person;
                    PERSON *newPerson = &person;

                    printf("Enter your firstname:\n");
                    fgets(newPerson-> firstname, 20, stdin);

                    printf("Enter your lastname:\n");
                    fgets(newPerson-> lastname, 20, stdin);

                    printf("Enter your personal number:\n");
                    fgets(newPerson-> pers_number, 13, stdin);

                    fflush(stdin);
                    append_file(newPerson);
                    break;
                case 3:
                    printf("Search by (F) first name or (L) last name: ");
                    scanf(" %c",&choice);
                    if(choice == 70) {
                        printf("Please enter the first name of person:\n");
                        scanf(" %21s", search);
                        search_by_firstname(search);
                    } else if(choice == 76){
                        printf("Please enter the last name of person:\n");
                        scanf(" %21s", search);
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

    char* A = "Robert";
    strncpy(inrecord->firstname, A, sizeof(inrecord->firstname));
    char* B = "Lewandowski";
    strncpy(inrecord->lastname, B, sizeof(inrecord->lastname));
    char* C = "199905118890";
    strncpy(inrecord->pers_number, C, sizeof(inrecord->pers_number));

    remove("records.bin");
    FILE *fp;
    fp = fopen("records.bin", "wb");
    fprintf (fp, "%d\n", &inrecord);
    fclose(fp);
}

void printfile(void){
    char filename[] = {"records.bin"};
    FILE *fp;
    fp=fopen(filename,"rb");
    char s;
    if (fp == NULL) {
      printf("Error opening %s\n",filename);
    } else {
      while((s=fgetc(fp))!=EOF) {
          printf("%c",&s);
      }
      printf("\n");
      fclose(fp);
    }


}

void search_by_firstname(char *name){
    FILE *fp;
    int line, col;
    fp = fopen("records.bin", "rb");
    char str[sizeof(name)];
    char *pos;

    line = -1;
    col  = -1;

    while ((fgets(str, sizeof(name), fp)) != NULL)
    {
        line += 1;

        pos = strstr(str, name);
        if (pos != NULL)
        {
            col = (pos - str);
            break;
        }
    }

    if (col == -1)
        line = -1;

    printf("%d",&col);

}

void append_file(PERSON *inrecord){
  char filename[] = {"records.bin"};
  FILE *fp;
  fp = fopen(filename, "ab");

  if (fp == NULL) {
    printf("Error opening %s\n",filename);
  } else {
    fwrite(inrecord, 20,1 , fp);
    puts("File has been updated successfully!\n");
    fclose(fp);
  }
}
