class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        MOD = 1_000_000_007

        def count(arr: List[int]) -> int:
            if len(arr) <= 2:
                return 1

            root = arr[0]
            left = [x for x in arr[1:] if x < root]
            right = [x for x in arr[1:] if x > root]

            ways = math.comb(len(left) + len(right), len(left)) % MOD
            return (ways * count(left) * count(right)) % MOD

        return (count(nums) - 1) % MOD