from collections import defaultdict
def organizeDataCenters(arr: list):
	# ["ssw001.atns1", "ssw002.atns1", "ssw001.atns2"]
	organizedData = defaultdict(lambda: defaultdict(list))
	for data in arr:
		deviceType = data[:3]
		deviceId = data[3:6] # This doesnt get used
		center = data[7:]
		if center not in organizedData:
			organizedData[center] = []
		organizedData[center][deviceType].append(data)
	return organizedData

data = ["ssw001.atns1", "ssw002.atns1", "ssw001.atns2"]

print(organizeDataCenters(data))
