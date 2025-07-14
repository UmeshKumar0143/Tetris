#include <raylib.h>
#include "Game.h"

double lastUpdatedTime = 0; 

bool isEventTriggerd(double interval){
    double currentTime = GetTime(); 
    if(currentTime-lastUpdatedTime>=interval){
        lastUpdatedTime  = currentTime; 
        return true; 
    }
    return false; 
}


int main(){
    Color darkblue  = {44, 44, 127, 255}; 
    InitWindow(300, 600, "tetrix"); 
    SetTargetFPS(60); 

    Game g = Game(); 


    while(!WindowShouldClose()){
        g.HandleInput(); 
        if(isEventTriggerd(0.2)){
            g.MoveBlockDown(); 
        }
        BeginDrawing(); 
        ClearBackground(darkblue); 
        g.Draw(); 
        EndDrawing(); 
    }

    CloseWindow(); 
}