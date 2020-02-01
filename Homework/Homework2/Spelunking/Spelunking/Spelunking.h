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

class Player
{
    std::vector<int> adjRooms{ std::vector<int>(3) };
    int currRoom;
    void setAdjRooms();

public:
    void setCurrRoom(int r) { currRoom = r; setAdjRooms(); }      
    int room() const { return currRoom; }
    int getAdj(int i) const { return adjRooms[i]; }
};
#endif // !SPELUNKING_H
