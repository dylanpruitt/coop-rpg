#ifndef STATUS_H
#define STATUS_H
#include <string>

class Entity;

class Status
{
    public:
        Status ();
        virtual ~Status ();

        std::string name;

        int turns_left = 1;

        virtual void on_ice_damage (Entity* parent) {};

        virtual void on_battle_end (Entity* parent) {};
    protected:

    private:
};

#endif // STATUS_H
