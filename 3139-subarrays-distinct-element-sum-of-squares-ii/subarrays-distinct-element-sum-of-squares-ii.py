class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        
        bit1 = [0] * (n + 2)
        bit2 = [0] * (n + 2)
        
        def range_add(l: int, r: int, val: int) -> None:
            idx = l
            v2 = val * (l - 1)
            while idx <= n:
                bit1[idx] += val
                bit2[idx] += v2
                idx += idx & -idx
            idx = r + 1
            v2 = -val * r
            while idx <= n:
                bit1[idx] -= val
                bit2[idx] += v2
                idx += idx & -idx
                
        def prefix_sum(idx: int) -> int:
            s1 = s2 = 0
            curr = idx
            while curr > 0:
                s1 += bit1[curr]
                s2 += bit2[curr]
                curr -= curr & -curr
            return s1 * idx - s2

        last_seen = {}
        cur_sq_sum = 0
        total_ans = 0
        
        for r, x in enumerate(nums, 1):  # 1-indexed
            prev = last_seen.get(x, 0)
            
            range_sum = prefix_sum(r) - prefix_sum(prev)
            cur_sq_sum = (cur_sq_sum + 2 * range_sum + (r - prev)) % MOD
            total_ans = (total_ans + cur_sq_sum) % MOD
            
            range_add(prev + 1, r, 1)
            last_seen[x] = r
            
        return total_ans