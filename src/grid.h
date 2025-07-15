#pragma once 
#include<vector>
#include <raylib.h> 
class Grid {
   
    private:
    int numRows; 
    int numCols; 
    int cellSize; 
    std::vector<Color>cellColors; 
    bool isRowFull(int row); 
    void clearRow(int row); 
    void MoveRowdown(int row, int compRows); 

    public:
    Grid(); 
    bool CheckCellOutside(int row , int col); 
    void initializeGrid();  
    void printGrid();  
    void draw(); 
    int grid[20][10];
    bool isCellEmpty(int row, int col); 
    int ClearFullRows(); 
}; 