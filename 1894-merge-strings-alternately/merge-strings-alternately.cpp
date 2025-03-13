class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int n;
        if(n1 != n2){
            n = min(n1,n2)*2;
        } else {
            n = n1 + n2;
        }
        string result = "";

        for(int i = 0; i < n/2; i++){
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        for(int i = n/2;i < n1;i++){
            result.push_back(word1[i]);
        }
        for(int i = n/2;i < n2;i++){
            result.push_back(word2[i]);
        }
        return result;
    }
};