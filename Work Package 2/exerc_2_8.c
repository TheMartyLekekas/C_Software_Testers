#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>

#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

int human_choice(int pile);
void write_winner( int player );
int play_again();
int computer_choice(int pile);
int toggle( int player );
void clear_stdin();

int main()
{
    int playAgainC;
    printf("Welcome to NIM by Sebastian Baszczynski\n");

    while(playAgainC == 0) {
        int pile,player,n_coins; /*coins taken*/
        srand( time(0) );		/* Setup random */

        pile = MAX_COINS;		/* Set start values (= init) */
        player = HUMAN;

            while (true) {
                printf("There are %d on the pile\n", pile);


                if (player == HUMAN) {
                    n_coins = human_choice(pile);
                } else {
                    n_coins = computer_choice(pile);
                    printf("- I took %d\n", n_coins);
                }
                pile -= n_coins;
                player = toggle(player);

                if (pile <= 1) {
                    break;
                }
            }
        write_winner(player);
        playAgainC = play_again();
    }
    printf("Completed\n");
    return 0;
}

void clear_stdin()
{
    while( getchar() != '\n' ){
        ;
    }
}

int human_choice(int pile){
    int c_chosen;
    if(pile >= 3){
        while(true) {
            printf("Please choose between 1-3 coins\n");
            scanf("%d", &c_chosen);
            if(c_chosen > 0 && c_chosen <= 3) {
                return c_chosen;
            }else{
                printf("Error! Wrong amount! ");
            }
        }
    }else{
        while(true) {
            printf("Please choose between 1-%d coins\n", pile);
            scanf("%d", &c_chosen);
            if(c_chosen > 0 && c_chosen <= pile) {
                return c_chosen;
            }else{
                printf("Error! Wrong amount! ");
            }
        }
    }
}

int computer_choice(int pile)
{
    if(pile > 4){
        return (rand() % (3 + 1 - 1) + 1);
    }else{
        return (pile - 1);
    }
}

void write_winner(int player ){
    if(player == 1){
        printf("Winner is Player!\n");
    }else{
        printf("Winner is Computer!\n");
    }
}

int play_again(){
    char choice;
    while(true) {
        printf("Play again? (Y or N)\n");
        scanf(" %c", &choice);
        if (choice == 89){ // 89 IS ASCII FOR CHARACTER Y
            return 0;
        } else if (choice == 78) { // 78 IS ASCII FOR CHARACTER 3
            return 1;
        } else {
            printf("Error! Incorrect character! ");
        }
    }
}

int toggle( int player )
{
    if (player == 0){
        return 1;
    } else {
        return 0;
    }
}
