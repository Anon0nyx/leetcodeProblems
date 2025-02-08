def foobar():
	tracker = {}
	tracker["test"] = "KEYVALUE"

	tracker = {
		"test": "foobar"
	}

	if "test" in tracker:
		print(True)


foobar()	
