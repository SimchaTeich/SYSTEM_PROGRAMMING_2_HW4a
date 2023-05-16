#include "Ninja.hpp"

using namespace ariel;


Ninja::Ninja(const string& name, Point& location)
    : Character(name, location)
{
    _type = 'N';
    _speed = 0;
};


void Ninja::move(Character *other)
{
    _location = Point::moveToWards(_location, other->getLocation(), _speed);
};


void Ninja::slash(Character *other)
{
    if(isAlive() && distance(other) < 1)
    {
        other->hit(40);
    }
};
