#ifndef SPELUNKING_H
#define SPELUNKING_H

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

//Struct for creating the rooms. 
struct Room
{
    std::vector<int>adjRooms{ std::vector<int>(3) };
    bool player{ false };
    bool bat{ false };
    bool wumpus{ false };
    bool pit{ false };
};

#endif // !SPELUNKING_H
