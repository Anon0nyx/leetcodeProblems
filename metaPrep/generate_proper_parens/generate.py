from typing import List

def generateParenthesis(n: int) -> List[str]:
    results: List[str] = []

    def dfs(openP: int, closeP: int, s: str):
        print(s)
        if (openP == closeP) and (openP + closeP == n * 2): 
            results.append(s)
            return

        if openP < n:
            dfs(openP + 1, closeP, s + "(")
        print(openP) 
        if closeP < openP:
            dfs(openP, closeP + 1, s + ")")

    dfs(0,0,"")
    return results

generateParenthesis(3)
