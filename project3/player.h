// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Project 3, Player Header File


#include <iostream>
#include <vector>
#include "Items.h"
using namespace std;

class Player
{

    private:
        vector <Items> my_items;
        int num_items;
        int ghosts_saved;
        int moves_made;
        int remnants_collected;
        bool key_found;
        bool escaped;


    public: 
        Player();
        int getNumItems();
        void setNumItems(int new_item_num);
        int getMoves();
        void setMoves(int new_moves_count);
        int getRemnants();
        void setRemnants(int blob);
        bool getKeyFound();
        void setFoundKey(bool is_found);
        bool isEscaped();
};