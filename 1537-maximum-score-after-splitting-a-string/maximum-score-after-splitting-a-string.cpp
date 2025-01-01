class Solution {
public:
    int maxScore(string s) {
        int one=0;
        int zero=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')one++;
        }
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='1')one--;
            else zero++;
            ans=max(ans,(zero+one));
        }
        return ans;
    }
};