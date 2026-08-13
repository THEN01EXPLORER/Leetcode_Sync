class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int current_sum = 0;
        int maxSum = nums[0];
        for(int num:nums){
            if(current_sum < 0){
                current_sum = 0;
            }
            current_sum += num ;
            if (current_sum > maxSum){
                maxSum = current_sum;
            }
        }

     return maxSum; 
    }
    
};