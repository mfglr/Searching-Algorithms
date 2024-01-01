#include "graph.h"
#include "algorithm.h"
#include <stdio.h>
#include <list>

using namespace searching_algorithms;
using namespace std;

int main(int argc, char const *argv[])
{

    Graph *graph = new Graph();
    graph->readJsonFile("graphs/graph.json");

    Algorithm *astar = new AStar(graph,15,24);
    list<int> path0 = astar->run();

    Algorithm *ucs = new UCS(graph,15,24);
    list<int> path1 = astar->run();

    for(list<int>::iterator it = path0.begin(); it != path0.end();it++)
        printf("%d\n",*it);

    printf("%s\n","***************************");
    
    for(list<int>::iterator it = path1.begin(); it != path1.end();it++)
        printf("%d\n",*it);

    return 0;
}
