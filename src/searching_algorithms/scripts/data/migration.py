import json


## source : https://gist.github.com/abdullahoguk/ee03c26a23dca6eda9c480b4967e77b6#file-il-json
jsonFile = open('rows.json')
rows = json.load(jsonFile)

## filtering unnecessary fields
def map(row):
    return {"id" : row["plaka"], "name" : row["il_adi"],"lat" : row["lat"],"lon" : row["lon"]}

numberOfRows = len(rows)
positions = []

for i in range(0,numberOfRows) :
    positions.insert(i,map(rows[i]))

with open("positions.json", "w") as outfile:
    json.dump(obj= positions, fp=outfile,ensure_ascii=False)