class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int duplicate = -1;
        int missing = 1; // Start by expecting the number 1
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                duplicate = nums[i]; // Found the duplicate!
            } else if (nums[i + 1] > nums[i] + 1) {
                // If there's a gap bigger than 1 (e.g., jumping from 1 to 3)
                missing = nums[i] + 1; // The number in the gap is missing
            }
        }
        
        // Edge Case: If the missing number is the very last number (e.g., [1, 2, 2] -> missing 3)
        if (nums.back() != nums.size()) {
            missing = nums.size();
        }

        return {duplicate, missing};
    }
};
