#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <limits.h>
#include <cmath>
using namespace std;

#include "ros/ros.h"
#include "searching_algorithms/node_index.h"
using namespace ros;
using namespace searching_algorithms;

#include "queue.h"
#include "location.h"
#include "node.h"
#include "graph.h"


class AStar{
    private :

        int start;
        int end;
        Graph *graph;
        
        Queue openSet;
        double *gScores;
        int *cameFrom;
        
        list<int> reconstructPath(){
            list<int> path;
            int current = end;
            path.push_back(current);
            while(current != start){
                current = cameFrom[current];
                path.push_front(current);
            }
            return path;            
        }

    public :
        AStar(char *path){
            graph = new Graph(path);
            int numberOfNodes = graph->getNumberOfNodes();
            cameFrom = (int *)malloc(sizeof(int) * numberOfNodes);
            gScores = (double *)malloc(sizeof(double) * numberOfNodes);
        }

        void init(int start, int end){

            this->start = start;
            this->end = end;
            
            int numberOfNodes = graph->getNumberOfNodes();

            for( int i = 0; i < numberOfNodes; i++ ){
                gScores[i] = INT_MAX;
                cameFrom[i] = -1;
            }

            gScores[start] = 0;
            double fScore = 0 + graph->getNode(start)->getLocation()->oklid( graph->getNode(end)->getLocation() );
            openSet.upsert(start,fScore);
        }

        list<int> run(Publisher *pub){
            int current,numberOfNeighbors;
            Node *currentNode;
            int *indexesOfNeighbors;
            double *costsOfMovingToNeighbors,fScore,tentativeGScore;
            Location *endLocation = graph->getNode(end)->getLocation();

            Rate r(10);
            node_index msg;
            msg.stop = 0;
            msg.color = 0;

            
            while (!openSet.empty() && (current = openSet.pop()) != end) {

                currentNode = graph->getNode(current);
                indexesOfNeighbors = currentNode->getIndexOfNeighbors();
                costsOfMovingToNeighbors = currentNode->getCostsOfMovingToNeigbors();
                numberOfNeighbors = currentNode->getNumberOfNeighbors();
                
                for ( int i = 0; i < numberOfNeighbors; i++ ) {
                    tentativeGScore = gScores[current] + costsOfMovingToNeighbors[i];
                    
                    if( tentativeGScore < gScores[indexesOfNeighbors[i]] ){
                        
                        gScores[indexesOfNeighbors[i]] = tentativeGScore;
                        cameFrom[indexesOfNeighbors[i]] = current;
                        fScore = tentativeGScore + graph->getNode(indexesOfNeighbors[i])->getLocation()->oklid(endLocation);
                        openSet.upsert(indexesOfNeighbors[i],fScore);

                        msg.index = indexesOfNeighbors[i];
                        pub->publish(msg);
                        r.sleep();
                    }
                    
                }
            }
            return reconstructPath();
        }
};

int main(int argc, char **argv)
{
    init(argc,argv,"ucs");
    NodeHandle nh;

    Publisher pub = nh.advertise<node_index>("node_index",10);
    Rate r(10);
    
    AStar astar("/home/mfglr/searchingAlgorithms/src/searching_algorithms/scripts/data/graph.json");
    astar.init(15,24);
    list<int> path = astar.run(&pub);

    node_index msg;
    msg.stop = 0;
    for(list<int>::iterator itr = path.begin();itr != path.end();itr++){
        msg.index = *itr;
        msg.color = 1;
        pub.publish(msg);
        r.sleep();
    }
    msg.stop = 1;
    pub.publish(msg);
    return 0;
}