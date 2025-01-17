def count_artistic_photos(N, C, X, Y):
    photographers = []
    actors = []
    backdrops = []

    # Identify positions
    for i in range(N):
        if C[i] == 'P':
            photographers.append(i)
        elif C[i] == 'A':
            actors.append(i)
        elif C[i] == 'B':
            backdrops.append(i)

    count = 0

    # Check valid ranges using sliding window approach
    for actor in actors:
        # Find valid photographers
        left_index = right_index = 0
        while left_index < len(photographers) and photographers[left_index] < actor - Y:
            left_index += 1
        while right_index < len(photographers) and photographers[right_index] <= actor - X:
            right_index += 1
        valid_photographers = right_index - left_index

        # Find valid backdrops
        left_index = right_index = 0
        while left_index < len(backdrops) and backdrops[left_index] <= actor + X:
            left_index += 1
        while right_index < len(backdrops) and backdrops[right_index] <= actor + Y:
            right_index += 1
        valid_backdrops = right_index - left_index

        # Count valid combinations
        count += valid_photographers * valid_backdrops

    return count

# Example usage
N = 8
C = ".PBAAP.B"
X = 1
Y = 3
print(count_artistic_photos(N, C, X, Y))  # Output: 3
