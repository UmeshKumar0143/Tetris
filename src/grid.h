#pragma once 
#include<vector>
#include <raylib.h>
class Grid {
   
    private:
    int numRows; 
    int numCols; 
    int cellSize; 
    std::vector<Color>cellColors; 
    std::vector<Color>getCellColors();   
   
   
    public:
    Grid(); 
    void initializeGrid(); 
    void printGrid();  
    int grid[20][10];
}; 