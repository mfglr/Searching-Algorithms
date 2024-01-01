#include <list>
#include "graph.h"
#include "queue.h"

namespace searching_algorithms{
    
    class Algorithm{
        protected :
            int start;
            int end;
            int numberOfNodes;
            Graph *graph;
            Queue openSet;
            double *gScores;
            int *cameFrom;
            std::list<int> reconstructPath();
        public :
            Algorithm(Graph *graph,int start,int end);
            void changeRoute(int start,int end){
                this->start = start;
                this->end = end;
            }
            std::list<int> virtual run() = 0;
    };

    class AStar : public Algorithm{
        private :
            void initState();
        public :
            AStar(Graph *graph,int start,int end);
            std::list<int> run();
            
    };

    class UCS : public Algorithm{
        private :
            void initState();
        public :
            UCS(Graph *graph,int start,int end);
            std::list<int> run();
            
    };

}

