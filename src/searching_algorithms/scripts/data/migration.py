import json
import math

jsonFileNeighbors = open('neighbors.json')
jsonFileIds = open('ids.json')
## source : https://gist.github.com/abdullahoguk/ee03c26a23dca6eda9c480b4967e77b6#file-il-json
jsonFileRows = open('rows.json')

neihgbors = json.load(jsonFileNeighbors)
ids = json.load(jsonFileIds)
rows = json.load(jsonFileRows)

nodes = list(
    map(
        lambda neighbor,row: {
            "name" : neighbor["il"],
            "location":{"lat":row["lat"],"lon":row["lon"]},
            "numberOfNeighbors":len(neighbor["komsular"]),
            "indexesOfNeighbors":list(map(lambda n:ids[n] - 1,neighbor["komsular"])),
            "costsOfMovingToNeighbors":list(
                map(
                    lambda n :  math.sqrt(
                        pow( rows[ids[n] - 1]["lat"] - row["lat"], 2 ) + 
                        pow( rows[ids[n] - 1]["lon"] - row["lon"], 2 )
                    ),
                    neighbor["komsular"]
                )
            ),
        },neihgbors,rows
    )
)
data = {"numberOfNodes":len(nodes),"nodes":nodes}

with open("graph.json", "w") as outfile:
    json.dump(obj= data, fp=outfile,ensure_ascii=False)
    