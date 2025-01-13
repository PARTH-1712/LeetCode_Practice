class Solution {
public:
    int minimumLength(string s) {
        map<char,int> map;
        int count=0;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        for(auto it:map){
            if(it.second>2 && it.second%2==0){
               count+=2;
            }
            else if(it.second>2 && it.second%2!=0){
                count+=1;
            }
            else{
                count+=it.second;
            }
        }

        return count;
    }
};