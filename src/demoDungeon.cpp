#include "demoDungeon.h"
#include "healRoom.h"
#include "entities/Rat.h"
#include "entities/poisonFungus.h"
#include "entities/Stag.h"
#include "entities/Aether.h"
#include "entities/lightningBug.h"
#include "entities/Warhawk.h"

demoDungeon::demoDungeon()
{
    Room* room; std::vector <Entity*> encounter;

    // F1
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F2
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F3
    encounter.push_back (new Stag ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F4
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new lightningBug ());
    encounter.push_back (new lightningBug ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F5
    room = new healRoom ();
    rooms.push_back (room);
    // F6
    encounter.push_back (new Stag ());
    encounter.push_back (new Stag ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F7
    encounter.push_back (new lightningBug ());
    encounter.push_back (new lightningBug ());
    encounter.push_back (new Aether ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F8
    encounter.push_back (new Stag ());
    encounter.push_back (new Aether ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F9
    encounter.push_back (new Aether ());
    encounter.push_back (new Aether ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F10
    room = new healRoom ();
    rooms.push_back (room);
    // F11
    encounter.push_back (new Stag ());
    encounter.push_back (new lightningBug ());
    encounter.push_back (new lightningBug ());
    encounter.push_back (new poisonFungus ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F12
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Aether ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F13
    encounter.push_back (new Stag ());
    encounter.push_back (new Stag ());
    encounter.push_back (new Stag ());
    encounter.push_back (new Stag ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F14
    encounter.push_back (new poisonFungus ());
    encounter.push_back (new poisonFungus ());
    encounter.push_back (new lightningBug ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F15
    room = new healRoom ();
    rooms.push_back (room);
    // F16
    encounter.push_back (new Warhawk ());
    room = new Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
}

demoDungeon::~demoDungeon()
{
    //dtor
}
