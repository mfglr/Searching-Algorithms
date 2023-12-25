#!/usr/bin/env python3
import json
import matplotlib.pyplot as plt
import rospy
from searching_algorithms.msg import node_index

plt.ion()
fig = plt.figure(figsize=(10,10))
ax = plt.gca()
ax.set_aspect('equal', adjustable='box')

graphFile = open("/home/mfglr/searchingAlgorithms/src/searching_algorithms/scripts/data/graph.json")
graph = json.load(graphFile)
numberOfNodes = graph["numberOfNodes"]
nodes = graph["nodes"]

for i in range(0,len(nodes)) :
    node = nodes[i]
    location = node["location"]
    neighborIndexes = node["indexesOfNeighbors"]
    ax.text(location["lon"],location["lat"], node["name"], fontsize=8)
    plt.plot(location["lon"],location["lat"],'bo',markersize=4)
    for j in range(0,len(neighborIndexes)) :
        locationOfNeighbor = nodes[neighborIndexes[j]]["location"]
        x = [location["lon"],locationOfNeighbor["lon"]]
        y = [location["lat"],locationOfNeighbor["lat"]]
        plt.plot(x,y,"k",linewidth=1)

stop = 0
def getNodeIndex(msg):
    global stop
    stop = msg.stop
    location = nodes[msg.index]["location"]
    if(msg.color == 1):
        plt.plot(location["lon"],location["lat"],'ro',markersize=10)
    else :
        plt.plot(location["lon"],location["lat"],'ko',markersize=10)

rospy.init_node("display_nodes",anonymous=True)
rospy.Subscriber("node_index",node_index,getNodeIndex)
rate = rospy.Rate(10)

while stop != 1 : 
    fig.canvas.draw()
    fig.canvas.flush_events()
    rate.sleep()

