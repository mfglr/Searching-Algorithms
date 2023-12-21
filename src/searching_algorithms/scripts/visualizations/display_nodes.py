import json
import matplotlib.pyplot as plt

plt.figure(figsize=(10,10))
ax = plt.gca()
ax.set_aspect('equal', adjustable='box')

graphFile = open("../data/graph.json")
graph = json.load(graphFile)
numberOfNodes = graph["numberOfNodes"]
nodes = graph["nodes"]

for i in range(0,len(nodes)) :
    node = nodes[i]
    location = node["location"]
    neighborIndexes = node["indexesOfNeighbors"]
    plt.plot(location["lon"],location["lat"],'bo',markersize=4)
    for j in range(0,len(neighborIndexes)) :
        locationOfNeighbor = nodes[neighborIndexes[j]]["location"]
        x = [location["lon"],locationOfNeighbor["lon"]]
        y = [location["lat"],locationOfNeighbor["lat"]]
        plt.plot(x,y,"k",linewidth=1)
plt.show()
