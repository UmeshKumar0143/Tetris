#include "grid.h"
#include <iostream>
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

std::vector<Color> Grid:: getCellColors(){
        Color darkGrey = {26,31,40,255}; 
        Color red = {232,18,18,255}; 
        Color blue = {13,64,216,255}; 
        Color green = {47,230,23,255}; 
        Color yellow = {237,234,4,255}; 
        Color orange = {236,116,17,255}; 
        Color purple = {116,0,247,255}; 
        Color cyan = {21,204,209,255};
        
        return {darkGrey, red , blue, green, yellow, orange, purple, cyan}; 
}

void Grid::draw(){
    for(int row =0; row<numRows; row++){
        for(int col = 0; col<numCols; col++){
            int cellValue = grid[row][col]; 
            DrawRectangle(cellSize*col+1, cellSize*row+1 , cellSize-1, cellSize-1, cellColors[cellValue]); 
        }
    }   
}