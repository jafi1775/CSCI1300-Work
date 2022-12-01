// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Player Header File


#include <iostream>
#include "player.h"
#include <vector>
using namespace std;

Player :: Player()
{
    int num_items = 0;
    int ghosts_saved = 0;
    int num_candy = 0;
    int remnants_collected = 0;
    bool key_found = true;
    bool escaped = true;
    bool flashlight_found = false;
}


void Player :: printMyItems()
{
    for (int i = 0; i < num_items ; i++)
    {
        cout << my_items.at(i) << " "; 
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


void Player :: addItem()
{
    num_items++;
}

void Player :: addMyItem(string item)
{
    my_items.push_back(item);
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

int Player :: findItem(string item)
{

    for (int i = 0; i < my_items.size(); i ++)
    {
        if (my_items.at(i) == item)
        {
            return i;
        }
    }

    return 0;
}

void Player :: removeItem(int place)
{
    my_items.erase(my_items.begin() + place);
    return;
}

void Player :: subItem()
{
    num_items--;
    return;
}

void Player :: setRemnants(int num)
{
    remnants_collected = num;
    return;
}