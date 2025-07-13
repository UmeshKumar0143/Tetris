#include <raylib.h>
#include "Game.h"


int main(){
    Color darkblue  = {44, 44, 127, 255}; 
    InitWindow(300, 600, "tetrix"); 
    SetTargetFPS(60); 

    Game g = Game(); 


    while(!WindowShouldClose()){
        BeginDrawing(); 
        ClearBackground(darkblue); 
        g.Draw(); 
        EndDrawing(); 
    }

    CloseWindow(); 
}