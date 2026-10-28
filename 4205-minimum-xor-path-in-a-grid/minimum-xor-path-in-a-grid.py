class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        dp = {0: {grid[0][0]}}
        for r, row in enumerate(grid):
            for c, v in enumerate(row):
                s = (dp.get(c, set()) | dp.get(c - 1, set())) if (r or c) else {0}
                dp[c] = {x ^ v for x in s}
        return min(dp[len(grid[0]) - 1])