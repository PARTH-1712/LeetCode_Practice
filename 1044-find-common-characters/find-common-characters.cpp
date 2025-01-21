class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       vector<string>result;
       vector<int>count(26,0);
       string first=words[0];
       for(int i=0;i<first.length();i++)
       {
         count[first[i]-'a']++;
       }
       for(int i=1;i<words.size();i++)
       {
          vector<int>temp(26,0);
          string word=words[i];
          for(int j=0;j<word.length();j++)
          {
              temp[word[j]-'a']++;
          }
          for(int k=0;k<count.size();k++)
          {
             count[k]=min(count[k],temp[k]);
          }
       }
       for(int i=0;i<26;i++)
       {
          while(count[i]!=0)
          {
            result.push_back(string(1, 'a' + i));
            count[i]--;
          }
       }
       return result;
        
    }
};