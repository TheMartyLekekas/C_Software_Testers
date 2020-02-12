/* ====================================
File name: exerc_3_3.c
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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct q{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

int main(int argc, char *argv[])
{
    int nr=0, nr2=0;
    REGTYPE *akt_post, *akt_post2 , *head=NULL;

    srand( time(0)); // Random seed

    head=random_list();
    akt_post=head;
    akt_post2 = add_first(akt_post, (rand() % (100 + 1 - 1) + 1));


    while( akt_post!=NULL){
        printf("Post nr %d : %d\n" , nr++, akt_post->number);
        akt_post=akt_post->next;
    }

    printf("After add_first:\n");
    while( akt_post2!=NULL){
        printf("Post nr %d : %d\n" , nr2++, akt_post2->number);
        akt_post2=akt_post2->next;
    }

    while((akt_post=head)!=NULL){
        head=akt_post->next;
        free(akt_post);
    }

    while((akt_post2=head)!=NULL){
        head=akt_post2->next;
        free(akt_post2);
    }
    return 0;
}

REGTYPE* random_list(void){
    int nr = rand() % (100 + 1 - 1) + 1;
    int i=0;

    REGTYPE *top;
    REGTYPE *old;
    REGTYPE *item;

    top = malloc(sizeof(REGTYPE));
    top->number = 0;
    top->prev = NULL;
    old = top;

    while(i != nr){
        i++;
        item = malloc(sizeof(REGTYPE));
        item->number = i;
        item->prev= old;
        old->next = item;
        old = item;
    }
    return(top);
}

REGTYPE* add_first(REGTYPE* temp, int data) {
    REGTYPE *new;
    new = malloc(sizeof(REGTYPE));
    new->number= data;
    new->prev= NULL;
    new->next= temp;
    temp->prev= new;
    return(new);

}