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