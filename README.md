<h1>Fields of a node</h1>
<code>
{
    "name": "Adana", 
    "location": {"lat": 37, "lon": 35.3213333},
    "numberOfNeighbors": 6, 
    "indexesOfNeighbors": [32, 50, 37, 79, 30, 45],
    "costsOfMovingToNeighbors": [
        0.7164802858418398,
        1.1582264497449897,
        1.7408872246325675,
        0.9427150067133189,
        1.1897682813970125,
        1.7142991975990935
    ]
}
</code>

<h2>Graph Json File</h2>

#The graph.json file is under the graphs directory.

<code>
    {
        "numberOfNodes": 81,
        "nodes": [
            {
                "name": "Adana",
                "location": {"lat": 37, "lon": 35.3213333},
                "numberOfNeighbors": 6,
                "indexesOfNeighbors": [32, 50, 37, 79, 30, 45],
                "costsOfMovingToNeighbors": [
                    0.7164802858418398,
                    1.1582264497449897,
                    1.7408872246325675,
                    0.9427150067133189,
                    1.1897682813970125,
                    1.7142991975990935
                ]
            },
            {
                "name": "Adıyaman",
                "location": {"lat": 37.7641667, "lon": 38.2761667},
                "numberOfNeighbors": 5,
                "indexesOfNeighbors": [26, 62, 20, 43, 45],
                "costsOfMovingToNeighbors": [
                    1.1332717351728903,
                    0.8072187197889912,
                    1.9602285405830087,
                    0.5919602900260998,
                    1.3549547072544932
                ]
            },
            ...
            {
                "name": "Düzce",
                "location": {"lat": 40.843849, "lon": 31.15654},
                "numberOfNeighbors": 3,
                "indexesOfNeighbors": [53, 13, 66],
                "costsOfMovingToNeighbors": [
                    0.7832454291740804,
                    0.46683745280450434,
                    0.8874903008377065
                ]
            }
        ]
    }
</code>

<h1>An Example</h1>

<code>
    #include "graph.h"
    #include "algorithm.h"
    #include <stdio.h>
    #include <list>
    
    using namespace searching_algorithms;
    using namespace std;
    
    int main(int argc, char const *argv[])
    {
    
        // read the graph file to save it into memory
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

    ##Output :

    ***************************
    15      10      5       70      65      57      23      24
    ***************************
    15      10      5       70      65      57      23      24
    ***************************
</code>


<h1>Map of Nodes</h1>

If we consider each city of Turkey as a node, the resulting map will be as follows :

![Screenshot from 2023-12-20 21-34-45](https://github.com/mfglr/Searching-Algorithms/assets/79373693/97714bc8-ae73-4291-a834-da75c3979255)

<h2>astar algorithm</h2>

<code>
start point : Bursa
end point : Erzurum
</code>


https://github.com/mfglr/Searching-Algorithms/assets/79373693/6c5767ac-e0fd-4942-9f10-0e3e05261e02


<h2>ucs algorithm</h2>

<code>
start point : Bursa
end point : Erzurum
</code>


https://github.com/mfglr/Searching-Algorithms/assets/79373693/cc6d7246-a6c8-42c7-8099-2b9d5b64a96f

