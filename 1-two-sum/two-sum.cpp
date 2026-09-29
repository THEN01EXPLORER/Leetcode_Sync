class Solution {
public:
        vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen_numbers;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen_numbers.count(complement)) {
                return {seen_numbers.at(complement), i};
            }
            seen_numbers[nums[i]] = i;
        }  
        return {};
    }
};