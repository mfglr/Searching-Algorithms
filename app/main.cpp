#include "graph.h"
#include "algorithm.h"
#include <stdio.h>
#include <list>

using namespace searching_algorithms;
using namespace std;

int main(int argc, char const *argv[])
{

    // read the graph file to save into memory
    Graph *graph = new Graph();
    graph->readJsonFile("graphs/graph.json");
    
    //calculate the shortest path between index-15 and index-24 of the graph by a star algorithm.
    Algorithm *astar = new AStar(graph,15,24);
    list<int> path0 = astar->run();

    //calculate the shortest path between index-15 and index-24 of the graph by ucs algorithm.
    Algorithm *ucs = new UCS(graph,15,24);
    list<int> path1 = ucs->run();

    printf("%s\n","***************************");
    for(list<int>::iterator it = path0.begin(); it != path0.end();it++)
        printf("%d\t",*it);

    printf("\n%s\n","***************************");
    
    for(list<int>::iterator it = path1.begin(); it != path1.end();it++)
        printf("%d\t",*it);
    printf("\n%s\n","***************************\n");

    return 0;
}
