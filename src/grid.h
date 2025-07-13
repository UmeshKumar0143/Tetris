#pragma once 
#include<vector>
#include <raylib.h>
class Grid {
   
    private:
    int numRows; 
    int numCols; 
    int cellSize; 
    std::vector<Color>cellColors; 
   
   
    public:
    Grid(); 
    void initializeGrid(); 
    void printGrid();  
    void draw(); 
    int grid[20][10];
}; 