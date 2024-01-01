#ifndef GRAPH_H
#define GRAPH_H
#include "node.h"
namespace searching_algorithms{
    class Graph{
        private :
            int numberOfNodes;
            Node **nodes;
        public :
            Graph(){}
            void readJsonFile(char *path);
            int getNumberOfNodes(){ return numberOfNodes; }
            Node *getNode(int i){ return nodes[i]; }
    };
}
#endif