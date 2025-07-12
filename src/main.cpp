#include <raylib.h>

int main(){
    Color darkblue  = {44, 44, 127, 255}; 
    InitWindow(300, 600, "tetrix"); 
    SetTargetFPS(60); 
    while(!WindowShouldClose()){
        BeginDrawing(); 
        ClearBackground(darkblue); 
        EndDrawing(); 
    }

    CloseWindow(); 
}