#include <stdio.h>
#include "menu.h"
#include "game.h"
#include "board.h"
void afterModePicked(int module){
    if(module==1){
        printf("Player vs Player mode selected\n");
    }
    else if(module==2){
        printf("Player vs AI1 mode selected\n");
    }
    else if(module==3){
        printf("Player vs AI2 mode selected\n");
    }
    else if(module==4){
        printf("Player vs AI3 mode selected\n");
    }
    else{
        printf("Invalid choice\n");
    }
    return 0;
}
int main(){
    int module = showYourself();
    afterModePicked(module);
    return 0;
}