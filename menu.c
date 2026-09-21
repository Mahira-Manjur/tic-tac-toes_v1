#include <stdio.h>

int showYourself(){
    
    int x;
    printf("   TIC TAC TOE   \n");
    printf("1. Player vs. Player\n2. Player vs. AI1\n3. Player vs. AI2\n4. Player vs. AI3\n");
    printf("Enter your choice :");
    scanf("%d",&x);   
    return x;
}