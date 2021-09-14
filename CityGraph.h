#ifndef CITYGRAPH_H
#define CITYGRAPH_H
#include "city.h"
#include <string>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
class CityGraph
{
private:
    City* Cities[7] = {  new City("stadt0"),
                         new City("stadt1"),
                         new City("stadt2"),
                         new City("stadt3"),
                         new City("stadt4"),
                         new City("stadt5"),
                         new City("stadt6"),
                        };
    int citynum = 7;
    int matrix[7][7];

public:
    void init() // Sets the matrix to default values
    {
        for(int i = 0; i < citynum; i++)
        {
            for(int j = 0; j<citynum; j++)
            {
                matrix[i][j] = -1; // -1 = no connection
            }
        }

    }

    void setConnection(int start, int dest, int duration) // Set connection btwn cities
    {
        if(!checkInBounds(start) || !checkInBounds(dest))
        {
            cout << "Out of matrix bounds"<<endl;
            return;
        }

        if(duration < 0)
        {
            // hier sollte in der klausur ein error geworfen werden, in der main gecatched
            /*
            throw(invalid_argument("Error: Cannot have duration <0"));
            */

            cout << "Error: Cannot have duration <0"<<endl;
            return;
        }

        matrix[start][dest] = duration;


    }

    bool checkInBounds(int val) // Check if inbounds
    {
        if(val > citynum || val < 0)
        {
            cout << "CheckInBounds: Invalid argument value for matrix"<<endl;
            return false;
        }
        return true;
    }

    void printconnections(int city)
    {
        if(!checkInBounds(city)) // err catch
        {
            return;
        }

        cout << "Showing connections from "<<getCityNameById(city)<<endl;
        for(int i = 0; i < citynum; i++)
        {
            if(matrix[city][i] != -1)
            {
                cout << i<<" | "<<getCityNameById(i)<< " duration: "<<matrix[city][i]<< endl;
            }
        }


    }

    void deleteConnection(int start, int dest)
    {
        if(!checkInBounds(start) || !checkInBounds(dest))
        {
            return;
        }

        // Hier fehler werfen wenn man etwas löschen will das es nicht gibt
        if(matrix[start][dest] == -1)
        {
            /*
            throw(runtime_error("Cannot delete: Doesnt exist"));
            */
            return;
        }

        matrix[start][dest] = -1;
    }

    string getCityNameById(int id)
    {
        if(checkInBounds(id))
        {
            return Cities[id]->getName();
        }
        return "";
    }

    void showConnected(int city) // Keine garantie auf richtigkeit lol. Das soll ne tiefensuche sein, die
    {                               // Alle erreichbaren knoten findet und in visited speichert.
        queue<int> s;
        set<int> visited;
        int current = city;
        s.push(current);        

        cout << "(You are at "<<getCityNameById(city)<<" )You can reach following stations by transfers: "<<endl;

        while(!s.empty()) // solange stack !empty
        {
            current = s.front();
            s.pop();
            for(int i = 0 ; i < citynum; i++)
            {
                if(!visited.count(matrix[current][i]) && matrix[current][i]!= -1)
                {
                    s.push(i);

                }

            }
            visited.insert(current);
        }

        for(auto element : visited)
        {
            if(!(element == city))
            {
                cout << "- "<<element<< " | "<<getCityNameById(element)<<endl;
            }
        }
    }

    void buildworld()
    {
        init();

        setConnection(0,1,40);
        setConnection(0,2,40);
        setConnection(2,3,40);
        setConnection(3,6,40);
        setConnection(4,5,40);
    }
};
#endif // CITYGRAPH_H
