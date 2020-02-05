/* ====================================
File name: exerc_3_1.c
Date: 2020-02-05
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [<Ass code 1-4> <abc>]Important , No code no exercise points
!====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum DIRECTION { N, E, S, W };
typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void read(char *dirs, int *xpos, int *ypos);
void move(int *xpos, int *ypos, char dir);
void turn(enum DIRECTION *dir);


int main() {
    ROBOT robot;
    robot.dir = 'N';

    char directions[100];
    char *dirs = directions;
    enum DIRECTION *dire = &robot.dir;
    int *posx = &robot.xpos;
    int *posy = &robot.ypos;


    do {
        read(dirs, posx, posy);
        
        int i;
        for (i = 0; i < strlen(directions); i++)
        {
            if (directions[i] != 'm' && directions[i] != 't')
            {
                printf("Invalid input\n");
                break;
            }
        }

        for (i = 0; i < strlen(directions); i++)
        {
            if (directions[i] == 'm') {
                move(posx, posy, robot.dir);

            } else {
                turn(dire);
            }
        }
            printf("Your final position is {%d, %d}\n", *posx, *posy, robot.dir);
    
    } while (*dirs != 'q');
    return 0;
}

void read(char *dirs, int *xpos, int *ypos) {
    printf("Enter starting x position: \n");
    scanf("%d", xpos);
    printf("Enter starting y position: \n");
    scanf("%d", ypos);
    printf("Enter directions\n");
    scanf("%s", dirs);    
}

void move(int *xpos, int *ypos, char dir) {
    switch (dir)
    {
        case 'N':
            (*ypos)++;
            break;
        case 'E':
            (*xpos)++;
            break;
        case 'S':
            (*ypos)--;
            break;
        case 'W':
            (*xpos)--;
            break;
        }
}

void turn(enum DIRECTION *dir) {
    switch (*dir)
    {
    case 78:            // ASCII for 'N'
        *dir = 69;
        break;
    case 69:            // ASCII for 'E'
        *dir = 83;
        break;
    case 83:             // ASCII for 'E'
        *dir = 87;
        break;
    case 87:             // ASCII for 'E'
        *dir = 78;
        break;
    }
}
