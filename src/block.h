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
        int rowOffset; 
        int colOffset; 

    public:     
        Block();
        void Draw(); 
        void Move(int rowOffset, int colOffset); 
        void Rotate(); 
        void undoRotate(); 
        std::vector<Position>getCellPosition(); 
        int id; 
        std::map<int,std::vector<Position>>cells; 
    
};