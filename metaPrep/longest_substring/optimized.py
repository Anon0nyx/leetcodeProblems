def findLongestSubstring(s: str) -> int:
    letters: dict = {}
    temp = set()
    for i in range(0, len(s)):
        if not s[i] in temp:
            temp.add(s[i])

    for i in temp:    
        foobar = i
        letters[foobar] = set()
    
    for i in range(0, len(s)):
        letters[s[i]].add(i)

    for key in letters:
        print(key)

    return 0

s: str = "ABCABCBB"
findLongestSubstring(s)
