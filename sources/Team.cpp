#include "Team.hpp"

using namespace ariel;


Team::Team(Character *captain)
{
    _captain = captain;
    _amountOfCowboys = 0;
    _amountOfNinjas = 0;
    add(captain);
}


void Team::add(Character *player)
{
    if(_amountOfCowboys + _amountOfNinjas < MAX_PLAYERS)
    {
        if(player->getType() == 'C')
        {
            _cowboys[_amountOfCowboys++] = (Cowboy *)player;
        }
        else
        {
            _ninjas[_amountOfNinjas++] = (Ninja *)player;
        }
    }
}


Team::~Team()
{
    // free memory of Cowboys.
    for(int i = 0; i < _amountOfCowboys; i++)
    {
        delete _cowboys[i];
    }

    // free memory of Ninjas.
    for(int i = 0; i < _amountOfNinjas; i++)
    {
        delete _ninjas[i];
    }
}


void Team::attack(Team *enemies)
{
    // TODO
}


int Team::stillAlive() const
{
    int stillAlives = 0;
    
    for(int i = 0; i < _amountOfCowboys; i++)
    {
        if(_cowboys[i]->isAlive()) stillAlives++;
    }

    for(int i = 0; i < _amountOfNinjas; i++)
    {
       if(_ninjas[i]->isAlive()) stillAlives++;
    }

    return stillAlives;
}


string Team::print() const
{
    for(int i = 0; i < _amountOfCowboys; i++)
    {
        _cowboys[i]->print();
    }

    for(int i = 0; i < _amountOfNinjas; i++)
    {
        _ninjas[i]->print();
    }
}

