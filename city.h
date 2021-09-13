#ifndef CITY_H
#define CITY_H
#include <string>
using namespace std;
class City
{
protected:
    string name;


public:
    City();
    City(string n);

    virtual ~City();
    string getName() const;
    void setName(const string &value);
    virtual int getPopulation();
    virtual bool populationSchnaps();
};

#endif // CITY_H
