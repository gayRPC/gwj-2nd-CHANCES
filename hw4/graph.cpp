
/**
 * Title: Balanced Search Trees, Hashing and Graphs
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 1
 * Assignment: 4
 * Description: @file graph.cpp,  An adjacency list representation of an undirected weighted graph.
 *              - Implementation details in the header file (.h)
 */


#include "graph.h"
/*Do not add new libraries or files*/

Graph::Graph()
{
}  // end constructor

void Graph::addAirport(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
    
    // insert returns an iterator to the existing element if it already exists
    adjList.insert(std::make_pair(airportName, list<node>()));
    
}  // end addPerformer

void Graph::addConnection(const string& airport1, const string& airport2, int numOfPassengers)
{   /*YOUR IMPLEMENTATION*/
    if(adjList.find(airport1) == adjList.end()){
        addAirport(airport1);
    }
    // initialize the new node to insert into the map
    node newNode;
    newNode.airportName = airport2;
    newNode.numOfPassengers = numOfPassengers;
    // insert the node to the given list of nodes
    adjList[airport1].push_back(newNode);
    // check airport2 in the map or not
    if(adjList.find(airport2) == adjList.end()){
        // initialize the map with the airport 2
        addAirport(airport2);
    }
    newNode.airportName = airport1;
    adjList[airport2].push_back(newNode);
}  // end addConnection

list<string> Graph::getAdjacentAirports(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
    // get the list associated with airport
    list<string> airportList;
    // check airport with the airportname exists or not
    if(adjList.find(airportName) != adjList.end()){