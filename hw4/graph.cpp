
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
        // initialize the map with the airport 2
        list<node>::iterator iterNode = adjList[airportName].begin();
        // iterate the list
        while(iterNode != adjList[airportName].end())
        {
            airportList.push_back(iterNode->airportName);
            iterNode++;
        }
    }
    return airportList;
}  // end getAdjacentAirports

int Graph::getTotalPassengers(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
    // total number of passengers transported
    int totalPassengers = 0;
    // get the vertex iterate over the vertex
    // check airport with the airportname exists or not
    if(adjList.find(airportName) != adjList.end()){
        // initialize the map with the airport 2
        list<node>::iterator iterNode = adjList[airportName].begin();
        // iterate the list
        while(iterNode != adjList[airportName].end())
        {
            // increment passengers
            totalPassengers += iterNode->numOfPassengers;
            iterNode++;
        }
    }
    return totalPassengers;
}  // end getTotalPassengers


list<string> Graph::findShortestPath(const string& airport1, const string& airport2)
{   /*YOUR IMPLEMENTATION*/
    // idea: BFS to find shortest find in the unweighted airport graph
    list<string> shortestPath;
    // if source airport does not exist
    if (adjList.find(airport1) == adjList.end()) {
        return shortestPath;
    }
    list<string> visited;
    queue<list<node>> airportQueue;
    // mark the visited vertex
    visited.push_back(airport1);
    shortestPath.push_back(airport1);
    // beacuse it will popped deleted
    shortestPath.push_back(airport1);
    // find the node list with the source airport name
    list<node> vertexList = adjList.find(airport1)->second;
    airportQueue.push(vertexList);
    bool isVisited;
    while (!airportQueue.empty()) {
        // access the element in the queue
        list<node> adjNodes = airportQueue.front();
        // remove the element from queue
        airportQueue.pop();
        // find by value
        string vertex;
        findByValue(adjNodes, vertex);
        shortestPath.pop_back();
        shortestPath.push_back(vertex);
        // iterate through the adjaceny vertex
        for (list<node>::iterator it = adjNodes.begin(); it != adjNodes.end(); ++it){
            // look whether current node visited or not
            isVisited = false;
            for (list<string>::iterator itVisited = visited.begin(); itVisited != visited.end(); itVisited++) {
                if ((*itVisited) == it->airportName) {
                    isVisited = true;
                }
            }
            // only visit the unvisited nodes
            if (!isVisited) {
                // mark current node as visited
                visited.push_back(it->airportName);
                // check whether you reached the end of search
                if (it->airportName == airport2) {
                    shortestPath.push_back(airport2);
                    return shortestPath;
                }
                // enqueue the node
                vertexList = adjList.find(it->airportName)->second;
                airportQueue.push(vertexList);
            }