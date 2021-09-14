#include <iostream>
#include "CityGraph.h"
using namespace std;

int main()
{
    cout << "CityConnect : PaD2_SoSe21_Klausur" << endl;

    CityGraph* g = new CityGraph();

    g->buildworld();

    g->showConnected(0);

    return 0;

    // Hier standard UI in Console, mit Verbindungen anzeigen usw.
}
