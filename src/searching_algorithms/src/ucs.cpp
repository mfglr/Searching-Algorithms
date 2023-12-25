#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <limits.h>
using namespace std;

#include "ros/ros.h"
#include "searching_algorithms/node_index.h"
using namespace ros;
using namespace searching_algorithms;

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"
using namespace rapidjson;

#include "queue.h"

class Location {
    private :
        double lat;
        double lon;
    public :
        Location(double lat,double lon){ this->lat = lat; this->lon = lon; }
        double getLat(){ return lat; }
        double getLon(){ return lon; }
};

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

class Graph{
    private :
        int numberOfNodes;
        Node **nodes;
    public :
        Graph(char *path){
            FILE* fp = fopen(path, "rb");
            
            char readBuffer[65536];
            FileReadStream is(fp, readBuffer, sizeof(readBuffer));
            Document d;
            d.ParseStream(is);
            
            numberOfNodes = d["numberOfNodes"].GetInt();
            nodes = (Node **)malloc(sizeof(Node *) * numberOfNodes);

            Value& nodeJsons = d["nodes"];
            int i = 0;
            for (Value::ConstValueIterator itr = nodeJsons.Begin(); itr != nodeJsons.End(); itr++,i++) {
                GenericObject<true,Value> nodeJson = itr->GetObject(); 
                
                int numberOfNeighbors = nodeJson["numberOfNeighbors"].GetInt();
                int lat = nodeJson["location"]["lat"].GetDouble();
                int lon = nodeJson["location"]["lon"].GetDouble();
                int *indexes = (int *)malloc(sizeof(int) * numberOfNeighbors);
                double *costs = (double *)malloc(sizeof(double) * numberOfNeighbors);
                
                for(int j = 0; j < numberOfNeighbors;j++){
                    indexes[j] = nodeJson["indexesOfNeighbors"][j].GetInt();
                    costs[j] = nodeJson["costsOfMovingToNeighbors"][j].GetDouble();
                }
                
                nodes[i] = new Node( lat, lon, numberOfNeighbors,indexes,costs );
            }
            
            fclose(fp);
        }
        int getNumberOfNodes(){ return numberOfNodes; }
        Node *getNode(int i){ return nodes[i]; }
};


class UCS{
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
        UCS(char *path){
            graph = new Graph(path);
            int numberOfNodes = graph->getNumberOfNodes();
            cameFrom = (int *)malloc(sizeof(int) * numberOfNodes);
            gScores = (double *)malloc(sizeof(double) * numberOfNodes);
        }

        void init(int start, int end){

            this->start = start;
            this->end = end;
            int numberOfNodes = graph->getNumberOfNodes();
            for(int i = 0; i < numberOfNodes;i++){
                gScores[i] = INT_MAX;
                cameFrom[i] = -1;
            }
            gScores[start] = 0;
            openSet.upsert(start,gScores[start]);
        }

        list<int> run(Publisher *pub){
            int current,numberOfNeighbors;
            Node *currentNode;
            int *indexesOfNeighbors;
            double *costsOfMovingToNeighbors,tentativeGScore;

            Rate r(10);
            node_index msg;
            msg.color = 0;
            msg.stop = 0;
            
            while (!openSet.empty() && (current = openSet.pop()) != end) {

                currentNode = graph->getNode(current);
                indexesOfNeighbors = currentNode->getIndexOfNeighbors();
                costsOfMovingToNeighbors = currentNode->getCostsOfMovingToNeigbors();
                numberOfNeighbors = currentNode->getNumberOfNeighbors();
                
                for ( int i = 0; i < numberOfNeighbors; i++) {
                    
                    msg.index = indexesOfNeighbors[i];
                    pub->publish(msg);
                    r.sleep();


                    tentativeGScore = gScores[current] + costsOfMovingToNeighbors[i];

                    if( tentativeGScore < gScores[indexesOfNeighbors[i]] ){
                        
                        gScores[indexesOfNeighbors[i]] = tentativeGScore;
                        cameFrom[indexesOfNeighbors[i]] = current;
                        openSet.upsert(indexesOfNeighbors[i],tentativeGScore);
                            
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
    
    UCS ucs("/home/mfglr/searchingAlgorithms/src/searching_algorithms/scripts/data/graph.json");
    ucs.init(15,24);
    list<int> path = ucs.run(&pub);

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