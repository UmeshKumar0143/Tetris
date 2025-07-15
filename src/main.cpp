#include <raylib.h>
#include "Game.h"
#include "colors.h"
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
    InitWindow(500, 620, "tetrix"); 
    SetTargetFPS(60); 

    Game g = Game(); 

    Font  font = LoadFontEx("/Font/monogram.ttf", 64, 0, 0); 

    while(!WindowShouldClose()){
        g.HandleInput(); 
        if(isEventTriggerd(0.2)){
            g.MoveBlockDown(); 
        }
        BeginDrawing(); 
        ClearBackground(darkblue); 
        DrawTextEx(font, "Score",{365, 15}, 38, 2, WHITE); 
        DrawTextEx(font, "Next",{370, 175}, 38, 2, WHITE); 
        if(g.gameOver){
            DrawTextEx(font, "Game Over",{320, 450}, 38, 2, WHITE); 

        }
        DrawRectangleRounded({324,55, 170, 60}, 0.3, 6, lightBlue); 
        DrawRectangleRounded({324,215, 170, 180}, 0.3, 6, lightBlue); 
        g.Draw(); 
        EndDrawing(); 
    }

    CloseWindow(); 
}