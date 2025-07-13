#pragma once 
#include "grid.h"
#include "block.h"

class Game{
    private: 
    std::vector<Block>blocks; 
    Block currentBlock; 
    Block nextBlock; 

    public: 
    Game(); 
    void Draw(); 
    std::vector<Block>getAllBlocks(); 
    Block getRadomBlock(); 
    Grid grid; 

}; 