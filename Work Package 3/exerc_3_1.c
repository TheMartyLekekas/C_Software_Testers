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
Demonstration code: [42395]
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

int read(char *dirs, int *xpos, int *ypos);
void move(int *xpos, int *ypos, char dir);
void turn(enum DIRECTION *dir);


int main(void) {
    ROBOT robot;
    robot.dir = 'N';

    char directions[100];
    char *dirs = directions;
    enum DIRECTION *dire = &robot.dir;
    int *posx = &robot.xpos;
    int *posy = &robot.ypos;


    do {
        robot.dir = 'N';
        int check = read(dirs, posx, posy);
        if(check == 1)
        {
            int i;
            for (i = 0; i < strlen(directions); i++)
            {
                if (directions[i] == 'm') {
                    move(posx, posy, robot.dir);

                } else {
                    turn(dire);
                }
            }
                printf("Robot's final position is {%d, %d}\n\n", *posx, *posy, robot.dir);
        }

    } while (*dirs != 'q');
    return 0;
}

int read(char *dirs, int *xpos, int *ypos) {
    char xinput[2], yinput[2];
    
    printf("Enter starting x position (0-99): ");
    scanf("%s", xinput);
    *xpos = atoi(xinput);
    if (!isdigit(*xinput) || *xpos < 0 || *xpos > 99)
    {
        printf("Invalid coordinates\n");
        return 0;
    }

    printf("Enter starting y position (0-99): ");
    scanf("%s", yinput);
    *ypos = atoi(yinput);
    if (!isdigit(*yinput) || *ypos < 0 || *ypos > 99)
    {
        printf("Invalid coordinates\n");
        return 0;
    }

    printf("Enter directions {m, t}\n");
    scanf("%s", dirs);
    int i;
    for (i = 0; i < strlen(dirs); i++)
    {
        if (dirs[i] != 'm' && dirs[i] != 't')
        {
            printf("Invalid directions\n");
            return 0;
        }
    }
        return 1;
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
    case 83:            // ASCII for 'S'
        *dir = 87;
        break;
    case 87:            // ASCII for 'W'
        *dir = 78;
        break;
    }
}