#include <stdio.h>
#include <conio.h>
#define SIZE 3
#define PLAYER 'X'
#define COMP 'O'
#define EMPTY '-'


char board[SIZE][SIZE] = {
                            {'-','-','-'},
                            {'-','-','-'},
                            {'-','-','-'}
                        };

struct pos{
    int x,y;
}move;

void display();
void greet(int);
int checkStatus();
int getMoveScore(char);
int main(){
    int status=2,i=0,j=0,x,y,score;
    display();
    printf("PRESS TO START GAME \n");
    getch();
    board[1][1]=COMP;
    display();
    printf("ENTER YOUR POSITION : ");
    scanf("%d",&x);
    scanf("%d",&y);
    board[x][y]=PLAYER;
    while(status==2){

        display();
        score=getMoveScore(COMP);
        // printf("score : %d\n",score );
        board[move.x][move.y]=COMP;
        display();
        status=checkStatus();
        greet(status);
        printf("YOUR TURN : ");
        scanf("%d",&x);
        scanf("%d",&y);
        board[x][y]=PLAYER;
    }

    getch();
    return 0;

}


void display(){
    int i,j;

    for(i=0;i<SIZE;i++){
        printf("\n\n\t");
        for(j=0;j<SIZE;j++){
            printf("  %c  ", board[i][j]);
        }

    }

    printf("\n");
}



int checkStatus(){
        // 0  :  DRAW      1 : PLAYER WINS      -1 : PLAYER LOSS     2 : MORE GAME LEFT

    int i,j;

    if(board[0][0] ==COMP &&  board[1][1] == COMP && board[2][2] == COMP) return -1;
    if(board[0][2] ==COMP &&  board[1][1] == COMP && board[2][0] == COMP) return -1;

    if(board[0][0] ==COMP &&  board[0][1] == COMP && board[0][2] == COMP) return -1;
    if(board[1][0] ==COMP &&  board[1][1] == COMP && board[1][2] == COMP) return -1;
    if(board[2][0] ==COMP &&  board[2][1] == COMP && board[2][2] == COMP) return -1;

    if(board[0][0] ==COMP &&  board[1][0] == COMP && board[2][0] == COMP) return -1;
    if(board[0][1] ==COMP &&  board[1][1] == COMP && board[2][1] == COMP) return -1;
    if(board[0][2] ==COMP &&  board[1][2] == COMP && board[2][2] == COMP) return -1;


    if(board[0][0] ==PLAYER &&  board[1][1] == PLAYER && board[2][2] == PLAYER) return 1;
    if(board[0][2] ==PLAYER &&  board[1][1] == PLAYER && board[2][0] == PLAYER) return 1;

    if(board[0][0] ==PLAYER &&  board[0][1] == PLAYER && board[0][2] == PLAYER) return 1;
    if(board[1][0] ==PLAYER &&  board[1][1] == PLAYER && board[1][2] == PLAYER) return 1;
    if(board[2][0] ==PLAYER &&  board[2][1] == PLAYER && board[2][2] == PLAYER) return 1;

    if(board[0][0] ==PLAYER &&  board[1][0] == PLAYER && board[2][0] == PLAYER) return 1;
    if(board[0][1] ==PLAYER &&  board[1][1] == PLAYER && board[2][1] == PLAYER) return 1;
    if(board[0][2] ==PLAYER &&  board[1][2] == PLAYER && board[2][2] == PLAYER) return 1;

    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(board[i][j]=='-'){
                return 2;
            }
        }
    }
    return 0;


}


void greet(int status){
    if(status==0) printf("DRAW !\n");
    else if(status==1) printf("YOU WIN ! !\n");
    else if(status==-1) printf("LOSER !\n");
}


int getMoveScore(char turn){
    int score;
    int st=checkStatus();
    if(st==1) return 10;
    else if(st==0) return 0;
    else if(st==-1) return -10;

int x,y,status;
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            if(board[i][j]==EMPTY){
                if(turn==COMP){
                   // score = getMoveScore(PLAYER);
                   // board[i][j]=EMPTY;
                    for(x=0;x<SIZE;x++){
                        for(y=0;y<SIZE;y++){
                            if(board[x][y]==EMPTY){
                                board[x][y]=PLAYER;
                                status=checkStatus();
                                board[x][y]=EMPTY;
                                if(status==1){
                                    score=10;
                                    move.x=x;
                                    move.y=y;
                                    return 2;
                                }
                                else if(status==0){
                                    score=0;
                                }
                            }
                        }
                    }
                    board[i][j]=COMP;
                    score = getMoveScore(PLAYER);
                    board[i][j]=EMPTY;


                   if(score==-10){
                    move.x=i;
                    move.y=j;
                   }
                }
                else if(turn==PLAYER){
                    board[i][j]=PLAYER;
                    score= getMoveScore(COMP);

                    board[i][j]=EMPTY;
                    if(score==10){
                        i++;
                        j++;

                    }

                }
            }
        }
    }
    return score;
}
