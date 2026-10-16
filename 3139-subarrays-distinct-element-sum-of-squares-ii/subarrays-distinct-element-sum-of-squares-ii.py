class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        
        # Two Fenwick trees (1-indexed) for Range Add & Range Sum
        bit1 = [0] * (n + 2)
        bit2 = [0] * (n + 2)
        
        def add(bit: list[int], idx: int, val: int):
            while idx <= n:
                bit[idx] += val
                idx += idx & (-idx)
                
        def range_add(l: int, r: int, val: int):
            add(bit1, l, val)
            add(bit1, r + 1, -val)
            add(bit2, l, val * (l - 1))
            add(bit2, r + 1, -val * r)
            
        def prefix_sum(idx: int) -> int:
            s1, s2 = 0, 0
            curr = idx
            while curr > 0:
                s1 += bit1[curr]
                s2 += bit2[curr]
                curr -= curr & (-curr)
            return s1 * idx - s2
            
        def range_sum(l: int, r: int) -> int:
            return prefix_sum(r) - prefix_sum(l - 1)

        last_seen = {}
        cur_sq_sum = 0
        total_ans = 0
        
        for r, x in enumerate(nums, 1):  # 1-indexed
            prev = last_seen.get(x, 0)
            
            # Query sum of f(l, r-1) for l in [prev + 1, r]
            current_range_sum = range_sum(prev + 1, r)
            
            # Update running sum of squares for the current right endpoint r
            cur_sq_sum = (cur_sq_sum + 2 * current_range_sum + (r - prev)) % MOD
            total_ans = (total_ans + cur_sq_sum) % MOD
            
            # Increment f(l, r) by 1 for l in [prev + 1, r]
            range_add(prev + 1, r, 1)
            last_seen[x] = r
            
        return total_ans