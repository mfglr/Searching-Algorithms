#include <list>
#include <limits.h>
#include "algorithm.h"
#include "graph.h"

std::list<int> searching_algorithms::Algorithm::reconstructPath(){
    std::list<int> path;
    int current = end;
    path.push_front(current);
    while(current != start){
        current = cameFrom[current];
        path.push_front(current);
    }
    return path;
}

searching_algorithms::Algorithm::Algorithm(Graph *graph,int start, int end){
    this->graph = graph;
    this->start = start;
    this->end = end;
    this->numberOfNodes = graph->getNumberOfNodes();
    cameFrom = (int *)malloc(sizeof(int) * numberOfNodes);
    gScores = (double *)malloc(sizeof(double) * numberOfNodes);
}

searching_algorithms::AStar::AStar(Graph *graph,int start, int end) : Algorithm(graph,start,end){
}

void searching_algorithms::AStar::initState(){
    for( int i = 0; i < numberOfNodes; i++ ){
        gScores[i] = INT_MAX;
        cameFrom[i] = -1;
    }
    gScores[start] = 0;
    double fScore = 0 + Location::oklid(graph->getNode(start)->getLocation(),graph->getNode(end)->getLocation());
    openSet.set(start,fScore);
}

std::list<int> searching_algorithms::AStar::run(){
    initState();

    int current,numberOfNeighbors;
    Node *currentNode;
    int *indexesOfNeighbors;
    double *costsOfMovingToNeighbors,fScore,tentativeGScore;
    Location *endLocation = graph->getNode(end)->getLocation();

    while (!openSet.empty() && (current = openSet.pop()) != end) {

        currentNode = graph->getNode(current);
        numberOfNeighbors = currentNode->getNumberOfNeighbors();
        indexesOfNeighbors = currentNode->getIndexOfNeighbors();
        costsOfMovingToNeighbors = currentNode->getCostsOfMovingToNeigbors();
        
        for ( int i = 0; i < numberOfNeighbors; i++ ) {
            tentativeGScore = gScores[current] + costsOfMovingToNeighbors[i];
            if( tentativeGScore < gScores[indexesOfNeighbors[i]] ){
                gScores[indexesOfNeighbors[i]] = tentativeGScore;
                cameFrom[indexesOfNeighbors[i]] = current;
                fScore = tentativeGScore + Location::oklid(graph->getNode(indexesOfNeighbors[i])->getLocation(),endLocation);
                openSet.set(indexesOfNeighbors[i],fScore);
            }
        }
    }
    return reconstructPath();
}


searching_algorithms::UCS::UCS(Graph *graph,int start, int end) : Algorithm(graph,start,end){
}

void searching_algorithms::UCS::initState(){
    for( int i = 0; i < numberOfNodes; i++ ){
        gScores[i] = INT_MAX;
        cameFrom[i] = -1;
    }
    gScores[start] = 0;
    openSet.set(start,0);
}

std::list<int> searching_algorithms::UCS::run(){
     initState();

    int current,numberOfNeighbors;
    Node *currentNode;
    int *indexesOfNeighbors;
    double *costsOfMovingToNeighbors,tentativeGScore;
    
    while (!openSet.empty() && (current = openSet.pop()) != end) {

        currentNode = graph->getNode(current);
        indexesOfNeighbors = currentNode->getIndexOfNeighbors();
        costsOfMovingToNeighbors = currentNode->getCostsOfMovingToNeigbors();
        numberOfNeighbors = currentNode->getNumberOfNeighbors();
        
        for ( int i = 0; i < numberOfNeighbors; i++) {
            tentativeGScore = gScores[current] + costsOfMovingToNeighbors[i];
            if( tentativeGScore < gScores[indexesOfNeighbors[i]] ){
                gScores[indexesOfNeighbors[i]] = tentativeGScore;
                cameFrom[indexesOfNeighbors[i]] = current;
                openSet.set(indexesOfNeighbors[i],tentativeGScore);
            }

        }
    }
    return reconstructPath();
}