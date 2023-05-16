#include "TrainedNinja.hpp"

using namespace ariel;

TrainedNinja::TrainedNinja(const string& name, Point& location)
    :Ninja(name, location)
{
    _hitPoints = 100;
    _speed = 14;
}
