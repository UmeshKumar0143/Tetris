#include "grid.h"
#include <iostream>
Grid::Grid(){
    numRows = 20 ; 
    numCols = 10; 
    cellSize = 30; 
    initializeGrid(); 
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