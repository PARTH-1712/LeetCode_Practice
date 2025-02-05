class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if  (s1 == s2) return true;
        if (s1.size() != s2.size())  return false;


        vector<int> vec;
        for(int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) vec.push_back(i);
        }

        if (vec.size() != 2 )  return false;
        swap(s2[vec[0]], s2[vec[1]]);
        if (s2 == s1)  return true;
        return false;
        
    }
};