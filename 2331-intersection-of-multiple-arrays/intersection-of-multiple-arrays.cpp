class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto &i:nums){
            for(int j:i){
                mp[j]++;
            }
        }
        for(auto &i:mp){
            if(i.second == nums.size()){
                ans.push_back(i.first);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};