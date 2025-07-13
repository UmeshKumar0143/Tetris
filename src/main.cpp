#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"
int main(){
    Color darkblue  = {44, 44, 127, 255}; 
    InitWindow(300, 600, "tetrix"); 
    SetTargetFPS(60); 

    Grid grid= Grid();
    grid.printGrid();  
    JBlock block = JBlock();          

    while(!WindowShouldClose()){
        BeginDrawing(); 
        ClearBackground(darkblue); 
        grid.draw(); 
        block.Draw(); 
        EndDrawing(); 
    }

    CloseWindow(); 
}