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
    int randomIndex = rand() % blocks.size(); 
    if(blocks.empty()){
        blocks  = getAllBlocks(); 
    }
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
