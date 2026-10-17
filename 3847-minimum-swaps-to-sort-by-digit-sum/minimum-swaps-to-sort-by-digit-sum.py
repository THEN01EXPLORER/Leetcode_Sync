class Solution:
    def minSwaps(self, nums: list[int]) -> int:
        def get_digit_sum(n: int) -> int:
            s = 0
            while n > 0:
                s += n % 10
                n //= 10
            return s

        n = len(nums)
        # Store (digit_sum, value, original_index)
        elements = [(get_digit_sum(val), val, i) for i, val in enumerate(nums)]
        
        # Sort by (digit_sum, value)
        elements.sort(key=lambda x: (x[0], x[1]))
        
        visited = [False] * n
        swaps = 0
        
        for i in range(n):
            # Already visited or already at the correct position
            if visited[i] or elements[i][2] == i:
                continue
            
            # Find the length of the cycle
            cycle_length = 0
            curr = i
            while not visited[curr]:
                visited[curr] = True
                curr = elements[curr][2]
                cycle_length += 1
            
            if cycle_length > 1:
                swaps += cycle_length - 1
                
        return swaps