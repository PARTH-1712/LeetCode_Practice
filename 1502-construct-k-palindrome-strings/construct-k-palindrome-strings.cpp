class Solution {
public:
    bool canConstruct(string s, int k) {
        // if(s.size()==k) return true;
        if(s.size()<k) return false;
        int charcount[26]={0};
        for(const auto&c : s){
            charcount[c-'a']++;
        }
        int count = 0;
        for(int i=0;i<26;i++){
            if(charcount[i]%2!=0)
            count++;
        }
        return count<=k;
    }
};