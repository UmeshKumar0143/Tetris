#include <raylib.h>
#include "Game.h"
#include "colors.h"
#include<iostream>
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
         DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (g.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        std::cout<<g.score<<std::endl; 
        char scoreText[10];
        sprintf(scoreText, "%d", g.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue); 
        g.Draw(); 
        EndDrawing(); 
    }

    CloseWindow(); 
}