#include <stdio.h>
#include "menu.h"
#include "game.h"
#include "board.h"
#include "raylib.h"
//#include "raygui.h"
#include "ttt.h"
#include "board_render.h"

// void afterModePicked(int module){
//     if(module==1){
//         printf("Player vs Player mode selected\n");
//     }
//     else if(module==2){
//         printf("Player vs AI1 mode selected\n");
//     }
//     else if(module==3){
//         printf("Player vs AI2 mode selected\n");
//     }
//     else if(module==4){
//         printf("Player vs AI3 mode selected\n");
//     }

//     else{
//         printf("Invalid choice\n");
//     }
    
// }
// int main(){
//     int module = showYourself();
//     afterModePicked(module);
//     char board[3][3];
//     // createBoard(board);
//     // showBoard(board);
//     startGame(module,board);
//     return 0;
// }

int main(){
    InitWindow(WINDOW_W, WINDOW_H, "TIC-TAC-TOE");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Tic-Tac-Toe is running",50,20,40,PURPLE);
        drawGrid();
        drawToken(0,'X');
        drawToken(1,'O');
        EndDrawing();
    }
    CloseWindow();
    return 0;
}