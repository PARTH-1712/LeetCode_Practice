class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(i!=j&&words[i].size()<=words[j].size()){
                    string st1=words[j].substr(0, words[i].size());
                    string st2=words[j].substr(words[j].size()-words[i].size(), words[i].size());
                    if(st1==words[i]&&st2==words[i]){
                        cnt++;
                        // cout<<i<<endl;
                        // cout<<words[i]<<" "<<words[j]<<endl;
                    }
                }
            }
        }
        return cnt;
    }
};