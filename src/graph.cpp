#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"
#include "graph.h"

void searching_algorithms::Graph::readJsonFile(char *path){
    FILE* fp = fopen(path, "rb");
            
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document d;
    d.ParseStream(is);
    
    numberOfNodes = d["numberOfNodes"].GetInt();
    nodes = (Node **)malloc(sizeof(Node *) * numberOfNodes);

    rapidjson::Value& nodeJsons = d["nodes"];
    int i = 0;
    for (rapidjson::Value::ConstValueIterator itr = nodeJsons.Begin(); itr != nodeJsons.End(); itr++,i++) {
        rapidjson::GenericObject<true,rapidjson::Value> nodeJson = itr->GetObject(); 
        
        int numberOfNeighbors = nodeJson["numberOfNeighbors"].GetInt();
        double lat = nodeJson["location"]["lat"].GetDouble();
        double lon = nodeJson["location"]["lon"].GetDouble();
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