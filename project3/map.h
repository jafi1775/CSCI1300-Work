
#ifndef MAP_H
#define MAP_H

#include <iostream>

using namespace std;

class Map
{
private:
    const char NOTHING = '+'; // marker for unexplored spaces
    const char STORY = 'N';
    const char ITEM = 'F';       // marker for room locations
    const char GHOST = 'G';        // marker for NPC locations
    const char PLAYER = 'X';      // marker for party position
    const char ESCAPE = 'E';       // marker for dungeon exit

    static const int num_rows_ = 12; // number of rows in map
    static const int num_cols_ = 12; // number of columns in map
    static const int max_ghosts = 6;  // max non-player characters
    static const int max_items = 7; // max number of rooms
    static const int max_story = 6;

    int player_position_[2];              // player position (row,col)
    int house_escape[2];                 // exit location of the dungeon
    int ghost_positions_[max_ghosts][3];     // stores the (row,col) positions of NPCs present on map and if they have been found
    int item_positions_[max_items][2];   // stores the (row,col) positions of rooms present on map
    char map_data_[num_rows_][num_cols_]; // stores the character that will be shown at a given (row,col)
    int story_positions_[max_story][6];

    int ghost_count_;  
    int item_count_; 
    int story_count_;

public:
    Map();

    void resetMap();

    // getters
    int getPlayerRow();
    int getPlayerCol();
    int getHouseEscapeRow();
    int getHouseEscapeCol();
    int getItemCount();
    //int getStoryCount();
    int getGhostCount();
    int getNumRows();
    int getNumCols();
    bool isOnMap(int row, int col);
    bool isGhostLocation(int row, int col);
    bool isItemLocation(int row, int col);
    //bool isStoryLocation(int row, int col);
    //bool isExplored(int row, int col);
    bool isFreeSpace(int row, int col);
    bool isHouseEscape(int row, int col);

    // setters
    void setPlayerPosition(int row, int col);
    void setHouseEscape(int row, int col);

    // other
    void displayMap();
    bool move(char);
    bool addGhost(int row, int col);
    //bool addStory(int row, int col);
    bool addItem(int row, int col);
    bool removeGhost(int row, int col);
    bool removeItem(int row, int col);
   //bool removeStory(int row, int col);
    //void exploreSpace(int row, int col);
};

#endif