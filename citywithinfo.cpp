#include "citywithinfo.h"


CityWithInfo::CityWithInfo(string n, int pop)
{
    name = n;
    population = &pop;
}

CityWithInfo::~CityWithInfo()
{
    delete population;
}

int CityWithInfo::getPopulation()
{
    return *population;
}

void CityWithInfo::deletePopulation()
{
    delete population;//MUHAHAHA
}

bool CityWithInfo::populationSchnaps() // Schaut ob die population zB 666 ist
{
    string str = to_string(*population);
    char curr = str[0];

    for(char c : str)
    {
        if(curr != c)
        {return false;}
    }
    return true;
}

