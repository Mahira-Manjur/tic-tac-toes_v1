void startGme(int module){
    char board[3][3];
    createBoard(board);
    showboard(board);
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
    int index= playerMove();
    char c1='X';
    validMovecheck(board,index,c1);
    puttingInput(board,index,c1);
}
void playerVsAI1(char board[3][3]){
    
}
void playerVsAI2(char board[3][3]){
    
}
void playerVsAI3(char board[3][3]){
    
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
    int cnt=1;
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