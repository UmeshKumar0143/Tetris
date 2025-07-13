#pragma once
#include "position.h"
#include <map>
#include <vector>
#include "colors.h"
class Block {
    private: 
        int cellSize; 
        int rotationState;
        std::vector<Color> cellColors ;  
    public:     
        Block();
        void Draw(); 
        int id; 
        std::map<int,std::vector<Position>>cells; 
    
};