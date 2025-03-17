#define ll long long
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ll n = nums.size();

        ll cnt = 0;

        ll l = 0;
        ll r = 0;

        ll prod = 1;

        while(r < n){
            prod *= nums[r];
            while(l <= r && prod >= k){
                prod /= nums[l];
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return (int)cnt;
    }
};