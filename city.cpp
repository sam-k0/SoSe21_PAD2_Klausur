#include "city.h"

string City::getName() const
{
    return name;
}

void City::setName(const string &value)
{
    name = value;
}

int City::getPopulation()
{
    return -1;
}

bool City::populationSchnaps()
{
    return false;
}

City::City()
{

}

City::City(string n)
{
    name = n;
}

City::~City()
{

}
