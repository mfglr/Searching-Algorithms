#include <stdlib.h>
#include <stdio.h>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"
using namespace rapidjson;

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
        int getIndexOfNeihgbor(int i){ return indexesOfNeighbors[i]; }
        double getCostOfMovingToNeighbor(int i) { return costsOfMovingToNeighbors[i]; }
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
