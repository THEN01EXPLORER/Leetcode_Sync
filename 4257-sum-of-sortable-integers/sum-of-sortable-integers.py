from typing import List

class Solution:
    def sortableIntegers(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0

        for k in range(1, n + 1):
            if n % k != 0:
                continue

            sortable = True
            prev_max = float('-inf')

            for start in range(0, n, k):
                descents = 0
                drop_idx = -1

                # Check cyclic descents and locate the split point
                for i in range(k):
                    if nums[start + i] > nums[start + (i + 1) % k]:
                        descents += 1
                        drop_idx = i

                # A block cannot be cyclically sorted if it has > 1 descent
                if descents > 1:
                    sortable = False
                    break

                # Determine the min and max of the block once rotated to sorted order
                if descents == 0:
                    # All elements in the block are equal (or k == 1)
                    block_min = nums[start]
                    block_max = nums[start]
                else:
                    # The unique sorted rotation starts at (drop_idx + 1) % k and ends at drop_idx
                    block_min = nums[start + (drop_idx + 1) % k]
                    block_max = nums[start + drop_idx]

                # Ensure cross-block ordering: previous block's max <= current block's min
                if block_min < prev_max:
                    sortable = False
                    break

                prev_max = block_max

            if sortable:
                ans += k

        return ans