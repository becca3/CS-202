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

//Move wumpus to random adjacent room.
int Map::moveWumpus()
{
    int r = rand() % 3;
    int pos = 0;

    for (; !(cave[pos].wumpus); ++pos); 
    {
        cave[pos].wumpus = false;
    }

    if ((cave[pos].wumpus && !(cave[pos].bat)) || (cave[pos].wumpus && !(cave[pos].pit)))
    {
        vacant.push_back(pos);
    }

    cave[cave[pos].adjRooms[r]].wumpus = true;

    if (cave[cave[pos].adjRooms[r]].player) 
    {
        std::cout << "The Wumpus got you! LOSER!" << std::endl;
        return END_GAME;
    }
    return 0;
}

//Shoot the Wumpus.
int Map::shoot(int target)
{
    if (target != p1.getAdj(0) && target != p1.getAdj(1) && target != p1.getAdj(2)) 
    {
        std::cout << "Nope. Please choose an ADJACENT room." << std::endl;
        return 0;
    }
    if (cave[target].wumpus) 
    {
        std::cout << "You killed the Wumpus! YOU WIN!" << std::endl;
        return END_GAME;
    }
    else if (cave[p1.getAdj(0)].wumpus || cave[p1.getAdj(1)].wumpus || cave[p1.getAdj(2)].wumpus)
        return moveWumpus();
}

//What happens in a bat encounter.
void Map::batEncounter()
{
    int r = rand() % vacant.size();

    cave[p1.room()].player = false;
    vacant.push_back(p1.room());

    cave[vacant[r]].player = true;
    p1.setCurrRoom(vacant[r]);

    vacant.erase(vacant.begin() + r);
}

//Set map up. Place player, bats, pits and wumpus.
void Map::init()
{
    for (int i = 0; i < ROOMS; ++i) {
        int t = 2 + 2 * (i & 1);
        cave[i].adjRooms[0] = ROOMS - 1 - i;
        cave[i].adjRooms[1] = (i + t) % ROOMS;
        cave[i].adjRooms[2] = (i - t + 20) % ROOMS;
        vacant.push_back(i);
    }

    addPlayer();
    addWumpus();
    addBats();
    addPits();

    for (int i = 0; i < 3; ++i)
        vacant.push_back(p1.getAdj(i));
}

//Play game.
void Map::play()
{
    reportState();
    while (input() != END_GAME) {
        reportState();
    }
}

//Allows user input.
int Map::input()
{
    char x = 0;
    int y = -1;

    std::cout << "Type m (move) followed by room number e.g. m18, \n to move to another room." << std::endl;
    std::cout << "Type s (shoot) followed by room number e.g. s18, \n to shoot an arrow to another room." << std::endl;
  
    while (1) 
    {
        std::cout << "Enter action: ";
        if (std::cin >> x >> y)
        {
            break;
        }

        else if (std::cin.fail() || (x != 'm' && x != 's'))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            std::cout << "Invalid input. Type mXX(sXX) to move(shoot) to(at) room XX." << std::endl;
        }
    }
    return (x == 'm') ? movePlayer(y) : shoot(y);
}

#endif // !SPELUNKING_H
