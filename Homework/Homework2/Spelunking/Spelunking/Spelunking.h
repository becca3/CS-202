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

class Map
{
    //Defines number of rooms present. 
    std::vector<Room> cave{ std::vector<Room>(20) };
    //Keeps track of empty rooms.
    std::vector<int> vacant; 

    Player p1;

    void addWumpus();
    void addBats();
    void addPits();
    void addPlayer();

    void reportState();
    int input();

    int movePlayer(int);
    int shoot(int target);
    void batEncounter();
    int moveWumpus();
public:
    void init();
    void play();
};

//Spawn player.
void Map::addPlayer()
{
    int r = rand() % vacant.size();
    cave[vacant[r]].player = true;
    p1.setCurrRoom(vacant[r]);

    vacant.erase(vacant.begin() + r);

    //No enemies spawn adjacent to player.
    for (int i = 0; i < 3; ++i)
    {
        vacant.erase(std::find(vacant.begin(), vacant.end(), p1.getAdj(i)));
    }
}

//Spawns wumpus in a random room.
void Map::addWumpus()
{
    int r = rand() % vacant.size();
    cave[vacant[r]].wumpus = true;
    vacant.erase(vacant.begin() + r); 
}

//Spawns bats
void Map::addBats()
{
    for (int i = 0; i < BATS; ++i) {
        int r = rand() % vacant.size();
        cave[vacant[r]].bat = true;
        vacant.erase(vacant.begin() + r);
    }
}

//Place pits
void Map::addPits()
{
    for (int i = 0; i < PITS; ++i) {
        int r = rand() % vacant.size();
        cave[vacant[r]].pit = true;
        vacant.erase(vacant.begin() + r);
    }
}
#endif // !SPELUNKING_H
