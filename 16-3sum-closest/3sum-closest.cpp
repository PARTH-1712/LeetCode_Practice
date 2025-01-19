class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0,closest=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(k>j)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>target)
                {
                    closest=min(closest,abs(target-sum));
                    if(closest==abs(target-sum)) ans=sum;
                    k--;
                }
                else if(sum<target) 
                {
                    closest=min(closest,abs(target-sum));
                    if(closest==abs(target-sum)) ans=sum;
                    j++;
                }
                else return target;
            }
        }
        return ans;
    }
};