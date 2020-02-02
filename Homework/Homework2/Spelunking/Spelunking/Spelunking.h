#ifndef SPELUNKING_H
#define SPELUNKING_H

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

const int ROOMS = 20;
const int BATS = 3;
const int PITS = 3;

const int END_GAME = -1;

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

//Prints the room state to the player.
void Map::reportState()
{
    std::cout << "You are in room " << p1.room() << std::endl;
    std::cout << "Adjacent rooms are " << p1.getAdj(0) << ", " << p1.getAdj(1)
        << ", " << p1.getAdj(2) << std::endl;

    if (cave[p1.getAdj(0)].bat || cave[p1.getAdj(1)].bat || cave[p1.getAdj(2)].bat)
    {
        std::cout << "Bats are near." << std::endl;
    }

    if (cave[p1.getAdj(0)].pit || cave[p1.getAdj(1)].pit || cave[p1.getAdj(2)].pit)
    {
        std::cout << "You feel a cool draft." << std::endl;
    }

    if (cave[p1.getAdj(0)].wumpus || cave[p1.getAdj(1)].wumpus || cave[p1.getAdj(2)].wumpus)
    {
        std::cout << "You can smell the Wumpus!!" << std::endl;
    }
}

int Map::movePlayer(int pos)
{
    if (pos != p1.getAdj(0) && pos != p1.getAdj(1) && pos != p1.getAdj(2))
    {
        std::cout << "Nope. Choose an adjacent room." << std::endl;
        return 0;
    }

    cave[p1.room()].player = false;
    cave[pos].player = true;

    vacant.push_back(p1.room());
    p1.setCurrRoom(pos);

    if (cave[p1.room()].wumpus)
    {
        std::cout << "The Wumpus killed you! LOSER!" << std::endl;
        return END_GAME;
    }

    if (cave[p1.room()].pit) 
    {
        std::cout << "You fell into a bottomless pit! LOSER." << std::endl;
        return END_GAME;
    }

    if (cave[p1.room()].bat) 
    {
        std::cout << "A giant bat took you to another room!" << std::endl;
        batEncounter();
        return 0;
    }
}
#endif // !SPELUNKING_H
