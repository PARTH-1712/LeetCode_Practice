class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> mp;
        for(string& s:strs){
            string temp=s;
            sort(temp.begin(),temp.end());
            if(mp.find(temp)==mp.end()){
                mp[temp]=ans.size();
                ans.push_back({s});
            }
            else{
                ans[mp[temp]].push_back(s);
            }
        }
        return ans;
    }
};