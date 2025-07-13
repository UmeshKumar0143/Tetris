#include "block.h"

Block::Block(){
    cellSize = 30 ; 
    rotationState = 0; 
    cellColors = getCellColors(); 
    rowOffset = 0; 
    colOffset  =0; 
}

void Block:: Draw(){
        std::vector<Position>tiles = getCellPosition(); 

        for(Position item: tiles){
            DrawRectangle(item.col*cellSize+1,item.row*cellSize+1,cellSize-1,cellSize-1,cellColors[id]); 
        }
}

void Block::Move(int row, int col){
    rowOffset+= row; 
    colOffset+= col; 
}

std::vector<Position> Block::getCellPosition(){
    std::vector<Position>tiles = cells[rotationState]; 
    std::vector<Position> movedTiles; 

    for(Position item: tiles){
        Position newPos = Position(item.row+rowOffset, item.col+colOffset); 
        movedTiles.push_back(newPos); 
    }
    return movedTiles; 
}