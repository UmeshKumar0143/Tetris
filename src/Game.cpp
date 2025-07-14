#include "Game.h"
#include "blocks.cpp"
#include <random>
#include<iostream>
Game::Game(){
    grid = Grid(); 
    blocks = getAllBlocks(); 
    currentBlock = getRadomBlock(); 

    nextBlock = getRadomBlock(); 
}


Block Game::getRadomBlock(){
   
    if(blocks.empty()){
        blocks  = getAllBlocks(); 
    }
    int randomIndex = rand() % blocks.size(); 
    Block block = blocks[randomIndex]; 
    blocks.erase(blocks.begin()+randomIndex); 
    return block; 
}

std::vector<Block>Game::getAllBlocks(){
    return {JBlock(), LBlock(), IBlock(), OBlock(), TBlock(), SBlock(), ZBlock()}; 
}



void Game::Draw(){
    grid.draw(); 
    currentBlock.Draw(); 
}

void Game::HandleInput(){
    int keyPressed = GetKeyPressed(); 
    switch(keyPressed){
        case KEY_LEFT: 
        MoveBlockLeft(); 
        break; 
        case KEY_RIGHT: 
        MoveBlockRight(); 
        break; 
        case KEY_DOWN: 
        MoveBlockDown(); 
        break; 
        case KEY_UP: 
        RotateBlock(); 
        break; 
    }
}

void Game::MoveBlockLeft(){
    currentBlock.Move(0,-1); 
    std::cout<<isBlockOutside(); 
    if(isBlockOutside() || !BlockFits()) currentBlock.Move(0,1); 
}
void Game::MoveBlockRight(){
    currentBlock.Move(0,1); 
    if(isBlockOutside() || !BlockFits() ) currentBlock.Move(0,-1); 
}
void Game::MoveBlockDown(){
    currentBlock.Move(1,0); 
    if(isBlockOutside() || !BlockFits()) 
    {
        currentBlock.Move(-1,0); 
        LockBlock();     
      }      
}

void Game::RotateBlock(){
    currentBlock.Rotate(); 
    if(isBlockOutside() || !BlockFits()){
        currentBlock.undoRotate();  
    }
}

bool Game::isBlockOutside(){
    std::vector<Position>tiles = currentBlock.getCellPosition(); 
    for(Position item: tiles){
            if(grid.CheckCellOutside(item.row, item.col)) return true; 
    }
    return false; 
}

void Game:: LockBlock(){
    std::vector<Position>tiles = currentBlock.getCellPosition(); 
    for(Position item : tiles){
        grid.grid[item.row][item.col]  = currentBlock.id; 
    }
    currentBlock = nextBlock; 
    nextBlock = getRadomBlock(); 
    grid.ClearFullRows(); 
}


bool Game::BlockFits(){
    std::vector<Position>tiles = currentBlock.getCellPosition(); 

    for(Position item: tiles){
        if(!grid.isCellEmpty(item.row, item.col)) return false ; 
    }
    return true; 
}