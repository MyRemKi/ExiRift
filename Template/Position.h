#ifndef POSITION_H
#define POSITION_H
#include <vector>
using std::vector;

#pragma once

class Position
{
public:
    Position();
    
    void UpdatePosition(float x,float y){
        this->x = x;
        this->y = y;
    };

    vector<float> ReturnPosition(){return {x,y};};
    ~Position();

private:
    float x,y;

};

#endif