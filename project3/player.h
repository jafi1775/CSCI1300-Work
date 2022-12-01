// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Player Header File


#include <iostream>
#include "Items.h"
using namespace std;

class Player
{

    private:
        string my_items[5];
        int num_items;
        int num_candy;
        int ghosts_saved;
        int remnants_collected;
        bool key_found;
        bool escaped;
        bool flashlight_found;


    public: 
        Player();
        void printMyItems();
        void addMyItem(string item);
        int getNumItems();
        void setNumItems(int new_item_num);
        void addItem();

        int getCandy();
        void addCandy();
        void subCandy();
        void setNumCandy(int num);

        int getRemnants();
        void addRemnants();
        void subRemnants();

        bool getKeyFound();
        void setFoundKey(bool is_found);

        void setEscaped(bool is_escaped);
        bool isEscaped();

        void setGhostsSaved(int ghosts);
        void addGhostsSaved();
        int getGhostsSaved();

        bool isFlashlightFound();
        void setFlashlightFound(bool is_found);
};