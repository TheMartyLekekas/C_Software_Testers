/* ====================================
File name: exerc_4_3.c
Date: 2020-02-18
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [23422]
!====================================== */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void f_delay(int);
unsigned char random_inport( void);
void printport( int);
char check_hex( int);


int main(){
    int nr;
    char hex;
    unsigned char port;
    srand(time(0));
    for ( nr=0; nr < 10; nr++){
        port = random_inport();
        printport( port);
        f_delay(5);
    }
    return(0);
}


void f_delay( int tenth_sec){
    clock_t start_t, end_t;
    long int i;
    start_t = clock();
    do{
        for(i=0; i< 10000000; i++);
        end_t = clock();
    }while ((end_t - start_t) < (tenth_sec*CLOCKS_PER_SEC)/10);
    return;
}

unsigned char random_inport( void){
    unsigned char inport = 0;
    inport=  rand() % 256;
    return (inport);
}

char check_hex(int portvalue){
    printf(" %d", portvalue);
    return 0;
}

void printport( int portvalue){
    int binchar[8], rest,j, i=0,bool=0, hex;
    rest = portvalue;

    while(rest!=0){
        binchar[i++]= rest % 2;
        rest = rest / 2;
    }
    // Fill to 8 bits
    while( i<8){
        binchar[i++]=0;
    }

    if(portvalue >> 7 == 0){
        bool = 1;
        hex = portvalue&15;
    }

    // Print bits and at the end corresponding decimal value
    for(j =i-1 ;j > -1;j--)
        printf("  %d",binchar[j]);

    if (bool == 1) {
        printf(" Port value = %d Hex = %X \n", portvalue, hex);
    } else {
        printf(" Port value = %d\n", portvalue);
    }

    return ;
}
