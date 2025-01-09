class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c=0;
        int n=pref.size();
        for(int i=0;i<words.size();i++){
            string a=words[i].substr(0,n);
            if(a==pref) c++;
        }
        return c;
    }
};