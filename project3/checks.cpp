#include <iostream>
#include "map.h"
#include "time.h"
#include <string>
#include "player.h"
#include "flashlight.h"
#include "story_build.h"

using namespace std;

int main()
{
    assert(map.addGhost(0,0)); // ghosts 
    assert(map.addGhost(3,3));
    assert(map.addGhost(5,5));
    assert(map.addGhost(6,9));
    assert(map.addGhost(8,3));

    assert(map.addItem(7,0)); // flashlight

    assert(map.addItem(8,7)); // non interactive features or items
    assert(map.addItem(11,9)); 
    assert(map.addItem(0,8));
    assert(map.addItem(1,5));
    assert(map.addItem(6,2));
    assert(map.addItem(3,8));

    //ghost
    if (map.getPlayerRow() == 0 && map.getPlayerCol() == 0)
    {

    }

    //ghost
    // if (map.getPlayerRow() == 2 && map.getPlayerCol() == 3)
    // {

    // }

    //ghost
    if (map.getPlayerRow() == 5 && map.getPlayerCol() == 5)
    {

    }

    // //ghost
    // if (map.getPlayerRow() == 6 && map.getPlayerCol() == 9)
    // {

    // }

    //ghost
    if (map.getPlayerRow() == 8 && map.getPlayerCol() == 3)
    {

    }


    //flashlight
    if (map.getPlayerRow() == 7 && map.getPlayerCol() == 0)
    {
        
    }

    //non interactive
    if (map.getPlayerRow() == 8 && map.getPlayerCol() == 7)
    {

    }

    //non interactive
    if (map.getPlayerRow() == 11 && map.getPlayerCol() == 9)
    {

    }

    // non interactive
    if (map.getPlayerRow() == 0 && map.getPlayerCol() == 8)
    {

    }

    //non interactive
    if (map.getPlayerRow() == 1 && map.getPlayerCol() == 5)
    {

    }

    //non interactive
    if (map.getPlayerRow() == 6 && map.getPlayerCol() == 2)
    {

    }

    //non interactive
    if (map.getPlayerRow() == 3 && map.getPlayerCol() == 8)
    {

    }

}