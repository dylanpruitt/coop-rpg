#ifndef STATUS_H
#define STATUS_H
#include <string>

class Status
{
    public:
        Status ();
        virtual ~Status ();

        std::string name;

        int turns_left = 1;

    protected:

    private:
};

#endif // STATUS_H
