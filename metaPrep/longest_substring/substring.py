def findLongestSubstring(s: str) -> int:
    if not len(s) > 0:
        return 0
    length: int = 1
    for i in range(0, len(s)):
        if s[0] == " ":
            return 1
        substring: set = {s[0]}
        for j in range(i+1, len(s)):
            if not s[j] in substring:
                substring.add(s[j])
                if len(substring) > length:
                    length = len(substring)
            else:
                if len(substring) > length:
                    length = len(substring)
                substring = {}
                break
    return length

test: str = "au"
print(findLongestSubstring(test))
