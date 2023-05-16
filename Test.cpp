#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"

using namespace ariel;


TEST_CASE("Point class")
{
    Point a(0,0);
    Point b(3,0);
    Point c(3,4);
    Point d(6,8);
    
    CHECK_EQ(a.distance(b), b.distance(a));
    CHECK_EQ(b.distance(c), c.distance(b));
    CHECK_EQ(c.distance(a), a.distance(c));

    CHECK_EQ(a.distance(a), 0);
    CHECK_EQ(c.distance(a), 5);

    CHECK_EQ(Point::moveToWards(a, d, 5).x(), 3);
    CHECK_EQ(Point::moveToWards(a, d, 5).y(), 4);
}


TEST_CASE("Cowboy")
{
    Cowboy alice("Alice", Point(0,0));
    Cowboy bob("Bob", Point(0,10));


    CHECK_EQ(alice.getName(), "Alice");
    CHECK_EQ(alice.getType(), 'C');
    CHECK_EQ(alice.hasBoolets(), true);

    for(int i = 0; i < 6; i++)
    {
        alice.shoot(&bob);
    }

    CHECK_EQ(alice.hasBoolets(), false);
    CHECK_EQ(bob.isAlive(), true);

    alice.reload();

    for(int i = 0; i < 5; i++)
    {
        alice.shoot(&bob);
    }

    CHECK_EQ(alice.hasBoolets(), true);
    CHECK_EQ(bob.isAlive(), false);
}


TEST_CASE("Young Ninja")
{
    YoungNinja alice("Alice", Point(0,0));
    YoungNinja bob("Bob", Point(0,0.9));
    YoungNinja eve("Eve", Point(0,1));

    CHECK_EQ(alice.getType(), 'N');

    alice.slash(&bob); // bob hits: 100 - 40
    CHECK_EQ(bob.isAlive(), true);
    alice.slash(&bob); // bob hits: 60 - 40
    CHECK_EQ(bob.isAlive(), true);
    alice.slash(&bob); // bob hits: 20 - 40 --> bob die!
    CHECK_EQ(bob.isAlive(), false);

    // eve is far away from alice.. 1 Meter exactly.
    alice.slash(&eve);
    alice.slash(&eve);
    alice.slash(&eve);
    CHECK_EQ(eve.isAlive(), true);
}


TEST_CASE("Trained Ninja")
{
    TrainedNinja alice("Alice", Point(0,0));
    TrainedNinja bob("Bob", Point(11, 0));
    TrainedNinja eve("Eve", Point(12, 0));

    alice.move(&bob);
    CHECK_EQ(alice.getLocation().x(),11);
    CHECK_EQ(alice.getLocation().y(), 0);

    alice.slash(&bob);
    alice.slash(&bob);
    alice.slash(&bob);
    CHECK_EQ(bob.isAlive(), false);

    alice.slash(&eve);
    alice.slash(&eve);
    alice.slash(&eve);
    CHECK_EQ(eve.isAlive(), true);

    alice.move(&eve);

    alice.slash(&eve);
    alice.slash(&eve);
    alice.slash(&eve);
    CHECK_EQ(eve.isAlive(), false);
}


TEST_CASE("Old Ninja")
{
    OldNinja alice("Alice", Point(0,0));
    OldNinja bob("Bob", Point(8, 0));
    OldNinja eve("Eve", Point(8.1, 0));

    alice.move(&bob);
    
    alice.slash(&bob);
    alice.slash(&bob);
    alice.slash(&bob);
    alice.slash(&eve);
    alice.slash(&eve);
    alice.slash(&eve);
    CHECK_EQ(bob.isAlive(), false);
    CHECK_EQ(eve.isAlive(), false);
}
