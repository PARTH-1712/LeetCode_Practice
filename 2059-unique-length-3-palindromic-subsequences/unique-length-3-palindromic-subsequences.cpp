class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> indices(26, {-1,-1});

        for(int i=0; i<s.size(); i++) {
            int ind = s[i] - 'a';
            if(indices[ind].first==-1) {
                indices[ind].first = i;
            }
            indices[ind].second = i;
        }

        int res = 0;
        for(int i=0; i<26; i++) {
            int leftIdx = indices[i].first;
            int rightIdx = indices[i].second;

            if(leftIdx==-1) continue;

            unordered_set<char> set;
            for(int mid = leftIdx+1; mid<rightIdx; mid++) {
                set.insert(s[mid]);
            }

            res += set.size();
        }

        return res;
    }
};