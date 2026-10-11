#include "game.h"
#include"board.h"
#include <stdbool.h>
#include<stdio.h.>
#include <stdlib.h>
#define WIN 1
#define DRAW 2
int number;

void gameOverText(int number){
    if(number==0){
        printf("Player 1 won");
    }
    else if(number==1){
        printf("Player 2 won");
    }
    else if(number==2){
        printf("Player won");
    }
    else if(number==3){
        printf("A1 won");
    }
    else if(number==4){
        printf("A2 won");
    }
    else if(number==5){
        printf("A3 won");
    }
    else if(number==6){
         printf("DRAW!");
    }else if(number==7){

    }
}

void startGame(int module,char board[3][3]){
    createBoard(board);
    showBoard(board);
    if(module==1){
        playerVsPlayer(board);
    }
    else if(module==2){
        playerVsAI1(board);
    }
    else if(module==3){
        playerVsAI2(board);
    }
    else if(module==4){
        playerVsAI3(board);
    } 
}

void playerVsPlayer(char board[3][3]){
    while(1){
        int index1;
        char token1='X';
        char token2='O';

        do{
            index1=playerMove();
        }while(!validMoveCheck(board,index1));
        
        puttingInput(board,index1,token1);
        showBoard(board);
        
        if(gameOver(board,token1,token2)==WIN){
            gameOverText(0);
            break;
        }
        else if(gameOver(board,token1,token2)==DRAW){
            gameOverText(6);
        }
        int index2;
        
        do{
            index2=playerMove();
        }while(!validMoveCheck(board,index2));
        
        puttingInput(board,index2,token2);
        showBoard(board);

        if(gameOver(board,token1,token2)==WIN){
            gameOverText(1);
            break;
        }else if(gameOver(board,token1,token2)==DRAW){
            gameOverText(6);
        }
    }
    
}
void playerVsAI1(char board[3][3]){
    while(1){
        int index1;
        char token1='X';
        char token2='O';

        do{
            index1=playerMove();
        }while(!validMoveCheck(board,index1));
        
        puttingInput(board,index1,token1);
        showBoard(board);
        if(gameOver(board,token1,token2)==WIN){
            gameOverText(2);
            break;
        }else if(gameOver(board,token1,token2)==DRAW){
            gameOverText(6);
        }
        int index2;
        
        do{
            index2=rand()%9;
        }while(!validMoveCheck(board,index2));
        
        puttingInput(board,index2,token2);
        showBoard(board);
        if(gameOver(board,token1,token2)==WIN){
            gameOverText(3);
            break;
        }else if(gameOver(board,token1,token2)==DRAW){
            gameOverText(6);
        }
    }
}
void playerVsAI2(char board[3][3]){
    while(1){
        int index1;
        char token1='X';
        char token2='O';

        do{
            index1=playerMove();
        }while(!validMoveCheck(board,index1));
            
        puttingInput(board,index1,token1);
        showBoard(board);
        if(gameOver(board,token1,token2)==WIN){
            gameOverText(2);
            break;
        }
        else if(gameOver(board,token1,token2)==DRAW){
            gameOverText(6);
        }

        int index2;
        int caseTrue=0;
        if(!caseTrue){
            for(index2=0;index2<9;index2++){
            //1st case
                if(validMoveCheck(board,index2)){
                    board[index2/3][index2%3]=token2;
                    if(gameOver(board,token1,token2)==1){
                    
                        showBoard(board);
                        gameOverText(7);
                        caseTrue=1;
                        break;
                    }
                    else{
                        board[index2/3][index2%3]=' ';
                    }
                }  
            }
        }
        if(!caseTrue){
            for(index2=0;index2<9;index2++){
                //2nd case
                if(validMoveCheck(board,index2)){
                    board[index2/3][index2%3]=token1;
                    if(gameOver(board,token1,token2)==1){
                        board[index2/3][index2%3]=token2;
                        showBoard(board);
                        gameOverText(7);
                        caseTrue=1;
                        break;
                    }
                
                    else{
                        board[index2/3][index2%3]=' ';
                    }
                }
            }
        }
        if(!caseTrue){
            do{
                index2=rand()%9;
            }while(!validMoveCheck(board,index2));

            puttingInput(board,index2,token2);
            showBoard(board);
        }   
        if(gameOver(board,token1,token2)==WIN){
                gameOverText(4);
                break;
        }else if(gameOver(board,token1,token2)==DRAW){
            gameOverText(6);
            break;
        }
    }
}
void playerVsAI3(char board[3][3]){
    
    int index1;
    int index2;
    char token1='X';
    char token2='O';
    bool firstMove=true;    
    while(1){
        if(firstMove){
            index2=4
            ;
            puttingInput(board,index2,token2);
            showBoard(board);
            firstMove=false;
            
        }
        else{
            int caseTrue=0;
                if(!caseTrue){
                    for(index2=0;index2<9;index2++){
                    //1st case
                        if(validMoveCheck(board,index2)){
                            board[index2/3][index2%3]=token2;
                            if(gameOver(board,token1,token2)==1){
                            
                                showBoard(board);
                                gameOverText(7);
                                caseTrue=1;
                                break;
                            }
                            else{
                                board[index2/3][index2%3]=' ';
                            }
                        }  
                    }
                }
                if(!caseTrue){
                    for(index2=0;index2<9;index2++){
                        //2nd case
                        if(validMoveCheck(board,index2)){
                            board[index2/3][index2%3]=token1;
                            if(gameOver(board,token1,token2)==1){
                                board[index2/3][index2%3]=token2;
                                showBoard(board);
                                gameOverText(7);
                                caseTrue=1;
                                break;
                            }
                        
                            else{
                                board[index2/3][index2%3]=' ';
                            }
                        }
                    }
                }
                //3rd case
                if(!caseTrue){
                    do{
                        index2=rand()%9;
                    }while(!validMoveCheck(board,index2));

                    puttingInput(board,index2,token2);
                    showBoard(board);
                }
                
                //winner declare
                if(gameOver(board,token1,token2)==WIN){
                        gameOverText(5);
                        break;
                }else if(gameOver(board,token1,token2)==DRAW){
                    gameOverText(6);
                    break;
                }
            }
        do{
            index1=playerMove();
        }while(!validMoveCheck(board,index1));
            
        puttingInput(board,index1,token1);
        showBoard(board);
        if(gameOver(board,token1,token2)==WIN){
            gameOverText(2);
            break;
        }
        else if(gameOver(board,token1,token2)==DRAW){
            gameOverText(6);
        }
    }
}


int gameOver(char board[3][3],char token1,char token2){
        int flag=!WIN;
    // row check
    for(int i=0;i<3;i++){
        if(board[i][0]!=' '){
            int cnt=0;
            for(int j=0;j<2;j++){
                if(board[i][j]==board[i][j+1]) cnt++;
            }
            if(cnt==2){
                flag=WIN;
                // if(flag){
                //     number=
                //     (board[i][0]==token1)?gameOverText(0):printf("Player2 won!\n");
                // }
                break;
            } 
        }    
    }
    //column check
    for(int i=0;i<3;i++){
        if(board[0][i]!=' '){
            if(board[0][i]==board[1][i]&&board[1][i]==board[2][i])
            {

                flag=WIN;
                // if(flag){
                // (board[0][i]==token1)?printf("Player1 won!\n"):printf("Player2 won!\n");
                // }
                break;
            }
        }
    }
    if(board[0][0]!=' '&&board[0][0]==board[1][1]&&board[1][1]==board[2][2]){
        flag=WIN;
        //(board[0][0]==token1)?printf("Player1 won!\n"):printf("Player2 won!\n");
    }
    if(board[0][2]!=' '&&board[0][2]==board[1][1]&&board[1][1]==board[2][0]){
        flag=WIN;
        //(board[0][2]==token1)?printf("Player1 won!\n"):printf("Player2 won!\n");
    }

    
    int cnt=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=' '){
                cnt++;
            }
        }
    }
    if(cnt==9&&!flag){
        flag=DRAW;
    }
    return flag;
}

int playerMove(){
    int row,col;
    printf("Enter row and column (1-3): ");
    scanf("%d %d", &row, &col);
    if(row<1 || row>3 || col<1 || col>3){
        return playerMove();
    }
    return ((row-1)*3+col-1);
}
int validMoveCheck(char board[3][3],int index){
    return board[index/3][index%3]==' ';
}


void puttingInput(char board[3][3], int idx, char token){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(idx==(i*3)+j)
            board[i][j]=token;
        }
    }
}