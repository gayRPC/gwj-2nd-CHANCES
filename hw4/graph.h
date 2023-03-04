/**
 * Title: Balanced Search Trees, Hashing and Graphs
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 1
 * Assignment: 4
 * Description: @file graph.h
 */


#include <list>
#include <map>
#include <queue>
#include <string>
/* Do not add new libraries or files */

using namespace std;

struct node {
    string airportName;
    int numOfPassengers;
};

/** An adjacency list representation of an undirected weighted graph. */
class Graph
{
public:
    
    /** Adjacency list representation of the graph;
     * the map pair consists of the airport (key)
     * and the node list (value).
     */
    map< string, list<node> > adjList;
    
    /** Constructor.*/
    Graph();
    
    /** Adds a new airport to the map with airportName
     * as key, and an empty node list as value */
    void addAirport(const string& airportName);
    
    /** Adds a new node to the list of airport1
     * using airport2 and noOfPassengers data, and
     * adds a new node to the list of airport2
     * using airport1 and noOfPassengers data. */
    void addConnection(const string& airport1, const string& airport2, int numOfPassengers);
    
    /** Given an airport name, returns all adjacent
     * airports of the given airport as a list of string. */
    list<string> getAdjacentAirports(const string& airportName);
    
    /** Given an airport name, returns the total number of
     * passengers transported from/to the given airport as an integer*/
    int getTotalPassengers(const string& airportName);