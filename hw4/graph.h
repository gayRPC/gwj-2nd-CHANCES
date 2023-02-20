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
    
    /**