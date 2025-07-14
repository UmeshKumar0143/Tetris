#include "grid.h"
#include <iostream>
#include  "colors.h"
#include<vector>
#include<raylib.h>
Grid::Grid(){
    numRows = 20 ; 
    numCols = 10; 
    cellSize = 30; 
    initializeGrid(); 
    cellColors = getCellColors(); 
} 


void Grid::initializeGrid(){
    for(int row=0; row<numRows; row++){
        for(int col=0; col<numCols; col++){
            grid[row][col] = 0; 
        }
    }
}


void Grid:: printGrid(){
      for(int row=0; row<numRows; row++){
        for(int col=0; col<numCols; col++){
            std::cout<<grid[row][col]; 
        }
        std::cout << std::endl;
    }
}



void Grid::draw(){
    for(int row =0; row<numRows; row++){
        for(int col = 0; col<numCols; col++){
            int cellValue = grid[row][col]; 
            DrawRectangle(cellSize*col+1, cellSize*row+1 , cellSize-1, cellSize-1, cellColors[cellValue]); 
        }
    }   
}

bool Grid::CheckCellOutside(int row, int col){
        if(col>=0 && col<numCols && row>=0 && row<numRows) return false; 
        return true; 
}

bool Grid::isCellEmpty(int row, int col){
    if(grid[row][col]==0) return true; 
    return false;  
}