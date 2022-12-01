// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Player Header File


#include <iostream>
#include "player.h"
using namespace std;

Player :: Player()
{
    int num_items = 5;
    int ghosts_saved = 0;
    int moves_made = 0;
    int remnants_collected = 0;
    bool key_found = false;
    bool escaped = false;
    bool flashlight_found = false;
}

void Player :: printMyItems()
{
    for (int i = 0; i < 5; i++)
    {
        cout << my_items[i] << ", "; 
    }
    return;
}

int Player :: getNumItems()
{
    return num_items;
}

void Player :: setNumItems(int new_item_num)
{
    num_items = new_item_num;
}

int Player :: getRemnants()
{
    return remnants_collected;
}

void Player :: addRemnants()
{
    remnants_collected++;
}

void Player :: subRemnants()
{
    remnants_collected++;
}

bool Player :: getKeyFound()
{
    return key_found;
}

void Player :: setFoundKey(bool is_found)
{
    key_found = is_found;
}

bool Player :: isEscaped()
{
    return escaped;
}

void Player :: addGhostsSaved()
{
    ghosts_saved++;
}

int Player :: getGhostsSaved()
{
    return ghosts_saved;
}

bool Player :: isFlashlightFound()
{
    return flashlight_found;
}

void Player :: setFlashlightFound(bool is_found)
{
    flashlight_found = is_found;
}

void Player :: setEscaped(bool is_escaped)
{
    escaped = is_escaped;
}

void Player :: setGhostsSaved(int ghosts)
{
    ghosts_saved = ghosts;
}

void Player :: addItem()
{
    num_items++;
}

void Player :: addMyItem(string item)
{
    my_items[num_items] = item;
}

int Player :: getCandy()
{
    return num_candy;
}

void Player :: addCandy()
{
    num_candy++;
}

void Player :: subCandy()
{
    num_candy--;
}

void Player :: setNumCandy(int num)
{
    num_candy = num;
}