#include "demoDungeon.h"
#include "entities/Rat.h"
#include "entities/poisonFungus.h"
#include "entities/Stag.h"
#include "entities/Aether.h"
#include "entities/lightningBug.h"
#include "entities/Warhawk.h"

demoDungeon::demoDungeon()
{
    Room room; std::vector <Entity*> encounter;

    // F1
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F2
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F3
    encounter.push_back (new Stag ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F4
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new lightningBug ());
    encounter.push_back (new lightningBug ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F5
    // F6
    encounter.push_back (new Stag ());
    encounter.push_back (new Stag ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F7
    encounter.push_back (new lightningBug ());
    encounter.push_back (new lightningBug ());
    encounter.push_back (new Aether ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F8
    encounter.push_back (new Stag ());
    encounter.push_back (new Aether ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F9
    encounter.push_back (new Aether ());
    encounter.push_back (new Aether ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F10
    // F11
    encounter.push_back (new Stag ());
    encounter.push_back (new lightningBug ());
    encounter.push_back (new lightningBug ());
    encounter.push_back (new poisonFungus ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F12
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Rat ());
    encounter.push_back (new Aether ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F13
    encounter.push_back (new Stag ());
    encounter.push_back (new Stag ());
    encounter.push_back (new Stag ());
    encounter.push_back (new Stag ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F14
    encounter.push_back (new poisonFungus ());
    encounter.push_back (new poisonFungus ());
    encounter.push_back (new lightningBug ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
    // F15
    // F16
    encounter.push_back (new Warhawk ());
    room = Room (encounter);
    rooms.push_back (room);
    encounter.clear ();
}

demoDungeon::~demoDungeon()
{
    //dtor
}
