/*
Author: Rebecca Morgan
Date: 31/01/2020
Class: CS 202
Description: Hunt the Wumpus game for cs 202.
*/

#include "Spelunking.h"

const int ROOMS = 20;
const int BATS = 3;
const int PITS = 3;

const int END_GAME = -1;

void Player::setAdjRooms()
{
    int t = 2 + 2 * (currRoom & 1);
    adjRooms[0] = ROOMS - 1 - currRoom;
    adjRooms[1] = (currRoom + t) % ROOMS;
    adjRooms[2] = (currRoom - t + 20) % ROOMS;
}
