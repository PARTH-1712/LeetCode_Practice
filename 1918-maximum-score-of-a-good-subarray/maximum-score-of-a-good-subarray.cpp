class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k, right = k, n = nums.size();
        int minVal = nums[k], maxVal = nums[k];

        while(left>0 || right<n-1) {
            if(left==0 || left<n-1 && nums[left-1] < nums[right+1]) right++;
            else left--;

            minVal = min({minVal, nums[left], nums[right]});
            maxVal = max(maxVal, minVal*(right-left+1));
        }
        return maxVal;
    }
};