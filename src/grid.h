#pragma once 

class Grid {
    private:
    int numRows; 
    int numCols; 
    int cellSize; 

    public:
    Grid(); 
    void initializeGrid(); 
    void printGrid();  
    int grid[20][10];  
}; 