class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> pre(n,1);
        for(int i=1;i<n;i++){
            if((nums[i-1]+nums[i])%2!=0){
                pre[i]=pre[i-1]+1;
            }
        }
        vector<bool> ans;
        int m=queries.size();
        for(int i=0;i<m;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if((pre[v]-pre[u]+1)==(v-u+1)){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};