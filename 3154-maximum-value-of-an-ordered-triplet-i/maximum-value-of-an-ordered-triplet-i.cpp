class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxi = 0;

        for (int j = 1; j < n - 1; ++j) {
            int max_i = INT_MIN;
            for (int i = 0; i < j; ++i) {
                max_i = max(max_i, nums[i] - nums[j]);
            }

            for (int k = j + 1; k < n; ++k) {
                maxi = max(maxi, (long long)max_i * nums[k]);
            }
        }
        
        return maxi;
    }
};