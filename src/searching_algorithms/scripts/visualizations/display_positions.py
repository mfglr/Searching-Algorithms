import json
import matplotlib.pyplot as plt


positionsFile = open("../data/positions.json")
positions = json.load(positionsFile)


numberOfPositions= len(positions)

lats = list(map(lambda x : x["lat"],positions))
lons = list(map(lambda x : x["lon"],positions))

plt.plot(lats,lons,'ro',markersize=1)

plt.show()
