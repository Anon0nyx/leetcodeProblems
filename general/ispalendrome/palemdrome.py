def is_palendrome(s: str) -> bool:
    new_string = ""
    for letter in s:
        if letter.isalnum():
            new_string += letter.lower()

    left = 0
    right = len(s) - 1
    
    while left < right:
        if new_string[left] != new_string[right]:
            return False
        left += 1
        right -= 1
    
    return True

print(is_palendrome("abcba"))
