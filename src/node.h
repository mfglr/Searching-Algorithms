#ifndef NODE_H
#define NODE_H
#include "location.h"
namespace searching_algorithms{
    class Node {
        private : 
            Location *location;
            int numberOfNeighbors;
            int *indexesOfNeighbors;
            double *costsOfMovingToNeighbors;
        public :
            Node(double lat,double lon,int numberOfNeighbors,int *indexes,double *costs){
                this->location = new Location(lat,lon);
                this->numberOfNeighbors = numberOfNeighbors;
                this->indexesOfNeighbors = indexes;
                this->costsOfMovingToNeighbors = costs;
            }
            Location *getLocation(){ return location; }
            int getNumberOfNeighbors(){ return numberOfNeighbors; }
            int *getIndexOfNeighbors(){ return indexesOfNeighbors; }
            double *getCostsOfMovingToNeigbors(){ return costsOfMovingToNeighbors; }
    };
}
#endif