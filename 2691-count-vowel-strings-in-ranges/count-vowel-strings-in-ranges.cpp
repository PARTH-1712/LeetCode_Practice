class Solution {
    private:
    bool isvowel(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}
public:
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        int n=w.size();
        vector<int> count(n+1,0);
        for(int i=0;i<n;i++)
        {
            char start = w[i][0],end = w[i].back();
           (isvowel(start) && isvowel(end))?count[i+1] = 1 + count[i]:count[i+1] = count[i];
           cout<<count[i]<< start<<end<<endl;
        }
    vector<int> res;
    for(auto Q : q){
        int sum = count[Q[1]+1]-count[Q[0]];
        res.push_back(sum);
    }
        return  res;
    }
};