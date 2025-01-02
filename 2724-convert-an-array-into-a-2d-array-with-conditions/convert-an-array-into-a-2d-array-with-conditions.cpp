class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        map<int,bool>vis;
        while(vis.size()<nums.size()){
            map<int,bool>numvis;
            vector<int>temp;
            for(int i=0;i<nums.size();i++){
                if(vis.find(i)==vis.end() and numvis.find(nums[i])==numvis.end()){
                    temp.push_back(nums[i]);
                    vis[i]=true;
                    numvis[nums[i]]=true;
                }
            }
            ans.push_back(temp);
            temp.clear();
            numvis.clear();
        }
        return ans;
    }
};