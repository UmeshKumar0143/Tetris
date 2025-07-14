#pragma once 
#include "grid.h"
#include "block.h"

class Game{
    private: 
    std::vector<Block>blocks; 
    Block currentBlock; 
    Block nextBlock; 
    bool isBlockOutside(); 
    void LockBlock(); 
    void RotateBlock();     
    bool BlockFits(); 
    bool gameOver; 
    void reset(); 
    public: 
    Game(); 
    void Draw(); 
    std::vector<Block>getAllBlocks(); 
    Block getRadomBlock(); 
    void HandleInput(); 
    void MoveBlockLeft(); 
    void MoveBlockRight(); 
    void MoveBlockDown(); 
    Grid grid; 

}; 