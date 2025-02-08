def validIPAddress(queryIP: str) -> str:
	def checkVersion(ip):
		delims = (".", ":")
		tracker = set()
		delimCount = 0

		for i in range(len(ip)):
			if not ip[i].isalnum() and ip[i] in delims:
				if len(tracker) > 0 and ip[i] not in tracker:
					return "Neither"
				tracker.add(ip[i])
				delimCount += 1
			elif not ip[i].isalnum():
				return "Neither"
		if delimCount == 3 and len(tracker) == 1 and "." in tracker:
			return "IPv4"
		elif delimCount == 7 and len(tracker) == 1 and ":" in tracker:
			return "IPv6"
		return "Neither"

	def checkIPv4(ip):
		newIP = ip.split(".")
		for val in newIP:
			if val[0] == "0":
				return False
			if int(val) < 0 or int(val) > 255:
				return False
		return True

	def validHex(s):
		validH = set("0123456789abcdefABCDEF")
		for val in s:
			if val not in validH:
				return False
		return True

	def checkIPv6(ip):
		newIp = ip.split(":")
		for val in newIp:
			if not len(val) <= 4 or not len(val) > 0 and not validHex(val):
				return False
		return True

	ipVersion = checkVersion(queryIP)

	if ipVersion == "IPv4" and checkIPv4(queryIP):
		return ipVersion
	elif ipVersion == "IPv6" and checkIPv6(queryIP):
		return ipVersion

	return "Neither"


print(validIPAddress("2001:0db8:85a3:0000:0000:8a2e:0370:7334"))
print(validIPAddress("192.168@1.1"))
print(validIPAddress("192.168.1.1"))
print(validIPAddress("256.256.256.256"))
print(validIPAddress("2001:0db8:85a3:00000:0:8A2E:0370:7334"))
