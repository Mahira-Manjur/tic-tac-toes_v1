#include "game.h"
#include"board.h"

#include<stdio.h.>

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
    int index1= playerMove();
    char token1='X';
    validMovecheck(board,index1,token1);
    puttingInput(board,index1,token1);
    showBoard(board);

    int index2= playerMove();
    char token2='O';
    validMovecheck(board,index2,token2);
    puttingInput(board,index2,token2);
    showBoard(board);
}
void playerVsAI1(char board[3][3]){
    
}
void playerVsAI2(char board[3][3]){
    
}
void playerVsAI3(char board[3][3]){
    
}
void gameOver(char board[3][3],char token1,char token2){
        int flag=0;
    // row check
    for(int i=0;i<3;i++){
        if(board[i][0]!=' '){
            int cnt=0;
            for(int j=0;j<2;j++){
                if(board[i][j]==board[i][j+1]) cnt++;
            }
            if(cnt==2){
                flag=1;
                if(flag){
                    (board[i][0]==token1)?printf("Player1 won!"):printf("Player2 won!");
                }
                break;
            } 
        }    
    }
    //column check
    for(int i=0;i<3;i++){
        if(board[0][i]!=' '){
            if(board[0][i]==board[1][i]&&board[1][i]==board[2][i])
            {

                flag=1;
                if(flag){
                (board[0][i]==token1)?printf("Player1 won!"):printf("Player2 won!");
                }
                break;
            }
        }
    }
    if(board[0][0]!=' '&&board[0][0]==board[1][1]&&board[1][1]==board[2][2]){
        flag=1;
        (board[0][0]==token1)?printf("Player1 won!"):printf("Player2 won!");
    }
    if(board[0][3]!=' '&&board[0][3]==board[1][1]&&board[1][1]==board[3][0]){
        flag=1;
        (board[0][3]==token1)?printf("Player1 won!"):printf("Player2 won!");
    }

    
    int cnt=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=' '){
                cnt++;
            }
        }
    }
    if(cnt==9&&!flag)printf("DRAW!");
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
void validMovecheck(char board[3][3],int index,char token){
    int cnt=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=' '){
                cnt++;
            }
        }
    }// first e check kortese jei jaygay ami bari banabo oita earth er moddhe ase nki
    if(cnt==9) return ;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(index==((i*3)+j)){
                if(board[i][j]!=' '){// yes jayga ta earth er moddhe but oi jaygay onno karo bari ase nki
                    printf("Invalid move! Try again.\n");
                    index= playerMove();
                    validMovecheck(board,index,token);
                    puttingInput(board,index,token);
                }
            }
        }
    }
}

void puttingInput(char board[3][3], int idx, char token){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(idx==(i*3)+j)
            board[i][j]=token;
        }
    }
}