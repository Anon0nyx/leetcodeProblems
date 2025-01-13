from typing import List

def qsort(arr: List[int]) -> List[int]:
    lesser: List[int] = []
    greater: List[int] = []
    equal: List[int] = []
    if len(arr) <= 1:
        return arr
    pivot: int = arr[len(arr)//2]
    for element in arr:
        if element < pivot:
            lesser.append(element)
        elif element > pivot: 
            greater.append(element)
        else:
            equal.append(element)
    lesser = qsort(lesser)
    greater = qsort(greater)
    return lesser + equal + greater

def getMaxAdditionalDinersCount(N: int, K: int, M: int, S: List[int]) -> int:
    S: List[int] = qsort(S)

    total: int = 0
    step: int = 1
    avail: int = 0

    # First edge
    gap: int = S[0] - step
    if gap > 0:
        total += gap // (K + 1)
    step = S[0]

    # Middle slices
    for i in range(1, M):
        gap = S[i] - S[i-1] - 1
        if gap > 0:
            total += (gap - K) // (K + 1)
    
    # Last edge
    gap = N - S[-1]
    if gap > 0:
        total += gap // (K + 1)

    return total

def main() -> int:
    # Test one
    arr: List[int] = [11, 6, 14]
    print("Test one: " + str(getMaxAdditionalDinersCount(15, 2, 3, arr)))

    #Test two
    arr = [2, 6]
    print("Test two: " + str(getMaxAdditionalDinersCount(10, 1, 2, arr)))

    return 0

if __name__ == "__main__":
    main()
